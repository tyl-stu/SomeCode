作文以记之 ~ 数组拆分1
=
# 0、前言
本篇博客是一个简单题的题解，题目挺简单，可根据思路的不同编写不同的实现代码！具体代码可 [点击此处](https://leetcode-cn.com/problems/array-partition-i/) 进行查看！相关博客内容可[点击此处](https://blog.csdn.net/m0_51961114/article/details/123949825)进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/713d200c767f4eecb9f5e2eba7292729.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 排序求和
### 2.1.1 思路
题目中要求求解`n`对数中最小值的最大总和，若将整体数组展开就可发现，`n`对数中各队的最小值其实是原数组排序后的下标为偶数的数，然后将他们求和就行！
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	#include<algorithm>
	using namespace std;
	
	void shownums(vector<int>& nums)
	{
		for (int &d : nums)
			cout << d << " ";
		cout << endl;
	}
	
	int arrayPairSum(vector<int>& nums)
	{
		sort(nums.begin(),nums.end());
		int i = 0;
		int ans = 0;
		while (i < nums.size())
		{
			ans += nums[i];
			i += 2;
		}
		return ans;
	}
	
	void test()
	{
		vector<int> nums = { 6, 2, 6, 5, 1, 2 };
		cout << "\n数组："; shownums(nums); cout << endl;
		cout << "最大总和：" << arrayPairSum(nums) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/bd3d0f5fffae4fab805d6c13ee9d805a.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 其他方法
该题是一个简单题，它还有对应的其他解法，等以后再更新吧！
# 3、总结
这个题，因为用的是简单方法求解的，所以就没有特别大的感触，如果说有的话，可能就是以后处理问题时要抓住规律！