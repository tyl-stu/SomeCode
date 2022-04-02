#include<iostream>
#include<vector>
using namespace std;

void shownums(vector<vector<int>>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums[0].size(); j++)
			cout << nums[i][j] << " ";
		cout << "\n";
	}cout << endl;
}

/* 方法1：先用二维数组记下数组中0的位置，然后依此来调整数组 */
//void setzero(vector<vector<int>>& matrix, vector<vector<int>>& ans)
//{
//	int i, j;
//	for (int x = 0; x < ans.size(); x++)
//	{
//		i = ans[x][0]; j = ans[x][1];
//		for (int n = 0; n < matrix.size(); n++)
//			matrix[n][j] = 0;
//		for (int m = 0; m < matrix[0].size(); m++)
//			matrix[i][m] = 0;
//	}
//
//}
//
//void setZeroes(vector<vector<int>>& matrix) 
//{
//	vector<vector<int>> ans;
//	for (int i = 0; i < matrix.size(); i++)
//	{
//		for (int j = 0; j < matrix[0].size(); j++)
//		{
//			if (matrix[i][j] == 0)
//				ans.push_back({ i, j });
//		}
//	}
//	setzero(matrix, ans);
//}

void setZeroes(vector<vector<int>>& matrix) 
{
	
	int row = 0, col = 0;//定义第一行第一列是否有0，有则为1，无则为0
	//先判断第一列是否有0
	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix[i][0] == 0)
		{
			row = 1;
			break;
		}
	}
	//再判断第一行是否有0
	for (int i = 0; i < matrix[0].size(); i++)
	{
		if (matrix[0][i] == 0)
		{
			col = 1;
			break;
		}
	}
	//再进行其他情况，若在非第一行或第一列有0，则将该位置对应的行列首元素置为0
	for (int i = 1; i < matrix.size(); i++)
	{
		for (int j = 1; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	//cout << "\n现数组：\n"; shownums(matrix);
	//开始变0
	for (int i = 1; i < matrix.size(); i++)//根据第一列改行
	{
		if (matrix[i][0] == 0)
		{
			for (int j = 1; j < matrix[0].size(); j++)
				matrix[i][j] = 0;
		}
	}
	//cout << "\n现数组：\n"; shownums(matrix);
	for (int i = 1; i < matrix[0].size(); i++)//根据第一行改列
	{
		if (matrix[0][i] == 0)
		{
			for (int j = 1; j < matrix.size(); j++)
				matrix[j][i] = 0;
		}
	}
	//cout << "\n现数组：\n"; shownums(matrix);
	if (row)
	{
		for (int i = 0; i < matrix.size(); i++)
			matrix[i][0] = 0;
	}
	if (col)
	{
		for (int i = 0; i < matrix[0].size(); i++)
			matrix[0][i] = 0;
	}
	//cout << "\n现数组：\n"; shownums(matrix);
}

void test()
{
	vector<vector<int>> nums = { 
			{ 0,1,2,0 },
			{ 3,4,5,2 },
			{ 1,3,1,5 } };
	cout << "\n原数组：\n"; shownums(nums);
	setZeroes(nums);
	cout << "\n处理后数组：\n"; shownums(nums);
}
 
int main()
{
	test();
	system("pause");
	return 0;
}