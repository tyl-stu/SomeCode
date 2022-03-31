#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

/* https://leetcode-cn.com/problems/two-sum/ */

void showarr(vector<int>& nums)
{
	for (int &i : nums)
		cout << i << " ";
	cout << endl;
}

/* 方法1 利用哈希表 */
//vector<int> twoSum(vector<int>& nums, int target) {
//	unordered_map<int, int> m;
//	for (int i = 0; i<nums.size(); i++)
//	{
//		int tmp = target - nums[i];
//		if (m.find(tmp) != m.end())
//			return { m[tmp], i};
//		m[nums[i]] = i;
//	}
//	return{};
//}

/* 方法2 循环遍历 */
vector<int> twoSum(vector<int>& nums, int target) {
	for (int i = 0; i<nums.size(); i++)
	{
		int tmp = target - nums[i];
		for (int j = i+1; j < nums.size(); j++)
		{
			if (nums[j] == tmp)
				return{ i, j };
		}
	}
	return{};
}

void test()
{
	vector<int> arr = { 1, 9, 9, 8 };
	cout << "\n原数组："; showarr(arr);
	cout << "指定值：" << 10 << endl;
	cout << "处理后："; showarr(twoSum(arr,10)); cout << endl;
	
}

int main()
{
	test();
	system("pause");
	return 0;
}