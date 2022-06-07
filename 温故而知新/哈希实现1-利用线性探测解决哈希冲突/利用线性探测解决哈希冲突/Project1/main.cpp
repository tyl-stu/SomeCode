
/* ģ��ʵ�ֹ�ϣ�ṹ�� */
#include<iostream>
using namespace std;
#include<vector>

enum STATE
{
	EXIST,
	DELETE,
	EMPTY
};

//��ϣ���˴����ļ��й�ϣ��ͻ��ʹ�ô�����������̽�⣬��ɢ��
template <class K,class V>
struct HashNode
{
	pair<K, V> _kv;
	STATE _st = EMPTY;
};

//˳���ʵ�ֹ�ϣ��
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

	// ������ϣ��������
	void Swap(HashTable<K, V>& newHt)
	{
		swap(_hTable, newHt._hTable);
		swap(_size, newHt._size);
	}

	//չʾ��������
	void display()
	{
		cout << "��ǰ��ϣ�������ݣ�" << endl;
		for (int i = 0; i < _hTable.size(); i++)
		{
			cout << "Key:" << _hTable[i]._kv.first << "  Value:" << _hTable[i]._kv.second << endl;
		}
		cout << endl;
	}

	//�������
	void checkCapacity()
	{
		//�������� < 1
		//  ����0.7ʱ��������
		if (_hTable.size() == 0 || _size * 10 / _hTable.size() >= (0.7 * 10))
		{
			//���±�
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
		//0���������
		checkCapacity();

		//1�������ϣλ��
		int idx = kv.first % _hTable.size();

		//2���ж��Ƿ�����ͻ����������������̽�⣡
		while (_hTable[idx]._st != EMPTY)
		{
			//����ǰλ��������Ч����key��ͬ������ʧ��
			if (_hTable[idx]._st == EXIST && kv.first == _hTable[idx]._kv.first)
				return false;
			else if (_hTable[idx]._st == DELETE)
				break;
			//��������
			++idx;
			if (idx == _hTable.size())
				idx = 0;
		}

		//3����������
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
			//��ɾ��
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
	cout << ht.find(17)->_kv.second << endl;//��ʾ����
	ht.erase(17);
	cout << ht.find(17) << endl;
	ht.insert(make_pair(17, 170));
	//ht.display();
	cout << ht.find(17)->_kv.second << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}