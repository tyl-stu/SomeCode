
/* ģ��ʵ�� unordered_map & unordered_set */
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

//��ϣ���˴����ļ��й�ϣ��ͻ��ʹ�ô�����������̽�⣬��ɢ��(������) -- ��ϣͰ
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
template <> // �ػ����������string���ݵ�keyת��Ϊint
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


//��ϣ���ǰ������
template<class K, class V, class KeyofValue, class HashFun = HashFun<K>>
class HTable;

//��ϣ����������Զ�������
//ͨ����װ������Ľڵ�ʵ��
template<class K, class V, class KeyofValue, class HashFun = HashFun<K>>
struct HashIterator
{
	typedef HashIterator<K, V, KeyofValue, HashFun> Self;
	typedef HTable<K, V, KeyofValue, HashFun> HT;

	//��Ա���ڵ�ָ�룬��ϣ��ָ��
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
			//������һ���ǿ������ͷ�ڵ�
			//���㵱ǰ�ڵ��ڹ�ϣ���еĵ�ַ
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
			//û����Ч�ڵ�
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

	//�ѵ���������Ϊ��Ԫ�� --> ���HashIterator�Ϳɷ���HTable��˽�г�Ա
	template<class K, class V, class KeyofValue, class HashFun>
	friend struct HashIterator;

	HTable(int n = 10)
		:_ht(n)
		, _size(0)
	{}

	iterator begin()
	{
		//���ص�һ���ǿ������ͷ�ڵ�
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
		//����һ���յĵ�����λ��
		return iterator(nullptr, this);
	}

	//���� ���������� ʵ�ֶ�ϵͳ�����ݣ�
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

			//�����µ�ָ������
			vector<Node*> newHt(newC);
			cout << newHt.size() << endl;

			KeyofValue kov;
			HashFun hfun;
			//�����ɱ�
			for (int i = 0; i < _ht.size(); ++i)
			{
				Node* cur = _ht[i];
				while (cur)
				{
					Node* next = cur->_next;
					//�����µ�λ��
					int idx = hfun(kov(cur->_val)) % newHt.size();
					//ͷ��
					cur->_next = newHt[idx];
					newHt[idx] = cur;

					cur = next;
				}
				//�ɱ�ָ���ÿ�
				_ht[i] = nullptr;
			}
			//�±���ɱ���
			swap(_ht, newHt);
			//swap(_size, newHt);
		}
	}

	pair<iterator, bool> insert(const V& val)
	{
		//0���������
		checkCapacity();

		//1������hashλ��
		KeyofValue kov;
		HashFun hfun;
		int idx = hfun(kov(val)) % _ht.size();

		//2������
		Node* cur = _ht[idx];
		while (cur)
		{
			if (kov(cur->_val) == kov(val))
				return make_pair(iterator(cur, this), false);
			cur = cur->_next;
		}

		//3�����룺ͷ��
		cur = new Node(val);
		cur->_next = _ht[idx];
		_ht[idx] = cur;
		++_size;
		return make_pair(iterator(cur, this), true);
	}

private:
	//ָ������
	vector<Node*> _ht;
	int _size;
};

/************* ģ��ʵ�� map  *************/
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
		//iterator ָ����������Ԫ���������е�λ��
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

/************* ģ��ʵ�� set  *************/
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
	//�� HTable<K, pair<K, V>, MapKeyOfValue> �п��Բ��ø����ĸ����ͣ���Ϊ���潫������Ϊȱʡ������
	//��Ȼ��ֱ��дΪ HTable<K, K, SetKeyOfValue,HashFun> -- ���ȱʡ�Ĺ���һ��
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
	//�� HTable<K, pair<K, V>, MapKeyOfValue> �п��Բ��ø����ĸ����ͣ���Ϊ���潫������Ϊȱʡ������
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