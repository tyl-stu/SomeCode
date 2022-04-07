作文以记之 ~ 杨辉三角
=
# 0、前言
本篇博客利用C++实现了杨辉三角的生成，这个也是力扣上的一道题，具体题目内容可 [点击此处](https://leetcode-cn.com/problems/pascals-triangle/submissions/) 进行查看！具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123962284) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/6b31f9042d8a482e9625ea0ef7171926.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 利用嵌套循环
### 2.1.1 思路
此思路主要是根据杨辉三角的生成规律，通过基于设定好的第一行和第二行的值去逐层生成其他数。此种规律可总结为：

当设定好第一行以及每一行的首尾两数后，则下一行或者本行的数据（不包括第一行和第二行）可以表示为 `ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];` -- 其中`i`为行数，`j`为第几个数。

具体可根据下述代码进行分析！
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	
	void shownums(vector<vector<int>>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums[i].size(); j++)
			{
				cout << nums[i][j] << " ";
			}cout << endl;
		}cout << endl;
	}
	
	//写法一
	vector<vector<int>> generate(int numRows) 
	{
		vector<vector<int>> ans;
		for (int i = 0; i < numRows; ++i)  
			ans.push_back(vector<int>(i+1,0));
		ans[0][0] = 1;
		for (int i = 1; i < numRows; i++)
		{
			ans[i][0] = 1; ans[i][i] = 1;
			for (int j = 1; j < i; j++)
			{
				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
		}
		return ans;
	}
	
	//写法二
	//vector<vector<int>> generate(int numRows) 
	//{
	//	vector<vector<int>> ans(numRows);
	//	for (size_t i = 0; i < numRows; i++)
	//	{
	//		ans[i].resize(i + 1, 0);
	//		ans[i][0] = 1;
	//		ans[i][i] = 1;
	//	}
	//	for (size_t i = 0; i < ans.size(); i++)
	//	{
	//		for (size_t j = 0; j < ans[i].size(); j++)
	//		{
	//			if (ans[i][j] == 0)
	//			{
	//				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
	//			}
	//		}
	//	}
	//	return ans;
	//}
	
	void test()
	{
		int n = 5;
		cout << "\n生成的杨辉三角：\n";
		shownums(generate(n));
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

**注**：上述代码中提供了**两种写法**，这两种的主要区别在于生成目标数组`ans`时的方法不一样，一个是一开始就设定好了数组每行的个数，一个是分别设定的~
### 2.1.3 运行结果
程序中所给杨辉三角的行数为 `5`，其生成的杨辉三角如下图：
![在这里插入图片描述](https://img-blog.csdnimg.cn/195bd6f501bb4a079cfe4e001eaca25a.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 其他方法
生成杨辉三角还有其他的方法，比如利用数学方法，此方法具体内容可 [点击此处](https://leetcode-cn.com/problems/pascals-triangle/solution/yang-hui-san-jiao-by-leetcode-solution-lew9/) 进行查看！后续有时间再对其进行补充！
# 3、总结
整篇内容就是说明了如何利用程序生成杨辉三角，没有特别需要注意的知识点！