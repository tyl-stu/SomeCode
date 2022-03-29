#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void display(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	cout << endl;
}

void rotate(vector<int>& nums, int k) {
	/* ����1 -- ��ʱ */
	//while (k--)
	//{
	//	nums.insert(nums.begin(), nums[nums.size() - 1]);
	//	//nums.erase(nums.end());
	//	nums.pop_back();
	//	cout << "�����飺";
	//	display(nums);
	//}

	/* ����2  -- ��ʱ */
	/*int tmp;
	int n = nums.size() - 1;
	while (k--)
	{
	tmp = nums[n];
	while (n > 0)
	{
	nums[n] = nums[n - 1];
	n--;
	}
	nums[0] = tmp;
	n = nums.size() - 1;
	cout << "�����飺";
	display(nums);
	}*/

	/* ������ -- ���µ�������в��� */
	vector<int> newArr(nums.size());
	for (int i = 0; i < nums.size(); i++)
	{
	newArr[(i + k) % nums.size()] = nums[i];
	}
	nums.assign(newArr.begin(), newArr.end());
	cout << "\n�����飺";
	display(nums);
	cout << "\n";
}

void test()
{
	// ��������
	vector<int> nums;
	for (int i = 1; i < 8; i++)
		nums.push_back(i);
	cout << "\nԭ���飺";
	display(nums);

	rotate(nums, 3);
}

int main()
{
	test();
	system("pause");
	return 0;
}