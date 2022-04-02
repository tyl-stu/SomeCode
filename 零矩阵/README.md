@[TOC](作文以记之 ~ 零矩阵)
# 0、前言
本篇博客依然是一题解，具体题目请 [点击此处](https://leetcode-cn.com/problems/zero-matrix-lcci/submissions/) 进行查看！相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123917582) 进行查看！

题目不难，而且解法也多，写这篇的目的在于记录作者所使用的两个方法！

# 1、问题描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/cfdf859cf8714b4b9f98c0afbdb4dcc6.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 利用二维数组记录0的位置
### 2.1.1 思路
此方法即是遍历目标数组，然后将数组中0的位置记录到指定二维数组中，然后基于此二维数组进行原数组中元素的转化！
### 2.1.2 程序代码


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
	void setzero(vector<vector<int>>& matrix, vector<vector<int>>& ans)
	{
		int i, j;
		for (int x = 0; x < ans.size(); x++)
		{
			i = ans[x][0]; j = ans[x][1];
			for (int n = 0; n < matrix.size(); n++)
				matrix[n][j] = 0;
			for (int m = 0; m < matrix[0].size(); m++)
				matrix[i][m] = 0;
		}
	
	}
	
	void setZeroes(vector<vector<int>>& matrix) 
	{
		vector<vector<int>> ans;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (matrix[i][j] == 0)
					ans.push_back({ i, j });
			}
		}
		setzero(matrix, ans);
	}
	
	void test()
	{
		vector<vector<int>> nums = { 
				{ 0,1,2,0 },
				{ 3,4,5,2 },
				{ 1,3,1,5 } };
		cout << "\n原数组：\n"; shownums(nums);
		setZeroes(nums);
		cout << "\n原数组：\n"; shownums(nums);
	}
	 
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/a6734efc0e0e415799255d0774e78c08.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 方法2 ~ 利用循环遍历
### 2.2.1 思路
此方法的思路主要是 先遍历目标数组的第一行和第一列，若其中有0，则将两个变量设为1，此两个变量用于最后处理第一行和第一列的条件。之后判断其他数组元素的情况，若其他元素为0，则将该元素对应的第一行和第一列的值置为0。最后先根据第一行和第一列的0值去将对应行列的元素置为0，再根据一开始的两个变量对第一行和第一列进行操作！
### 2.2.2 程序代码


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

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/9a75ca1637cd42cbbe2d4b99d629e229.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
本题不难，只不过还是写了一篇博客纪念一下，上述两种方法有简单易上手的，也有需要多重遍历的，只不过上述代码写的有点冗杂，但暂时不想优化
，加油吧！