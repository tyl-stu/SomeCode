#include<iostream>
using namespace std;

/* 单链表：*/
//struct MyLinkedListNode{
//public:
//	int _val;
//	struct MyLinkedListNode* _next;
//	MyLinkedListNode() :_val(0), _next(nullptr){}
//	MyLinkedListNode(int val) :_val(val), _next(nullptr){}
//	MyLinkedListNode(int val, MyLinkedListNode* next) :_val(val), _next(next){}
//};
//
//class MyLinkedList {
//public:
//	MyLinkedList():size(0),head(nullptr) {}
//
//	int get(int index) {
//		if (index < 0 || index > (size-1))
//			return -1;
//		MyLinkedListNode* next = head;
//		while (index)
//		{
//			next = next->_next;
//			index--;
//		}
//		return next->_val;
//	}
//
//	void addAtHead(int val) {
//		MyLinkedListNode* cur = new MyLinkedListNode(val);
//		cur->_next = head;
//		head = cur;
//		size++;
//	}
//
//	void addAtTail(int val) {
//		if (size == 0) addAtHead(val);
//		else{
//			MyLinkedListNode* next = head;
//			while (next->_next) next = next->_next;
//			MyLinkedListNode* cur = new MyLinkedListNode(val);
//			next->_next = cur;
//			size++;
//		}
//	}
//
//	void addAtIndex(int index, int val) {
//		if (index <= 0) addAtHead(val);
//		else if (index == size) addAtTail(val);
//		else if (index > (size-1)) return;
//		else
//		{
//			MyLinkedListNode* next = head;
//			MyLinkedListNode* prev = nullptr;
//			while (index)
//			{
//				prev = next;
//				next = next->_next;
//				index--;
//			}
//			MyLinkedListNode* cur = new MyLinkedListNode(val);
//			cur->_next = next;
//			prev->_next = cur;
//			size++;
//		}
//	}
//
//	void deleteAtIndex(int index) {
//		if (index<size && index >= 0)
//		{
//			MyLinkedListNode* next = head;
//			MyLinkedListNode* prev = nullptr;
//			while (index)
//			{
//				prev = next;
//				next = next->_next;
//				--index;
//			}
//			prev->_next = next->_next;
//			delete next;
//			size--;
//		}
//		else if (index == 0)
//		{
//			MyLinkedListNode* next = head->_next;
//			head = next;
//			size--;
//		}
//	}
//
//	void display()
//	{
//		MyLinkedListNode* next = head;
//		while (next)
//		{
//			cout << next->_val << " ";
//			next = next->_next;
//		}
//		cout << endl;
//	}
//
//private:
//	struct MyLinkedListNode* head;
//	int size;
//};


/*双向链表*/
struct MyListNode{
public:
	int _val;
	struct MyListNode* _prev;
	struct MyListNode* _next;
	MyListNode() :_val(0), _prev(nullptr), _next(nullptr){}
	MyListNode(int val) :_val(val), _prev(nullptr), _next(nullptr){}
	MyListNode(int val, struct MyListNode* prev, struct MyListNode* next) :_val(val), _prev(prev), _next(next){}
};
class MyLinkedList {
public:
	MyLinkedList() :size(0), head(nullptr) {

	}

	int get(int index) {
		if (index >= 0 && index < size)
		{
			MyListNode* next = head;
			while (index)
			{
				next = next->_next;
				index--;
			}
			return next->_val;
		}
		else
			return -1;
	}

	void addAtHead(int val) {
		if (size == 0)
			head = new MyListNode(val);
		else
		{
			MyListNode* cur = new MyListNode(val);
			cur->_next = head;
			head->_prev = cur;
			head = cur;
		}
		size++;
	}

	void addAtTail(int val) {
		if (size == 0)
			addAtHead(val);
		else{
			MyListNode* next = head;
			while (next->_next != nullptr)
			{
				next = next->_next;
			}
			MyListNode* cur = new MyListNode(val);
			next->_next = cur;
			cur->_prev = next;
			size++;
		}
	}

	void addAtIndex(int index, int val) {
		if (index <= 0) addAtHead(val);
		else if (index == size) addAtTail(val);
		else if (index > size) return;
		else{
			MyListNode* next = head;
			while (index)
			{
				next = next->_next;
				index--;
			}
			MyListNode* prev = next->_prev;
			MyListNode* cur = new MyListNode(val);
			prev->_next = cur;
			cur->_prev = prev;
			cur->_next = next;
			next->_prev = cur;
			
			size++;
		}
	}

	void deleteAtIndex(int index) {
		if (index > 0 && index < size)
		{
			MyListNode* tmp = head;
			while (index)
			{
				tmp = tmp->_next;
				index--;
			}
			MyListNode* prev = tmp->_prev;
			MyListNode* next = tmp->_next;
			prev->_next = next;
			if (next != nullptr)
				next->_prev = prev;
			delete tmp;
			size--;
		}
		else if (index == 0)
		{
			MyListNode* next = head;
			head = head->_next;
			delete next;
			size--;
		}
	}

	void display()
	{
		MyListNode* next = head;
		while (next)
		{
			cout << next->_val << " ";
			next = next->_next;
		}
		cout << endl;
	}
private:
	int size;
	struct MyListNode* head;
};

/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList* obj = new MyLinkedList();
* int param_1 = obj->get(index);
* obj->addAtHead(val);
* obj->addAtTail(val);
* obj->addAtIndex(index,val);
* obj->deleteAtIndex(index);
*/

void test()
{
	MyLinkedList linkedList = MyLinkedList(); linkedList.display();
	linkedList.addAtHead(2);
	linkedList.display();

	linkedList.deleteAtIndex(1);
	linkedList.display();

	linkedList.addAtHead(2);
	linkedList.display();

	linkedList.addAtHead(7);
	linkedList.display();

	linkedList.addAtHead(3);
	linkedList.display();

	linkedList.addAtHead(2);
	linkedList.display();

	linkedList.addAtHead(5);
	linkedList.display();

	linkedList.addAtTail(5);
	linkedList.display();

	cout << linkedList.get(5) << endl;

	linkedList.deleteAtIndex(6);
	linkedList.display();

	linkedList.deleteAtIndex(4);
	linkedList.display();

	//cout << linkedList.get(0) << endl;

	//linkedList.addAtHead(5);
	//linkedList.display();

	//linkedList.addAtIndex(1, 2);
	//linkedList.display();

	//cout << linkedList.get(1) << endl;

	//linkedList.addAtHead(6);
	//linkedList.display();

	/*linkedList.addAtTail(3);
	linkedList.display();
	linkedList.addAtIndex(1, 2);
	linkedList.display();

	cout << linkedList.get(1) << endl;
	linkedList.deleteAtIndex(1);
	linkedList.display();
	cout << linkedList.get(1) << endl;
*/
	//linkedList.addAtTail(1);
	////linkedList.display();

	//cout << linkedList.get(5) << endl;

	//linkedList.addAtHead(2);
	////linkedList.display();

	//cout << linkedList.get(2) << endl;

	//linkedList.addAtHead(6);
	////linkedList.display();

	
}

int main()
{
	test();
	system("pause");
	return 0;
}