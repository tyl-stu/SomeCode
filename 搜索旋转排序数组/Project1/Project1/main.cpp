#include<iostream>
#include<vector>

using namespace std;

void shownums(vector<int>& nums)
{
	for (int& d : nums)
		cout << d << " ";
	cout << endl;
}

int search(vector<int>& nums, int target)
{
	int n = nums.size();
	if (n == 0) return -1;
	if (n == 1) return nums[0] == target ? 0 : -1;
	int start = 0, end = n - 1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (nums[mid] == target) return mid;
		if (nums[0] <= nums[mid])//确定前半部分是否有序 -- 此时为 [0,mid]
		{
			if (nums[0] <= target && target < nums[mid])//确定是否存在于当前有序部分数组中，在则确定该部分的结尾end
				end = mid - 1;
			else//不在则确定下一部分的起始位置
				start = mid + 1;
		}
		else
		{
			if (nums[mid] < target && target <= nums[n - 1])
				start = mid + 1;
			else
				end = mid - 1;
		}
	}
	return -1;
}

void test()
{
	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
	int target = 1;
	cout << "\n原数组为："; shownums(nums); 
	cout << "要查找的值为：" << target << endl; cout << endl;
	cout << "目标数据所在的位置：" << search(nums, target) << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}