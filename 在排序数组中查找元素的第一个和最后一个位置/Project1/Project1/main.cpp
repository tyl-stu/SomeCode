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

vector<int> searchRange(vector<int>& nums, int target) 
{
	int n = nums.size();
	if (n == 0) return{ -1, -1 };
	int start = 0, end = n - 1;
	vector<int> ans;
	while ((start + 1) < end)
	{
		int mid = start + (end - start) / 2;
		if (nums[mid] == target)
		{
			int left = mid, right = mid;
			while (0<=left && nums[left] == target) left--;
			while (right<= n-1 && nums[right] == target) right++;
			ans.push_back(left + 1);
			ans.push_back(right - 1);
			break;
		}
		else if (nums[mid] < target) start = mid;
		else end = mid;
	}
	if (nums[start] == target) ans.push_back(start);
	if (nums[end] == target) ans.push_back(end);
	if (ans.size() == 1) return{ ans[0], ans[0] };
	else if (ans.size() == 0) return { -1, -1 };
	else
	{
		sort(ans.begin(), ans.end());
		return{ ans[0], ans[ans.size() - 1] };
	}
}

void test()
{
	/*vector<int> nums = { 1, 2, 1, 3, 5, 6, 4 };*/
	vector<int> nums = { 0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 5, 5};
	/*vector<int> nums = { 5, 7, 7, 8, 8, 10 };*/
	/*vector<int> nums = { 1};*/
	int target = 5;
	cout << "\n原数组："; shownums(nums); cout << endl;
	vector<int> ans = searchRange(nums,target);
	cout << "数组中" << target << "的起始和终止位置："<< ans[0]<<" " << ans[1] << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}