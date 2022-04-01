#include<iostream>
#include<vector>

using namespace std;

/* 思路一 */
//int pivotIndex(vector<int>& nums) 
//{
//	int sum = 0;
//	for (int &d : nums)
//		sum += d;
//	int sum1 = 0;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		if ((sum - 2 * sum1) == nums[i])
//			return i;
//		sum1 += nums[i];
//	}
//	return - 1;
//}

/* 思路二 */
int pivotIndex(vector<int>& nums)
{
	int sum = 0;
	for (int &d : nums)
		sum += d;
	int sum1 = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		sum1 += nums[i];
		if ((2 * sum1 - sum) == nums[i])
			return i;
	}
	return -1;
}

void test()
{
	vector<int> nums = { -1, -1, -1, -1, -1,0};
	cout << "\n原数组为：";
	for (int &d : nums)
		cout << d << " ";
	cout << endl;
	cout << "中心坐标：" << pivotIndex(nums) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}