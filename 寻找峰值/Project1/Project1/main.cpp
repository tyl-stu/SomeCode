#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

void shownums(vector<int>& nums)
{
	for (int& d : nums)
		cout << d <<" ";
	cout << endl;
}

/* 方法1 ~ 调用API */
//int findPeakElement(vector<int>& nums) {
//	// max_element()返回序列中最大值的地址，减去数组的首地址，可获得最大值的下标！
//	return max_element(nums.begin(), nums.end()) - nums.begin();
//}

/* 方法2 ~ 遍历*/
//int findPeakElement(vector<int>& nums) {
//	int n = nums.size();
//	if (n == 1) return 0;
//	int max = nums[0];
//	for (int i = 1; i < n; i++)
//	{
//		
//		if (max < nums[i])
//			max = nums[i];
//		else
//			return i - 1;
//		if (i == (n - 1)) return i;
//	}
//	return -1;
//}

/* 方法3 ~ 二分法 */
int findPeakElement(vector<int>& nums) {
	int start = 0, end = nums.size() - 1;
	while (start < end)
	{
		int mid = start + (end - start) / 2;
		if (nums[mid] > nums[mid + 1])
			end = mid;
		else
			start = mid + 1;
	}
	return start;
}

void test()
{
	vector<int> nums = { 1, 2, 1, 3, 5, 6, 4 };
	/*vector<int> nums = { 1, 2 };*/
	cout << "\n原数组："; shownums(nums); cout << endl;
	cout << "数组中某一峰值位置：" << findPeakElement(nums) << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}