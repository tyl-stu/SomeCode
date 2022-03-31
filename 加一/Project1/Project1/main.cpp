#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

/* https://leetcode-cn.com/problems/plus-one/solution/ */

void showarr(vector<int>& nums)
{
	for (int &i : nums)
		cout << i << " ";
	cout << endl;
}

/*方法1  -- 调用库函数*/
//vector<int> plusOne(vector<int>& digits) 
//{
//	int end = ++digits[digits.size() - 1];
//	int i = 1;
//	while (1)
//	{
//		if (end / 10 == 1)
//		{
//			digits[digits.size() - i] = 0;
//			if (digits.size()>i)
//				++digits[digits.size() - (i + 1)];
//			else
//				digits.insert(digits.begin(), 1);
//		}
//		else
//			break;
//		end = digits[digits.size() - (i + 1)];
//		i++;
//	}
//	return digits;
//}

/*方法2 -- 分情况实现*/
vector<int> plusOne(vector<int>& digits)
{
	int n = digits.size();
	for (int i = n-1; i >= 0; i--)
	{
		if (digits[i] != 9)
		{
			++digits[i];
			for (int j = i + 1; j < n; j++)
				digits[j] = 0;
			return digits;
		}
	}
	vector<int> ans(n + 1);
	ans[0] = 1;
	return ans;
}

void test()
{
	vector<int> arr = { 1, 9, 9, 8 };
	cout << "\n原数组："; showarr(arr);
	cout << "处理后："; showarr(plusOne(arr)); cout << endl;
	vector<int> arr2 = { 9, 9, 9 };
	cout << "\n原数组："; showarr(arr2);
	cout << "处理后："; showarr(plusOne(arr2)); cout << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}