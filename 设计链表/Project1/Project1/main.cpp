#include<iostream>
using namespace std;

struct MyLinkedListNode{
public:
	int _val;
	struct MyLinkedListNode* _next;
	MyLinkedListNode() :_val(0), _next(nullptr){}
	MyLinkedListNode(int val) :_val(val), _next(nullptr){}
	MyLinkedListNode(int val, MyLinkedListNode* next) :_val(val), _next(next){}
};

class MyLinkedList {
public:
	MyLinkedList():size(0),head(nullptr) {}

	int get(int index) {
		if (index < 0 || index > (size-1))
			return -1;
		MyLinkedListNode* next = head;
		while (index)
		{
			next = next->_next;
			index--;
		}
		return next->_val;
	}

	void addAtHead(int val) {
		MyLinkedListNode* cur = new MyLinkedListNode(val);
		cur->_next = head;
		head = cur;
		size++;
	}

	void addAtTail(int val) {
		if (size == 0) addAtHead(val);
		else{
			MyLinkedListNode* next = head;
			while (next->_next) next = next->_next;
			MyLinkedListNode* cur = new MyLinkedListNode(val);
			next->_next = cur;
			size++;
		}
	}

	void addAtIndex(int index, int val) {
		if (index <= 0) addAtHead(val);
		else if (index == size) addAtTail(val);
		else if (index > (size-1)) return;
		else
		{
			MyLinkedListNode* next = head;
			MyLinkedListNode* prev = nullptr;
			while (index)
			{
				prev = next;
				next = next->_next;
				index--;
			}
			MyLinkedListNode* cur = new MyLinkedListNode(val);
			cur->_next = next;
			prev->_next = cur;
			size++;
		}
	}

	void deleteAtIndex(int index) {
		if (index<size && index >= 0)
		{
			MyLinkedListNode* next = head;
			MyLinkedListNode* prev = nullptr;
			while (index)
			{
				prev = next;
				next = next->_next;
				--index;
			}
			prev->_next = next->_next;
			delete next;
			size--;
		}
		else if (index == 0)
		{
			MyLinkedListNode* next = head->_next;
			head = next;
			size--;
		}
	}

	void display()
	{
		MyLinkedListNode* next = head;
		while (next)
		{
			cout << next->_val << " ";
			next = next->_next;
		}
		cout << endl;
	}

private:
	struct MyLinkedListNode* head;
	int size;
};

void test()
{
	MyLinkedList linkedList = MyLinkedList(); linkedList.display();
	linkedList.addAtHead(4);
	//linkedList.display();

	cout << linkedList.get(0) << endl;

	linkedList.addAtHead(5);
	//linkedList.display();

	linkedList.addAtIndex(1, 2);
	//linkedList.display();

	cout << linkedList.get(1) << endl;

	linkedList.addAtHead(6);
	//linkedList.display();

	linkedList.addAtTail(2);
	//linkedList.display();

	cout << linkedList.get(3) << endl;

	linkedList.addAtTail(1);
	//linkedList.display();

	cout << linkedList.get(5) << endl;

	linkedList.addAtHead(2);
	//linkedList.display();

	cout << linkedList.get(2) << endl;

	linkedList.addAtHead(6);
	//linkedList.display();

	
}

int main()
{
	test();
	system("pause");
	return 0;
}