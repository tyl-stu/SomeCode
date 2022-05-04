#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void showArr(vector<vector<int>>& mat)
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[0].size(); j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/*利用BFS -- 基于1去找0 ，冗杂待优化*/
//class Solution {
//public:
//	int findMin(vector<vector<int>>& mat, int r, int c)
//	{
//		int rowmax = mat.size(), colmax = mat[0].size();
//		queue<pair<int, int>> que;
//		que.push({ r, c });
//		int len = 0;
//		int flag = 0;
//		int size = que.size();
//		while (!que.empty())
//		{
//			size--;
//			auto cur = que.front();
//			que.pop();
//			int row = cur.first, col = cur.second;
//			
//			if ((row + 1) < rowmax && mat[row + 1][col] != 0 && mat[row + 1][col] != INT_MAX) //向下
//			{
//				que.push({ row + 1, col });
//				mat[row + 1][col] = INT_MAX;
//			}
//			else if ((row + 1) < rowmax && mat[row + 1][col] == 0)
//			{
//				len++;
//				flag = 1;
//				break;
//			}
//			if ((row - 1) >= 0 && mat[row - 1][col] != 0 && mat[row - 1][col] != INT_MAX) //向上
//			{
//				que.push({ row - 1, col });
//				mat[row - 1][col] = INT_MAX;
//			}
//			else if ((row - 1) >= 0 && mat[row - 1][col] == 0)
//			{
//				len++;
//				flag = 1;
//				break;
//			}
//			if ((col - 1) >= 0 && mat[row][col - 1] != 0 && mat[row][col - 1] != INT_MAX) //向左
//			{
//				que.push({ row, col - 1 });
//				mat[row][col - 1] = INT_MAX;
//			}
//			else if ((col - 1) >= 0 && mat[row][col - 1] == 0)
//			{
//				len++;
//				flag = 1;
//				break;
//			}
//			if ((col + 1) < colmax && mat[row][col + 1] != 0 && mat[row][col + 1] != INT_MAX) //向右
//			{
//				que.push({ row, col + 1 });
//				mat[row][col + 1] = INT_MAX;
//			}
//			else if ((col + 1) < colmax && mat[row][col + 1] == 0)
//			{
//				len++;
//				flag = 1;
//				break;
//			}
//			if (size == 0)
//			{
//				len++;
//				size = que.size();
//			}
//		}
//		return flag == 0 ? mat[r][c] : len;
//	}
//	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//		int rowmax = mat.size(), colmax = mat[0].size();
//		vector<vector<int>> tmp = mat;
//		vector<vector<int>> ans = mat;
//		for (int i = 0; i < rowmax; i++)
//		{
//			for (int j = 0; j < colmax; j++)
//			{
//				if (ans[i][j] != 0)
//				{
//					ans[i][j] = findMin(tmp, i, j);
//					tmp = mat;
//				}
//			}
//		}
//		return ans;
//	}
//};

///*利用BFS -- 基于0去找1 */
//class Solution {
//public:
//	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
//	{
//		vector<vector<int>> cpy = mat;//mat的备份，有需要操作的地方只需修改cpy，而非mat,防止修改mat原有数据
//		vector<vector<int>> ans = mat;//操作结束后返回的数组
//		int pos[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };//用于寻找当前位置的上下左右位置
//		int rowmax = mat.size(), colmax = mat[0].size();
//
//		// 找出原数组中0的位置，并保存至que
//		queue<pair<int, int>> que;
//		for (int i = 0; i < rowmax; i++)
//		{
//			for (int j = 0; j < colmax; j++)
//			{
//				if (cpy[i][j] == 0)
//					que.push({ i, j });
//			}
//		}
//
//		// 正式操作开始 -- 基于0找1
//		while (!que.empty())
//		{
//			auto cur = que.front();
//			int r = cur.first, c = cur.second;
//			que.pop();
//			for (int i = 0; i < 4; i++)
//			{
//				int row = r + pos[i][0], col = c + pos[i][1];
//				if (row >= 0 && row < rowmax && col >= 0 && col < colmax && cpy[row][col] != 0)
//				{
//					ans[row][col] = ans[r][c] + 1;
//					que.push({ row, col });
//					cpy[row][col] = 0;
//				}
//			}
//		}
//		return ans;
//	}
//};

///*利用DFS -- 基于0去找1 注：只适合部分案例 ！！！！*/
//class Solution {
//public:
//	void dfs(vector<vector<int>>& cpy, vector<vector<int>>& ans, int row, int col,int len)
//	{
//		int rowmax = cpy.size(), colmax = cpy[0].size();
//		if (cpy[row][col] != 0)
//		{
//			ans[row][col] = min(len + 1, ans[row][col]);
//			cpy[row][col] = 0;
//		}
//			if ((row - 1) >= 0 && cpy[row-1][col] != 0) //向上
//				dfs(cpy, ans, row - 1, col, ans[row][col]);
//			if ((row + 1) < rowmax && cpy[row+1][col] != 0) //向下
//				dfs(cpy, ans, row + 1, col, ans[row][col]);
//			if ((col - 1) >= 0 && cpy[row][col-1] != 0) //向左
//				dfs(cpy, ans, row, col - 1, ans[row][col]);
//			if ((col + 1) < colmax && cpy[row][col+1] != 0) //向右
//				dfs(cpy, ans, row, col + 1, ans[row][col]);
//	}
//	vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
//	{
//		int rowmax = mat.size(), colmax = mat[0].size();
//		vector<vector<int>> cpy = mat;//mat的备份，有需要操作的地方只需修改cpy，而非mat,防止修改mat原有数据
//		vector<vector<int>> ans(rowmax,vector<int>(colmax,INT_MAX));//操作结束后返回的数组
//
//		queue<pair<int, int>> que;
//		for (int i = 0; i < rowmax; i++)
//		{
//			for (int j = 0; j < colmax; j++)
//			{
//				if (cpy[i][j] == 0)
//					que.push({ i, j });
//			}
//		}
//
//		// 正式操作开始 -- 基于0找1
//		while (!que.empty())
//		{
//			auto cur = que.front();
//			que.pop();
//			ans[cur.first][cur.second] = 0;
//			cpy = mat;
//			dfs(cpy, ans, cur.first, cur.second, 0);
//		}
//
//		return ans;
//	}
//};

void test()
{
	/*vector<vector<int>> mat = {
			{ 1, 0, 1, 1, 0, 0, 1, 0, 0, 1 },
			{ 0, 1, 1, 0, 1, 0, 1, 0, 1, 1 },
			{ 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
			{ 1, 0, 1, 0, 1, 1, 1, 1, 1, 1 },
			{ 0, 1, 0, 1, 1, 0, 0, 0, 0, 1 },
			{ 0, 0, 1, 0, 1, 1, 1, 0, 1, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 0, 1, 1 },
			{ 1, 0, 0, 0, 1, 1, 1, 1, 0, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 0, 1, 0 },
			{ 1, 1, 1, 1, 0, 1, 0, 0, 1, 1 } };*/
	vector<vector<int>> mat = {
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 0, 0, 0 } };
	/*vector<vector<int>> mat = { { 0, 0, 0 }, { 0, 1, 0 }, { 1, 1, 1 } };*/
	cout << "原数组为：" << endl;
	showArr(mat);

	Solution s;
	showArr(s.updateMatrix(mat));
}

int main()
{
	test();
	system("pause");
	return 0;
}