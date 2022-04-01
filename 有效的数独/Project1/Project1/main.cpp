#include<iostream>
#include<vector>
using namespace std;

void showboard(vector<vector<char>>& board)
{
	cout << "����Ԫ��('.'����û������)��" << endl;
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

/*����1 -- ����2ά����*/
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

/*����2 -- ����λ����*/
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
	// ��������
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
	cout << "\n�жϵ�ǰ�����Ƿ���Ч��" << boolalpha << isValidSudoku(board) << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}