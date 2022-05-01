作文以记之 ~ 岛屿数量
=
# 0、前言
本篇博客是力扣上 [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) 题的一篇题解，写下这篇博客主要是想通过这个题的题解来记录在练习 **广度优先搜索算法(`Breadth-First-Search`,缩写为 `BFS`)** 和 **深度优先搜索算法(`Depth-First-Search`,缩写为 `DFS`)** 两种算法的代码应用！

如果上手此篇博客中的题目有点困难，可点击查看博客 [作文以记之 ~ 图像渲染](https://blog.csdn.net/m0_51961114/article/details/124533815) ，此博客中的题是本篇博客中题的基础，可先练习简单的，再上手这个题！

相关博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124217986) 进行查看！

# 1、简单说明
**广度优先搜索算法**(`BFS`)，是一种 **利用队列** 实现的搜索算法。
 **深度优先搜索算法**(`DFS`),是一种 **利用递归** 实现的搜索算法。

 `BFS` 的重点在于队列,而 `DFS` 的重点在于递归。这是它们的本质区别。
 有个小点是，能用dfs解决的题，一般就不能用bfs解决；能用bfs解决的题，一般就不能用dfs。（相关内容可点击 [dfs bfs算法区别](https://blog.csdn.net/double_app_le/article/details/105374198) 此博客进行查看！）

两种算法的具体说明可点击 图文详解两种算法：[深度优先遍历（DFS）和广度优先遍历（BFS）](https://developer.51cto.com/article/614590.html)  此文章进行查看！
# 2、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/afc959f1e4944adfb8a7b0bd61fb8ae8.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 3、解题思路
## 3.1 方法1 ~ 使用DFS
### 3.1.1 思路
为了求出岛屿的数量，可以扫描整个二维网格。从`（0，0）`位置开始，如果目标位置为 `'1'`，则以其为起始节点开始进行深度优先搜索。在深度优先搜索的过程中，需将每个搜索到的 `'1'` 都会被标记为 `'0'` ，避免出现多次干扰。

最终岛屿的数量就是我们进行深度优先搜索的次数。

### 3.1.2 程序代码


	class Solution {
	public:
	    void dfs(vector<vector<char>>& grid, int row,int col)
	    {
	        int rowmax = grid.size();
	        int colmax = grid[0].size();
	        //将为 '1' 的元素设为 '0'，避免出现干扰
	        grid[row][col] = '0';
	        // 检查根节点或者目标位置的数据周围为 ‘1’ 的位置
	        if((row - 1) >= 0 && grid[row-1][col] == '1') dfs(grid,row-1,col);
	        if((row + 1) < rowmax && grid[row+1][col] == '1') dfs(grid,row+1,col);
	        if((col - 1) >= 0 && grid[row][col-1] == '1') dfs(grid,row,col-1);
	        if((col + 1) < colmax && grid[row][col+1] == '1') dfs(grid,row,col+1);
	    }
	    int numIslands(vector<vector<char>>& grid) {
	        int rowmax = grid.size();
	        if(rowmax <= 0) return 0;
	        int colmax = grid[0].size();
	        int num = 0;
	        for(int row = 0; row < rowmax; row++)
	        {
	            for(int col = 0; col < colmax; col++)
	            {
	                if(grid[row][col] == '1')
	                {
	                    num++;
	                    dfs(grid,row,col);
	                } 
	            }
	        }
	        return num;
	    }
	};


## 3.2 方法2 ~ 利用BFS
### 3.2.1 思路
为了求出岛屿的数量，需扫描整个二维网格。如果一个位置为 `‘1’`，则将其加入队列，开始进行广度优先搜索。在广度优先搜索的过程中，每个搜索到的 `‘1’` 都会被重新标记为 `‘0’`。

期间会进行 **出队入队** 操作，出队是将出队的点作为起始点进行搜索操作，入队是当找到满足要求的点后将其存入队列，方便后续做搜索操作！直到队列为空，搜索结束。

最终岛屿的数量就是进行广度优先搜索的次数。

### 3.2.2 程序代码


	class Solution {
	public:
	    int numIslands(vector<vector<char>>& grid) {
	        int rowmax = grid.size();
	        if(rowmax <= 0) return 0;
	        int colmax = grid[0].size();
	        int num = 0;
	        queue<pair<int,int>> obj;
	
	        for(int r = 0; r < rowmax; r++)
	        {
	            for(int c = 0; c < colmax; c++)
	            {
	                if(grid[r][c] == '1')
	                {
	                    num++;
	                    grid[r][c] = '0';
	                    obj.push({r,c});
	                    while(!obj.empty())
	                    {
	                    	//做出队操作，将出队的点作为起始点进行搜索
	                        auto rc = obj.front();
	                        obj.pop();
	                        int row = rc.first, col = rc.second;
	                        if((row - 1) >= 0 && grid[row-1][col] == '1')
	                        {
	                            grid[row-1][col] = '0';
	                            obj.push({row-1,col});
	                        }
	                        if((row + 1) < rowmax && grid[row+1][col] == '1')
	                        {
	                            grid[row+1][col] = '0';
	                            obj.push({row+1,col});
	                        }
	                        if((col - 1) >= 0 && grid[row][col-1] == '1')
	                        {
	                            grid[row][col-1] = '0';
	                            obj.push({row,col-1});
	                        }
	                        if((col + 1) < colmax && grid[row][col+1] == '1')
	                        {
	                            grid[row][col+1] = '0';
	                            obj.push({row,col+1});
	                        }
	                    }
	                }
	            }
	        }
	        return num;
	    }
	};

*注*：以上内容大多数来自于 [力扣官方题解](https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/) ，有需要者可点击查看！