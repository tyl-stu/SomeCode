作文以记之 ~ 01 矩阵
=
# 0、前言
本篇博客是力扣上 [542. 01 矩阵](https://leetcode-cn.com/problems/01-matrix/) 题的一篇题解，写下这篇博客主要是记载一下自己在写代码处理问题时走过的一些弯路！

相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124576260) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/39afa127a7b54ea88988037c88214a20.png)



# 2、解题思路
## 2.1 方法1 ~ 利用BFS
### 2.1.1 思路
这个题主要是先找出数组中 0 的位置，然后基于其去寻找其他的非0值，以找出每个非0值与0的距离。此题结合队列进行实现就很简单，具体如下。

1. 先将数组中 0 的位置加入队列`que`，以此点为根据点，向周围开始扩散，每扩散一层，若其中有非0值，则将其值改为当前位置与0位置之间的距离！同时将该位置插入`que`中，方便后续迭代操作！


2. 每次迭代都会从`que`中取出队首元素，并在`que`中将其删除，为防止产生误操作，程序一开始需要对原数组内容进行2次备份，其一用于判断以找寻原数组中的非0值的位置，另一个则用于返回修改后的结果。


3. 当遍历到非0值时，用于判断的数组需要将同位置的数据进行修改以防止再次访问，在程序中会将其置为0。整个程序的迭代条件与其他`BFS`例题一致，都是以 **`que`是否为空** 进行判断，如果为空则跳出循环，非空则继续进行操作！


4. 需要注意的是，此程序为防止出现死循环，一定要对上述用于判断的数组中遍历过的非0值进行置0，一定要作此处理！



### 2.1.2 程序代码

	class Solution {
	public:
		vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
		{
			vector<vector<int>> cpy = mat;//mat的备份，有需要操作的地方只需修改cpy，而非mat,防止修改mat原有数据
			vector<vector<int>> ans = mat;//操作结束后返回的数组
			int pos[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };//用于寻找当前位置的上下左右位置
			int rowmax = mat.size(), colmax = mat[0].size();
	
			// 找出原数组中0的位置，并保存至que
			queue<pair<int, int>> que;
			for (int i = 0; i < rowmax; i++)
			{
				for (int j = 0; j < colmax; j++)
				{
					if (cpy[i][j] == 0)
						que.push({ i, j });
				}
			}
	
			// 正式操作开始 -- 基于0找1
			while (!que.empty())
			{
				auto cur = que.front();
				int r = cur.first, c = cur.second;
				que.pop();
				for (int i = 0; i < 4; i++)
				{
					int row = r + pos[i][0], col = c + pos[i][1];
					if (row >= 0 && row < rowmax && col >= 0 && col < colmax && cpy[row][col] != 0)
					{
						ans[row][col] = ans[r][c] + 1;
						que.push({ row, col });
						cpy[row][col] = 0;
					}
				}
			}
			return ans;
		}
	};
	

## 2.2 其他方法
本题还可用其他方法，比如 动态规划、贪心算法等，有机会再写吧！

