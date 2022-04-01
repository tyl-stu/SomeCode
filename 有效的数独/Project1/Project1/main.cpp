#include<iostream>
#include<vector>
using namespace std;

void showboard(vector<vector<char>>& board)
{
	cout << "数独元素('.'代表没填数字)：" << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/*方法1 -- 利用2维数组*/
bool isValidSudoku(vector<vector<char>>& board) {
	int row[9][10] = { 0 };
	int col[9][10] = { 0 };
	int box[9][10] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.') continue;
			int tmp = board[i][j] - '0';
			if ((row[i][tmp]) != 0 || (col[j][tmp]) != 0 || (box[j / 3 + (i / 3) * 3][tmp]) != 0)
				return false;
			row[i][tmp] = 1;
			col[j][tmp] = 1;
			box[j / 3 + (i / 3) * 3][tmp] = 1;
		}
	}
	return true;
}

/*方法2 -- 利用位运算*/
bool isValidSudoku(vector<vector<char>>& board) {
	int row[9] = { 0 };
	int col[9] = { 0 };
	int box[9] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.') continue;
			int tmp = 1 << (board[i][j] - '0');
			if ((row[i] & tmp) != 0 || (col[j] & tmp) != 0 || (box[j / 3 + (i / 3) * 3] & tmp) != 0)
				return false;
			row[i] |= tmp;
			col[j] |= tmp;
			box[j / 3 + (i / 3) * 3] |= tmp;
		}
	}
	return true;
}

void test()
{
	// 定义数独
	vector<vector<char>> board = { 
	{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
	{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
	{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
	{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
	{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
	{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
	{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
	{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
	{ '.', '.', '.', '.', '8', '.', '.', '7', '9' } };

	showboard(board);
	cout << "\n判断当前数独是否有效：" << boolalpha << isValidSudoku(board) << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}