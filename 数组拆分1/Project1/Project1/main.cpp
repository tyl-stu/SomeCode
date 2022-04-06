#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void shownums(vector<int>& nums)
{
	for (int &d : nums)
		cout << d << " ";
	cout << endl;
}

int arrayPairSum(vector<int>& nums)
{
	sort(nums.begin(),nums.end());
	int i = 0;
	int ans = 0;
	while (i < nums.size())
	{
		ans += nums[i];
		i += 2;
	}
	return ans;
}

void test()
{
	vector<int> nums = { 6, 2, 6, 5, 1, 2 };
	cout << "\n数组："; shownums(nums); cout << endl;
	cout << "最大总和：" << arrayPairSum(nums) << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}