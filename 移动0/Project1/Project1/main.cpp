#include<iostream>
#include<vector>

using namespace std;

/* https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode-solution/ */

void showarr(vector<int>& nums)
{
	for (int &i : nums)
		cout << i << " ";
	cout << endl;
}

/*����1*/
//void moveZeroes(vector<int>& nums) {
//	int n1 = nums.size();
//	int i = 0;
//	while ( i<nums.size())
//	{
//		if (nums[i] == 0)
//		{
//			nums.erase(nums.begin() + i);
//			i = -1;
//		}
//		i++;
//	}
//	int n2 = n1 - nums.size();
//	while (n2--)
//	{
//		nums.push_back(0);
//	}
//}

/*����2 �¿�����*/
//void moveZeroes(vector<int>& nums) {
//	int n = nums.size();
//	vector<int> ans(n);
//	int i = 0;
//	for (int &d : nums)
//	{
//		if (d != 0)
//			ans[i++] = d;
//	}
//	nums = ans;
//}

/*����3 ��ָ��*/
//void moveZeroes(vector<int>& nums) {
//	int start = 0;
//	for (int &d:nums)
//	{
//		if (d != 0)
//		{
//			nums[start] = d;
//			start++;
//		}
//	}
//	for (int i = start; i < nums.size(); i++)
//		nums[i] = 0;
//}

/*����4 ˫ָ��*/
void moveZeroes(vector<int>& nums) {
	int start = 0, end = 0;
	while (end<nums.size())
	{
		if (nums[end])
		{
			swap(nums[start], nums[end]);
			start++;
		}
		end++;
	}
}

void test()
{
	vector<int> arr = { 0,0,1,0,2 };
	cout << "\nԭ���飺"; showarr(arr);
	moveZeroes(arr);
	cout << "�����";  showarr(arr); cout << endl;
	
}

int main()
{
	test();
	system("pause");
	return 0;
}