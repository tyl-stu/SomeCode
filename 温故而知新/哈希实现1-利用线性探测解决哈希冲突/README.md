# 哈希结构 ~ 程序实现一 -- 利用线性探测解决哈希冲突

本篇博客将利用 **`C++`** 中的 **类** 对哈希结构的底层进行代码实现！且在本篇程序实现中，将基于`闭散列（开放定址法）`利用线性探测实现对**哈希冲突**的解决！

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/125166576) 进行查看！

代码中涉及了哈希的 **增** （i`nsert`）**删**（`erase`）**查**（`find`）改（没写(～￣▽￣)～），打印等基本操作！并附带了实例以及对应的运行结果！

**具体内容**如下`main.cpp`


	
	/* 模拟实现哈希结构！ */
	#include<iostream>
	using namespace std;
	#include<vector>
	
	enum STATE
	{
		EXIST,
		DELETE,
		EMPTY
	};
	
	//哈希表：此代码文件中哈希冲突所使用处理方法：线性探测，闭散列
	template <class K,class V>
	struct HashNode
	{
		pair<K, V> _kv;
		STATE _st = EMPTY;
	};
	
	//顺序表实现哈希表
	template <class K,class V>
	class HashTable
	{
	public:
		typedef HashNode<K, V> Node;
	
		HashTable(size_t n = 10)
			:_hTable(n)
			, _size(0)
		{
			cout << _hTable.size() << endl;
		}
	
		// 交换哈希表中数据
		void Swap(HashTable<K, V>& newHt)
		{
			swap(_hTable, newHt._hTable);
			swap(_size, newHt._size);
		}
	
		//展示表中数据
		void display()
		{
			cout << "当前哈希表中数据：" << endl;
			for (int i = 0; i < _hTable.size(); i++)
			{
				cout << "Key:" << _hTable[i]._kv.first << "  Value:" << _hTable[i]._kv.second << endl;
			}
			cout << endl;
		}
	
		//检查容量
		void checkCapacity()
		{
			//负载因子 < 1
			//  大于0.7时进行增容
			if (_hTable.size() == 0 || _size * 10 / _hTable.size() >= (0.7 * 10))
			{
				//开新表
				int newC = _hTable.size() == 0 ? 10 : 2 * _hTable.size();
				HashTable<K, V> newHt(newC);
				for (int i = 0; i < _hTable.size(); i++)
				{
					if (_hTable[i]._st == EXIST)
						newHt.insert(_hTable[i]._kv);
				}
				Swap(newHt);
			}
		}
	
		bool insert(const pair<K, V>& kv)
		{
			//0、检查容量
			checkCapacity();
	
			//1、计算哈希位置
			int idx = kv.first % _hTable.size();
	
			//2、判断是否发生冲突，若有则利用线性探测！
			while (_hTable[idx]._st != EMPTY)
			{
				//若当前位置数据有效，且key相同，插入失败
				if (_hTable[idx]._st == EXIST && kv.first == _hTable[idx]._kv.first)
					return false;
				else if (_hTable[idx]._st == DELETE)
					break;
				//继续搜索
				++idx;
				if (idx == _hTable.size())
					idx = 0;
			}
	
			//3、插入数据
			_hTable[idx]._kv = kv;
			_hTable[idx]._st = EXIST;
			++_size;
			return true;
		}
	
		Node* find(const K& key)
		{
			int idx = key % _hTable.size();
			while (_hTable[idx]._st != EMPTY)
			{
				if (_hTable[idx]._st == EXIST && key == _hTable[idx]._kv.first)
					return &_hTable[idx];
				++idx;
				if (idx == _hTable.size())
					idx = 0;
			}
			return nullptr;
		}
	
		bool erase(const K& key)
		{
			Node* node = find(key);
			if (node)
			{
				//假删除
				--_size;
				node->_st = DELETE;
				return true;
			}
			return false;
		}
	
	private:
		vector<Node> _hTable;
		size_t _size;
	};
	
	void test()
	{
		HashTable<int, int> ht;
		ht.insert(make_pair(1, 1));
		ht.insert(make_pair(5, 5));
		ht.insert(make_pair(4, 4));
		ht.insert(make_pair(6, 6));
		ht.insert(make_pair(14, 140));
		for (int i = 15; i < 25; i++)
		{
			ht.insert(make_pair(i, i));
		}
		//ht.display();
		cout << ht.find(37) << endl;
		cout << ht.find(17)->_kv.second << endl;//显示数据
		ht.erase(17);
		cout << ht.find(17) << endl;
		ht.insert(make_pair(17, 170));
		//ht.display();
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}


**运行结果**
![在这里插入图片描述](https://img-blog.csdnimg.cn/82e552ca656f460cb43045c51ca28df5.png)
