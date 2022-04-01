作文以记之 ~ 寻找数组的中心下标
=
# 0、前言
本篇博客是力扣上一题的解题方法，对这个题很有感触，具体就待会下面说！若想上手自己做，可 [点击此处](https://leetcode-cn.com/problems/find-pivot-index/submissions/) 进行求解！相关博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123885796) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/36ba8181785842e3a1500bbf2438423c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
**注**：作者本人觉得这个题有问题，逻辑不严谨，比如说题目描述中给出[1,2,3]的中心下标是-1，主要是因为1+2==3，这里就有问题了，如果是[2,-1,1]呢，这个是不是可以理解为 2+(-1) == 1，即其中心下标是-1，也可以理解为-1+1=0，从而其中心下标为0，也就是有两种答案，控制台运行的结果是0，如图
![在这里插入图片描述](https://img-blog.csdnimg.cn/fb396a5b9a2644dcb594bc0b2ca5060b.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
这些暂不说，不知后面会不会优化这个题！

# 2、解题思路
## 2.1 利用前缀和
### 2.1.1 思路

记数组的全部元素之和为 `total`，当遍历到第 `i` 个元素时，设其左侧元素之和为`sum`，则其右侧元素之和为 `total−nums[i]−sum`。左右侧元素相等即为 `sum=total−nums[i]−sum`，即 `nums[i]=total-2×sum` .如此，对数组作遍历，并以此为条件，实现求解问题代码的编写！

关于利用前缀和还有一个思路，与上面同理，此处将配图说明！
![在这里插入图片描述](https://img-blog.csdnimg.cn/d08e186e9f074eefae76cbd58e4e8d7b.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	
	using namespace std;
	
	/* 思路一 */
	//int pivotIndex(vector<int>& nums) 
	//{
	//	int total = 0;
	//	for (int &d : nums)
	//		total += d;
	//	int sum = 0;
	//	for (int i = 0; i < nums.size(); i++)
	//	{
	//		if ((total- 2 * sum) == nums[i])
	//			return i;
	//		sum += nums[i];
	//	}
	//	return - 1;
	//}
	
	/* 思路二 */
	int pivotIndex(vector<int>& nums)
	{
		int total = 0;
		for (int &d : nums)
			total += d;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			if ((2 * sum - total) == nums[i])
				return i;
		}
		return -1;
	}
	
	void test()
	{
		vector<int> nums = { -1, -1, -1, -1, -1,0};
		cout << "\n原数组为：";
		for (int &d : nums)
			cout << d << " ";
		cout << endl;
		cout << "中心坐标：" << pivotIndex(nums) << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/fb47209087f540ef8aea9f89e68816f3.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 利用双指针
额，这个方法呢是我一开始的想法，做了好久，根据题目所给的示例也改了好多bug，但最后还是没有实现，所以对此题做完之后的感觉就是：我自己就是一个智障！浪费了力气还不讨好！

有用双指针实现的大佬可以分享的话请联系我！

# 3、总结
此次这个题是一个简单题，可我一开始做的时候陷入了自己的思维，钻了牛角尖，浪费了好多时间，害，希望以后自己能少犯一些这样的错误！

