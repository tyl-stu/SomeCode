#include<iostream>
#include<vector>
using namespace std;

void shownums(vector<int>& nums)
{
	for (int &d : nums)
		cout << d << " ";
	cout << endl;
}

/* 都是二分查找，写法不同*/
int BinarySearch(vector<int>& nums, int target)
{
	int n = nums.size();
	int start = 0, end = n - 1, ans = n;
	while (start <= end)
	{
		int mid = (end - start) / 2 + start;
		if (target <= nums[mid])
		{
			ans = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return ans;
}

//int BinarySearch(vector<int>& nums, int target)
//{
//	int n = nums.size();
//	if (n == 0)
//		return 0;
//	int start = 0, end = n - 1;
//	for (; start<(end+1);)
//	{
//		if (target < nums[start + (end - start) / 2] && target > nums[start])
//		{
//			end = start + (end - start) / 2;
//		}
//		else if (target <= nums[start])
//			return start;
//		else if (target >= nums[start + (end - start) / 2] && target <= nums[end])
//		{
//			if ((start + 1) == end)
//				return end;
//			start = start + (end - start) / 2;
//		}
//		else if (target > nums[end])
//			return end + 1;
//	}
//	return end;
//}
int searchInsert(vector<int>& nums, int target) {
	return BinarySearch(nums, target);
}

void test()
{
	vector<int> nums = {1,3,5,6};
	cout << "原数组：";
	shownums(nums); cout << endl;
	int target = 0;
	cout << "目标数据：" << target << endl;
	cout << "位置：" << searchInsert(nums, target) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}