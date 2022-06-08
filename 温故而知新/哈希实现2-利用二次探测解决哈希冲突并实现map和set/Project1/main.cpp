
/* 模拟实现 unordered_map & unordered_set */
#include<iostream>
using namespace std;
#include<vector>
#include<string>

enum STATE
{
	EXIST,
	DELETE,
	EMPTY
};

//哈希表：此代码文件中哈希冲突所使用处理方法：二次探测，开散列(开链法) -- 哈希桶
template <class V>
struct HashNode
{
	V _val;
	HashNode<V>* _next;
	HashNode(const V& val)
		:_val(val)
		, _next(nullptr)
	{}
};

template<class K>
struct HashFun
{
	size_t operator()(const K& key)
	{
		return key;
	}
};
template <> // 特化，将插入的string数据的key转换为int
struct HashFun<string>
{
	size_t operator()(const string& key)
	{
		size_t hash = 0;
		for (const auto& ch : key)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};


//哈希表的前置声明
template<class K, class V, class KeyofValue, class HashFun = HashFun<K>>
class HTable;

//哈希表迭代器：自定义类型
//通过封装单链表的节点实现
template<class K, class V, class KeyofValue, class HashFun = HashFun<K>>
struct HashIterator
{
	typedef HashIterator<K, V, KeyofValue, HashFun> Self;
	typedef HTable<K, V, KeyofValue, HashFun> HT;

	//成员：节点指针，哈希表指针
	typedef HashNode<V> Node;
	HT* _hPtr;
	Node* _node;

	HashIterator(Node* node, HT* hptr)
		:_node(node)
		, _hPtr(hptr)
	{}

	V& operator*()
	{
		return _node->_val;
	}

	V* operator->()
	{
		return &_node->_val;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		if (_node->_next)
			_node = _node->_next;
		else
		{
			//查找下一个非空链表的头节点
			//计算当前节点在哈希表中的地址
			KeyofValue kov;
			HashFun hfun;
			int idx = hfun(kov(_node->_val)) % _hPtr->_ht.size();
			++idx;
			for (; idx < _hPtr->_ht.size(); ++idx)
			{
				if (_hPtr->_ht[idx])
				{
					_node = _hPtr->_ht[idx];
					break;
				}
			}
			//没有有效节点
			if (idx == _hPtr->_ht.size())
			{
				_node = nullptr;
			}
		}
		return *this;
	}
};

template<class K, class V, class KeyofValue, class HashFun = HashFun<K>>
class HTable
{
public:
	typedef HashNode<V> Node;
	typedef HashIterator<K, V, KeyofValue, HashFun> iterator;

	//把迭代器声明为友元类 --> 如此HashIterator就可访问HTable的私有成员
	template<class K, class V, class KeyofValue, class HashFun>
	friend struct HashIterator;

	HTable(int n = 10)
		:_ht(n)
		, _size(0)
	{}

	iterator begin()
	{
		//返回第一个非空链表的头节点
		for (int i = 0; i < _ht.size(); ++i)
		{
			if (_ht[i])
			{
				return iterator(_ht[i], this);
			}
		}
		return iterator(nullptr, this);
	}
	iterator end()
	{
		//返回一个空的迭代器位置
		return iterator(nullptr, this);
	}

	//利用 除留余数法 实现对系统的增容！
	size_t GetNextPrime(size_t prime)
	{
		const int PRIMECOUNT = 28;
		const size_t primeList[PRIMECOUNT] =
		{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
		};
		size_t i = 0;
		for (; i < PRIMECOUNT; ++i)
		{
			if (primeList[i] > primeList[i])
				return primeList[i];
		}
		return primeList[i - 1];
	}

	void checkCapacity()
	{
		if (_size == _ht.size())
		{
			int newC = _size == 0 ? 10 : 2 * _size;
			//size_t newC = GetNextPrime(_ht.size());

			//创建新的指针数组
			vector<Node*> newHt(newC);
			cout << newHt.size() << endl;

			KeyofValue kov;
			HashFun hfun;
			//遍历旧表
			for (int i = 0; i < _ht.size(); ++i)
			{
				Node* cur = _ht[i];
				while (cur)
				{
					Node* next = cur->_next;
					//计算新的位置
					int idx = hfun(kov(cur->_val)) % newHt.size();
					//头插
					cur->_next = newHt[idx];
					newHt[idx] = cur;

					cur = next;
				}
				//旧表指针置空
				_ht[i] = nullptr;
			}
			//新表与旧表交换
			swap(_ht, newHt);
			//swap(_size, newHt);
		}
	}

	pair<iterator, bool> insert(const V& val)
	{
		//0、检查容量
		checkCapacity();

		//1、计算hash位置
		KeyofValue kov;
		HashFun hfun;
		int idx = hfun(kov(val)) % _ht.size();

		//2、查找
		Node* cur = _ht[idx];
		while (cur)
		{
			if (kov(cur->_val) == kov(val))
				return make_pair(iterator(cur, this), false);
			cur = cur->_next;
		}

		//3、插入：头插
		cur = new Node(val);
		cur->_next = _ht[idx];
		_ht[idx] = cur;
		++_size;
		return make_pair(iterator(cur, this), true);
	}

private:
	//指针数组
	vector<Node*> _ht;
	int _size;
};

/************* 模拟实现 map  *************/
template<class K,class V>
class Map
{
	struct MapKeyofValue
	{
		const K& operator()(const pair<K, V>& val)
		{
			return val.first;
		}
	};
public:
	typedef typename HTable<K, pair<K, V>, MapKeyofValue>::iterator iterator;
	V& operator[](const K& key)
	{
		//iterator 指的是所返回元素在链表中的位置
		pair<iterator, bool> ret = _ht.insert(make_pair(key, V()));
		return ret.first->second;
	}

	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}

	pair<iterator, bool> insert(const pair<K, V>& val)
	{
		return _ht.insert(val);
	}

private:
	HTable<K, pair<K, V>, MapKeyofValue> _ht;
};

/************* 模拟实现 set  *************/
template<class K>
class Set
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	//此 HTable<K, pair<K, V>, MapKeyOfValue> 中可以不用给第四个泛型，因为上面将其设置为缺省泛型了
	//当然可直接写为 HTable<K, K, SetKeyOfValue,HashFun> -- 这和缺省的功能一样
	typedef typename HTable<K, K, SetKeyOfValue>::iterator iterator;

	iterator begin()
	{
		return _ht.begin();
	}
	iterator end()
	{
		return _ht.end();
	}

	bool insert(const K& key)
	{
		_ht.insert(key);
		return true;
	}
private:
	//此 HTable<K, pair<K, V>, MapKeyOfValue> 中可以不用给第四个泛型，因为上面将其设置为缺省泛型了
	HTable<K, K, SetKeyOfValue> _ht;
};

void test()
{
	Map<int, int> m;
	m.insert(make_pair(1, 1));
	m[2] = 2;
	m[1] = 100;
	m[50] = 50;
	m[2] = 20;

	Map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << " --> " << it->second << " ";
		++it;
	}cout << endl;

	for (auto& e : m)
	{
		cout << e.first << " --> " << e.second << " ";
	}cout << endl;

	/*Set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(11);
	s.insert(22);
	s.insert(33);
	s.insert(44);
	s.insert(31);
	s.insert(41);
	s.insert(24);
	s.insert(8);

	Set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}cout << endl;*/
}

int main()
{
	test();
	system("pause");
	return 0;
}