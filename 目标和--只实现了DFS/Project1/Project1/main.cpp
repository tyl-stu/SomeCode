#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	// DFS 写法1
	/*int findTargetSumWays(vector<int>& nums, int target) {
		return dfs(nums, target, 0);
	}

	int dfs(vector<int> &nums, int target, int left) {
		if (target == 0 && left == nums.size()) return 1;
		if (left >= nums.size()) return 0;
		int ans = 0;
		ans += dfs(nums, target - nums[left], left + 1);
		ans += dfs(nums, target + nums[left], left + 1);
		return ans;
	}*/

	// DFS 写法2
	int num = 0;
	int findTargetSumWays(vector<int>& nums, int target) {
		getNum(nums, target, 0, 0);
		return num;
	}
	void getNum(vector<int>& nums, int target, int index, int sum)
	{
		if (index == nums.size())
		{
			if (sum == target)
			{
				num++;
			}
		}
		else
		{
			getNum(nums, target, index + 1, sum + nums[index]);
			getNum(nums, target, index + 1, sum - nums[index]);
		}

	}
};

void test()
{
	vector<int> nums = { 1, 1, 1, 1, 1 };
	int target = 3;
	Solution s;
	cout << "达到target的计算方法数：" << s.findTargetSumWays(nums, target) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}