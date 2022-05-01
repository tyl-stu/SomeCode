作文以记之 ~ 图像渲染
=
# 0、前言
本篇博客是力扣上 [733. 图像渲染](https://leetcode-cn.com/problems/flood-fill/) 题的一篇题解，写下这篇博客原因一个是 此题是`BFS` 和  `DFS`两种算法的练习题，一个是因为这个与 [作文以记之 ~ 岛屿数量](https://blog.csdn.net/m0_51961114/article/details/124217986) 中的练习题可以说是一脉相承，或者说一个可以给另一个打基础，详细情况可点击上述链接进行对比分析！


具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124533815) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/62e9d0e3f3ec40a0adbcae46bcf444d1.png)


# 2、解题思路
## 2.1 方法1 ~ 利用BFS
### 2.1.1 思路
这个题主要是要找出整个图像中与起始点位置处像素值相同的位置，然后将其像素值转换为目标像素值即可，此题结合队列进行实现就很简单，具体如下。

1. 先将起始点位置加入队列`que`，以此点为根据点，以此位置的像素值为判断标准，向周围开始搜索，当找到满足条件的位置，先将其值变为目标像素值，并将该位置插入`que`中，方便后续迭代操作！


2. 每次迭代都会从`que`中取出队首元素，并在`que`中将其删除，防止后续产生误操作。同时，迭代条件与其他`BFS`例题一致，都是以 **`que`是否为空** 进行判断，如果为空则跳出循环，非空则继续进行操作！


3. 需要注意的是，程序开始前需判断起始位置的像素值是否与目标像素值一致，一致则直接返回原图像，不同则进行后续操作。此种操作必须在程序中出现，不管是前或后，如果没有会导致后续操作进入死循环！



### 2.1.2 程序代码


	class Solution {
	public:
	    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	        int obj = image[sr][sc];
	        if(obj == newColor) //判断起始点的像素值是否与目标像素值一致，一致则返回原图
	            return image;
	        int rowmax = image.size(),colmax = image[0].size();
	        image[sr][sc] = newColor;
	        queue<pair<int,int>> que;
	        que.push({sr,sc});
	        while(!que.empty())//开始遍历
	        {
	            auto cur = que.front();
	            que.pop();
	            int row = cur.first,col = cur.second;
	            if((row - 1) >= 0 && image[row-1][col] == obj) //向左
	            {
	                que.push({row-1,col});
	                image[row-1][col] = newColor;
	            }
	            if((row + 1) < rowmax && image[row+1][col] == obj) //向右
	            {
	                que.push({row+1,col});
	                image[row+1][col] = newColor;
	            }
	            if((col - 1) >= 0 && image[row][col-1] == obj) //向上
	            {
	                que.push({row,col-1});
	                image[row][col-1] = newColor;
	            }
	            if((col + 1) < colmax && image[row][col+1] == obj) //向下
	            {
	                que.push({row,col+1});
	                image[row][col+1] = newColor;
	            }
	        }
	        return image;
	    }
	};



## 2.2 方法2 ~ 使用DFS
### 2.2.1 思路
与`2.1.1`中的思路大致相似，此处只不过是将迭代转为了递归，同样的解决思路，此处我就不再赘述了，因为我觉得有浪费口水的时间各位大佬应该都就看懂了~

### 2.2.2 程序代码


	class Solution {
	public:
	    void dfs(vector<vector<int>>& image, int row, int col, int obj, int newColor)
	    {
	        int rowmax = image.size(),colmax = image[0].size();
	        image[row][col] = newColor;
	        if((row - 1) >= 0 && image[row-1][col] == obj) //向左
	            dfs(image,row-1,col,obj,newColor);
	        if((row + 1) < rowmax && image[row+1][col] == obj) //向右
	            dfs(image,row+1,col,obj,newColor);
	        if((col - 1) >= 0 && image[row][col-1] == obj) //向上
	            dfs(image,row,col-1,obj,newColor);
	        if((col + 1) < colmax && image[row][col+1] == obj) //向下
	            dfs(image,row,col+1,obj,newColor);
	    }
	    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	        int obj = image[sr][sc];
	        if(obj == newColor) //判断起始点的像素值是否与目标像素值一致，一致则返回原图
	            return image;
	        dfs(image,sr,sc,obj,newColor);
	        return image;
	    }
	};



