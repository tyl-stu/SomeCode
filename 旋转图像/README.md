作文以记之~旋转图像
=
# 0、前言
本篇博客将记录一下作者自己做题时的一些题解或思路，写的不详细。相关题目可 [点击此处](https://leetcode-cn.com/problems/rotate-image/submissions/) 进行查看！对应博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123875778) 进行查看！
# 1、问题描述
该题虽然题目是旋转图像，但实际上是旋转矩阵，即将矩阵旋转90度！
![在这里插入图片描述](https://img-blog.csdnimg.cn/a1989b78cd2c4d0ca39402943627ffb2.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 原地旋转
### 2.1.1 思路
这个题要求不能用另一个数组去进行旋转，所以就需考虑其他方法。方法之一就是通过旋转前后，找出矩阵元素旋转前后的位置规律，然后将其代码化，再确定作用范围进行遍历即可。如图
![在这里插入图片描述](https://img-blog.csdnimg.cn/ca3d5e7a115d458f9181fca5270625c4.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
此种方法官方题解中也有具体说明，有需要者可 [点击此处](https://leetcode-cn.com/problems/rotate-image/solution/xuan-zhuan-tu-xiang-by-leetcode-solution-vu3m/) 进行查看！
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	
	void showmatrix(vector<vector<int>>& matrix)
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		for (int i = 0; i<(n / 2); i++)
		{
			//for(int j = 0;j<(n+1)/2;j++)
			for (int j = i; j<(n - 1 - i); j++)
			{
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - i - 1];
				matrix[j][n - i - 1] = tmp;
			}
		}
	}
	
	void test()
	{
		// 定义数独
		vector<vector<int>> matrix = {
			{5, 1, 9, 11}, 
			{2, 4, 8, 10}, 
			{13, 3, 6, 7}, 
			{15, 14, 12, 16} };
	
		cout << "\n翻转前：" << endl;
		showmatrix(matrix);
		cout << "\n翻转后：" << endl;
		rotate(matrix);
		showmatrix(matrix);
		cout << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/ec516e889ee749cc940460a3535630e9.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 利用翻转
该种方法即先将数组上下翻转，然后将其按照对角线进行翻转，此处暂时不想实现该方法，具体后面有时间就补上！

