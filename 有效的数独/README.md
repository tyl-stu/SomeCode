作文以记之~有效数独
=
# 0、前言
依然是一题解，具体题目可 [点击此处](https://leetcode-cn.com/problems/valid-sudoku/) 进行查看！对应博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123865126) 进行查看！而写这篇博客的目的在于加深自己的代码印象，具体内容如下！
# 1、题目描述
简单说就是判断当前数独中的数据元素是否满足数独的规则，即是不是满足行、列、3*3的九宫格中同一数字不可出现两次。
![在这里插入图片描述](https://img-blog.csdnimg.cn/966ca78b0dde4d1c8b38016b0048b55f.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 利用二维数组
### 2.1.1 思路
![在这里插入图片描述](https://img-blog.csdnimg.cn/8d73ed855a404c18808972230ed2d5d4.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
### 2.1.2 程序代码


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

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/0132fc58558d4f46a519c9e064917991.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 利用位运算
### 2.2.1 思路
相较于上一种方法，此处的方法只不过是将2维数组变为了一维数组，然后在数组的数据中通过左移对应位置来表示数独中对应数据所存在的位置。具体可看下述代码！
### 2.2.2 程序代码

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

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/56c5f94c47864725a799e6f97ed7309e.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
本题中通过两种方法解决问题，我觉得值得在意的就是二维数组与一维数组之间的互通，利用位运算是一个好办法！