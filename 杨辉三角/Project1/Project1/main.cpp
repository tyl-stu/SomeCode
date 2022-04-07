#include<iostream>
#include<vector>
using namespace std;

void shownums(vector<vector<int>>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums[i].size(); j++)
		{
			cout << nums[i][j] << " ";
		}cout << endl;
	}cout << endl;
}

//写法一
vector<vector<int>> generate(int numRows) 
{
	vector<vector<int>> ans;
	for (int i = 0; i < numRows; ++i)  
		ans.push_back(vector<int>(i+1,0));
	ans[0][0] = 1;
	for (int i = 1; i < numRows; i++)
	{
		ans[i][0] = 1; ans[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
	}
	return ans;
}

//写法二
//vector<vector<int>> generate(int numRows) 
//{
//	vector<vector<int>> res(numRows);
//	for (size_t i = 0; i < numRows; i++)
//	{
//		res[i].resize(i + 1, 0);
//		res[i][0] = 1;
//		res[i][i] = 1;
//	}
//	for (size_t i = 0; i < res.size(); i++)
//	{
//		for (size_t j = 0; j < res[i].size(); j++)
//		{
//			if (res[i][j] == 0)
//			{
//				res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
//			}
//		}
//	}
//	return res;
//}

void test()
{
	int n = 5;
	cout << "\n生成的杨辉三角：\n";
	shownums(generate(n));
}

int main()
{
	test();
	system("pause");
	return 0;
}