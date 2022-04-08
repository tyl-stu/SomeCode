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

void showrow(vector<int>& row)
{
	for (int& d : row)
		cout << d << " ";
	cout << endl;
} 

/* 方法1 ~ 通过生成杨辉三角再输出 */
//vector<int> getRow(int rowIndex) 
//{
//	rowIndex++;
//	vector<vector<int>> ans;
//	for (int i = 0; i < rowIndex; ++i)  
//		ans.push_back(vector<int>(i+1,0));
//	ans[0][0] = 1;
//	for (int i = 1; i < rowIndex; i++)
//	{
//		ans[i][0] = 1; ans[i][i] = 1;
//		for (int j = 1; j < i; j++)
//		{
//			ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
//		}
//	}
//	return ans[rowIndex-1];
//}

///* 方法2 ~ 利用数学方法 利用阶乘*/
//int factorial(int x)
//{
//	if (x == 1)
//		return 1;
//	return x*factorial(x - 1);
//}
//vector<int> getRow(int rowIndex)
//{
//	vector<int> ans(rowIndex + 1);
//	ans[0] = 1, ans[rowIndex] = 1;
//	for (int i = 1; i < rowIndex; i++)
//	{
//		ans[i] = 1LL*factorial(rowIndex) / (factorial(i) * factorial(rowIndex - i));
//	}
//	return ans;
//}

/* 方法2 ~ 利用数学方法2*/
vector<int> getRow(int rowIndex)
{
	vector<int> ans(rowIndex + 1);
	ans[0] = 1;
	for (int i = 1; i <= rowIndex; i++)
	{
		ans[i] = 1LL * ans[i - 1] * (rowIndex - i + 1) / i;//1LL,LL其实代表long long，*1LL是为了在计算时，把int类型的变量转化为long long，然后再赋值给long long类型的变量
	}
	return ans;
}

void test()
{
	int n = 5;
	//cout << n << "的阶乘 = " << factorial(n) << endl;
	cout << "输入的行数：" << n << endl;
	cout << "\n生成的杨辉三角：\n";
	showrow(getRow(n)); cout << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}