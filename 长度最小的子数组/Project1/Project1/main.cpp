
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

void showarr(vector<int>& nums)
{
	for (int &i : nums)
		cout << i << " ";
	cout << endl;
}
/* 方法1 ~ 暴力求解 */
//int minSubArrayLen(int target, vector<int>& nums)
//{
//	int n = nums.size();
//	if (n == 0) {
//		return 0;
//	}
//	int ans = INT_MAX;
//	for (int i = 0; i < n; i++) {
//		int sum = 0;
//		for (int j = i; j < n; j++) {
//			sum += nums[j];
//			if (sum >= target) {
//				ans = min(ans, j - i + 1);
//				break;
//			}
//		}
//	}
//	return ans == INT_MAX ? 0 : ans;
//}

/* 方法2 ~ 滑动窗口 */
int minSubArrayLen(int target, vector<int>& nums)
{
	int n = nums.size();
	if (n == 0) {
		return 0;
	}
	int ans = INT_MAX;
	int start = 0, end = 0;
	int sum = 0;
	while (end < n)
	{
		sum += nums[end];
		while (sum >= target)
		{
			ans = min(ans, end - start + 1);
			sum -= nums[start];
			start++;
		}
		end++;
	}
	return ans == INT_MAX ? 0 : ans;
}

void test()
{
	vector<int> arr = { 2, 3, 1, 2, 4, 3 };
	cout << "\n原数组："; showarr(arr);
	int target = 7;
	cout << "指定值：" << target << endl;
	cout << "处理后最小连续子数组的长度：" << minSubArrayLen(target, arr) << endl << endl;

}

int main()
{
	test();
	system("pause");
	return 0;
}