#include<iostream>
#include<vector>
using namespace std;

void test()
{
	vector<int> data = { 1, 2, 3, 4, 3, 2, 1 };
	cout << "\nԭ����Ϊ��";
	for (int &d : data)
		cout << d << " ";
	cout << endl;

	int x = 0;
	for (int &d : data)
		x = x^d;
	cout << "\n�����г���һ�ε�����Ϊ��" << x << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}