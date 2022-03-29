/* 二维数组中查找对应数据 */

#include<iostream>
#include<vector>
using namespace std;

void InsertData(vector<vector<int>> &mat) //插入数据
{
	mat.push_back(vector<int>()); mat[0].push_back(1); mat[0].push_back(5); mat[0].push_back(9); mat[0].push_back(13);
	mat.push_back(vector<int>()); mat[1].push_back(2); mat[1].push_back(6); mat[1].push_back(10); mat[1].push_back(14);
	mat.push_back(vector<int>()); mat[2].push_back(3); mat[2].push_back(7); mat[2].push_back(11); mat[2].push_back(15);
	mat.push_back(vector<int>()); mat[3].push_back(4); mat[3].push_back(8); mat[3].push_back(12); mat[3].push_back(16);
}

void ShowData(vector<vector<int>> &mat) //显示数据
{
	int row = mat.size();
	int col = mat[0].size();
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

bool FindNumber(vector<vector<int>> &mat, int obj)
{
	int n = mat.size() - 1;
	int m = 0;
	while (n >= 0 && m < mat[0].size())
	{
		if (mat[n][m] > obj)
			n--;
		else if (mat[n][m] < obj)
			m++;
		else
			return true;
	}
	return false;
}

void test()
{
	vector<vector<int>> matrix;
	InsertData(matrix);
	std::cout << "原始二维数组：" << std::endl; ShowData(matrix);
	int target = 8;
	std::cout << target << " 是否存在于目标数组：" << std::boolalpha << FindNumber(matrix, target) << std::endl;
	target = 0;
	std::cout << target << " 是否存在于目标数组：" << std::boolalpha << FindNumber(matrix, target) << std::endl;
	std::cout << std::endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}