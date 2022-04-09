#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

void shownums(vector<int>& nums)
{
	for (int& d : nums)
		cout << d << " ";
	cout << endl;
}

/* 方法1 ~ 调用API */
int findMin(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	return nums[0];
}


int findMin(vector<int>& nums)
{
	int start = 0, end = nums.size() - 1;
	while (start < end)
	{
		int mid = start + (end - start) / 2;
		if (nums[mid] < nums[end])//用于确定更小的范围
			end = mid;
		else //可以确定出数组中较小的值的范围
			start = mid + 1;
	}
	return nums[start];
}

void test()
{
	//原数组为：0,1,2,3,4,5,6,7
	vector<int> nums = { 4, 5, 6, 7, 0, 1 };
	cout << "\n需处理的数组："; shownums(nums); cout << endl;
	vector<int> tmp = nums;
	sort(tmp.begin(), tmp.end());
	cout << "\n目标数组的原数组："; shownums(tmp); cout << endl;
	cout << "\n最小值：" << findMin(nums) << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}