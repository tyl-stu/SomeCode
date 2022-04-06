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
vector<int> twoSum(vector<int>& numbers, int target) {
	unordered_map<int, int> m;
	for (int i = 0; i<numbers.size(); i++)
	{
		int tmp = target - numbers[i];
		if (m.find(tmp) != m.end() && m[tmp] != i)
			return { m[tmp]+1, i+1};
		m[numbers[i]] = i;
	}
	return{};
}

/* 方法2 双指针 */
vector<int> twoSum(vector<int>& numbers, int target) {
	int len = numbers.size();
	int start = 0, end = len - 1;
	while (start < end)
	{
		int sum = numbers[start] + numbers[end];
		if (sum == target)
			return{ start + 1, end + 1 };
		else if (sum > target)
			end--;
		else
			start++;
	}
	return{};
}

/* 方法3 二分查找 */
vector<int> twoSum(vector<int>& numbers, int target) {
	for (int i = 0; i < numbers.size(); i++)
	{
		int start = i+1, end = numbers.size() - 1;
		while (start <= end)
		{
			int mid = (end - start) / 2 + start;
			if ((numbers[i] + numbers[mid]) == target)
				return{ i + 1, mid + 1 };
			else if ((numbers[i] + numbers[mid]) < target)//此时i的值不变，变得只能是mid，而他俩的和又小于target，因此需要将mid向右移，即mid++
				start = mid + 1;
			else
				end = mid - 1;
		}
	}
	return{};
}

void test()
{
	vector<int> arr = {0,0,3,4};
	cout << "\n原数组："; showarr(arr);
	int target = 0;
	cout << "指定值：" << target << endl;
	cout << "处理后两个整数的下标："; showarr(twoSum(arr,target)); cout << endl;
	
}

int main()
{
	test();
	system("pause");
	return 0;
}