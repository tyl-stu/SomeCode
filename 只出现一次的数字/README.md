作文以记之 ~ 只出现一次的数字
=
本篇博客就是一题解，而且题目不难，只不过是因为当初做时其中一个解法让人眼前一亮，所以便撰文以记之！题目可 [点击此处](https://leetcode-cn.com/problems/single-number/) 进行查看！相关博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123832690) 进行查看！

正文开始！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/19c3529b9bf340c4bd9b4e5f73c1d589.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
关于此题的解决思路，当初我一开始的想法是直接利用循环遍历进行暴力求解，虽然可以实现，但不建议使用，因为浪费资源较多！

而此处需要说明的一个思路是 **利用位运算** ，即利用位运算中的 **异或**！

易知异或是相异为1、相同为0，即自身与自身相异或为0，而且其满足交换律，具体如下
![在这里插入图片描述](https://img-blog.csdnimg.cn/065d8a7e51cd48bf8e21ec6b83a2d0d5.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 3、程序与结果
## 3.1 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	
	void test()
	{
		vector<int> data = { 1, 2, 3, 4, 3, 2, 1 };
		cout << "\n原数组为：";
		for (int &d : data)
			cout << d << " ";
		cout << endl;
	
		int x = 0;
		for (int &d : data)
			x = x^d;
		cout << "\n数组中出现一次的数字为：" << x << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

## 3.2 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/dbabac9d0b664c74bdf40ea09d4e04f9.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
