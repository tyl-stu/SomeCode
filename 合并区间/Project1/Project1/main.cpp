#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

void shownums(vector<vector<int>>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		int j = 0;
		cout << "[";
		for (; j < nums[0].size()-1; j++)
		{
			cout << nums[i][j] << " ";
		}
		cout << nums[i][j] << "] ";
	}cout << endl;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
	int n = intervals.size();
	if (n <= 1)
		return intervals;
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> ans;
	int start = intervals[0][0], end = intervals[0][1];
	int i;
	for (i = 1; i < intervals.size(); i++)
	{
		if (intervals[i][0] > end)
		{
			ans.push_back({ start, end });
			start = intervals[i][0], end = intervals[i][1];
			
		}
		else if (intervals[i][1] >= end)
		{
			end = intervals[i][1];
		}
	}
	if (i == n)
		ans.push_back({ start, end });
	return ans;
}

void test()
{
	/*vector<vector<int>> nums = { { 1, 3 }, { 2, 4 }, { 3, 6 }, {7,8} };*/
	vector<vector<int>> nums = { { 0, 3 }, { 0, 1 }, { 0, 2 }, { 1, 9 }, { 2, 5 }, { 10, 11 }, { 12, 20 }, { 19, 20 } };
	cout << "原数组：";
	shownums(nums); cout << endl;
	cout << "处理后：";
	shownums(merge(nums)); cout << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}