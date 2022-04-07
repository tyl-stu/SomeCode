作文以记之 ~ 长度最小的子数组
=
# 0、前言
本篇博客是一篇题解，具体题目可 [点击此处](https://leetcode-cn.com/problems/minimum-size-subarray-sum/) 进行查看！相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123958203) 进行查看！

这个题有点难度，当然他还是有简单解法，只不过看到题解中的其他解法就有点让人头大！正文开始

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/5e419fe40dcf4971a6d0b3c180cdd924.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 暴力求解
### 2.1.1 思路
此思路即是通过嵌套循环，从数组第一个元素开始，寻找满足题目要求的连续几个数，然后找出这连续几个数中最小的个数即可！具体可通过与代码进行分析比较！
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	#include<algorithm>
	
	using namespace std;
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	/* 方法1 ~ 暴力求解 */
	int minSubArrayLen(int target, vector<int>& nums)
	{
		int n = nums.size();
		if (n == 0) {
			return 0;
		}
		int ans = INT_MAX;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = i; j < n; j++) {
				sum += nums[j];
				if (sum >= target) {
					ans = min(ans, j - i + 1);
					break;
				}
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}
	
	void test()
	{
		vector<int> arr = { 2, 3, 1, 2, 4, 3 };
		cout << "\n原数组："; showarr(arr);
		int target = 7;
		cout << "指定值：" << target << endl;
		cout << "处理后最小连续子数组的长度：" << minSubArrayLen(target, arr) << endl<<endl;
	
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/8821fe8fa5334723b9979ddff41b83af.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 方法2 ~ 滑动窗口
### 2.2.1 思路
定义两个指针 `start` 和 e`nd` 分别表示子数组（滑动窗口窗口）的开始位置和结束位置，变量 `sum` 存储子数组中的元素和（即从 `nums[start]` 到 `nums[end]` 的元素和）。

每一轮迭代，将 `nums[end]` 加到`sum`，如果`sum≥target`，则更新子数组的最小长度（此时子数组的长度是 `end−start+1`），然后将 `nums[start]` 从 `sum` 中减去并将 `start` 右移，直到 `sum<target`，在此过程中同样更新子数组的最小长度。按照以上顺序进行迭代，直至`end`指向数组末尾！

### 2.2.2 程序代码

	#include<iostream>
	#include<vector>
	#include<algorithm>
	
	using namespace std;
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/* 方法2 ~ 滑动窗口 */
	int minSubArrayLen(int target, vector<int>& nums)
	{
		int n = nums.size();
		if (n == 0) {
			return 0;
		}
		int ans = INT_MAX;
		int start = 0, end = 0;
		int sum = 0;
		while (end < n)
		{
			sum += nums[end];
			while (sum >= target)
			{
				ans = min(ans, end - start + 1);
				sum -= nums[start];
				start++;
			}
			end++;
		}
		return ans == INT_MAX ? 0 : ans;
	}
	
	void test()
	{
		vector<int> arr = { 2, 3, 1, 2, 4, 3 };
		cout << "\n原数组："; showarr(arr);
		int target = 7;
		cout << "指定值：" << target << endl;
		cout << "处理后最小连续子数组的长度：" << minSubArrayLen(target, arr) << endl << endl;
	
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/b88c4bc329714622a236f3fc58b7bbd8.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.3 其他方法
关于该题还有其他方法，比如官网上提供的结合 前缀和 + 二分查找 的方法进行求解。而在这里，等以后有机会有想法了再回来更新！

# 3、总结
博客中的题目难度适中，适合扩展编程思维，特别是结合其他的方法进行求解，会对自身的能力有一定的提升！