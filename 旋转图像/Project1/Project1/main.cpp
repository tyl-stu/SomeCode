#include<iostream>
#include<vector>
using namespace std;

void showmatrix(vector<vector<int>>& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	for (int i = 0; i<(n / 2); i++)
	{
		//for(int j = 0;j<(n+1)/2;j++)
		for (int j = i; j<(n - 1 - i); j++)
		{
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[n - 1 - j][i];
			matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
			matrix[n - 1 - i][n - 1 - j] = matrix[j][n - i - 1];
			matrix[j][n - i - 1] = tmp;
		}
	}
}

void test()
{
	// 定义数独
	vector<vector<int>> matrix = {
		{5, 1, 9, 11}, 
		{2, 4, 8, 10}, 
		{13, 3, 6, 7}, 
		{15, 14, 12, 16} };

	cout << "\n翻转前：" << endl;
	showmatrix(matrix);
	cout << "\n翻转后：" << endl;
	rotate(matrix);
	showmatrix(matrix);
	cout << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}