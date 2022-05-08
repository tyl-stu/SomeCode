#include<iostream>
#include<vector>
using namespace std;

void showArr(vector<int>& nums)
{
	for (int& d : nums)
		cout << d << " ";
	cout << endl;
}

/*方法1 ~ 利用二分法*/
//class Solution {
//public:
//	/*利用二分法*/
//	int findDuplicate(vector<int>& nums) {
//		int start = 1, end = nums.size() - 1;
//		int ans;
//		while (start <= end)
//		{
//			int n = 0;//统计当前数组元素下满足要求的个数
//			int mid = (end - start) / 2 + start;
//			for (int i = 0; i<nums.size(); i++)
//				n += nums[i] <= mid;
//			if (n <= mid)
//				start = mid + 1;
//			else
//			{
//				end = mid - 1;
//				ans = mid;
//			}
//		}
//		return ans;
//	}
//	/*利用普通迭代  -- 这种会超出时间*/
//	//int findDuplicate(vector<int>& nums) {
//	//	int start = 1, end = nums.size() - 1;
//	//	int ans;
//	//	while (start <= end)
//	//	{
//	//		int n = 0;//统计当前数组元素下满足要求的个数
//	//		//int mid = (end - start) / 2 + start;
//	//		for (int i = 0; i<nums.size(); i++)
//	//			n += nums[i] <= start;
//	//		if (n <= start)
//	//			start++;
//	//		else
//	//		{
//	//			ans = start;
//	//			break;
//	//		}
//	//	}
//	//	return ans;
//	//}
//};

/*方法2 ~ 利用快慢指针*/
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0;
		// 先找出环形链表中的任一点
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		slow = 0;
		// 找出环形链表的起始点
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
};

void test()
{
	vector<int> nums = { 1, 3, 4, 2, 2 };
	showArr(nums);
	Solution s;
	cout << "nums 中的重复数为：" << s.findDuplicate(nums) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}
