作文以记之 ~ 寻找峰值
=
# 0、前言
本篇博客是力扣162题的题解，具体题目可 [点击此处](https://leetcode-cn.com/problems/find-peak-element/) 进行查看！相关博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124044289) 进行查看！
题目不难，有点意思，解法挺多，下面提供三种~
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/fe66b0332cb84f96918106410fcf966e.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 调用API
### 2.1.1 思路
`c++`中有一个函数，即`max_element()`，其主要功能是返回序列中最大值的地址，若减去数组的首地址，可获得最大值的下标！因此，解决题目可调用此`API`！
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	#include<algorithm>
	
	void shownums(vector<int>& nums)
	{
		for (int& d : nums)
			cout << d <<" ";
		cout << endl;
	}
	
	/* 方法1 ~ 调用API */
	int findPeakElement(vector<int>& nums) {
		// max_element()返回序列中最大值的地址，减去数组的首地址，可获得最大值的下标！
		return max_element(nums.begin(), nums.end()) - nums.begin();
	}
	
	void test()
	{
		vector<int> nums = { 1, 2, 1, 3, 5, 6, 4 };
		/*vector<int> nums = { 1, 2 };*/
		cout << "\n原数组："; shownums(nums); cout << endl;
		cout << "数组中某一峰值位置：" << findPeakElement(nums) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/236cff06edc64dbea9b18913b511d47e.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 方法2 ~ 利用遍历
### 2.2.1 思路
此种思路即为通过遍历，从头开始，找寻其中一个峰值即可，代码如下
### 2.2.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	#include<algorithm>
	
	void shownums(vector<int>& nums)
	{
		for (int& d : nums)
			cout << d <<" ";
		cout << endl;
	}
	
	/* 方法2 ~ 遍历*/
	int findPeakElement(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) return 0;
		int max = nums[0];
		for (int i = 1; i < n; i++)
		{
			
			if (max < nums[i])
				max = nums[i];
			else
				return i - 1;
			if (i == (n - 1)) return i;//处理边界
		}
		return -1;
	}
	
	void test()
	{
		vector<int> nums = { 1, 2, 1, 3, 5, 6, 4 };
		/*vector<int> nums = { 1, 2 };*/
		cout << "\n原数组："; shownums(nums); cout << endl;
		cout << "数组中某一峰值位置：" << findPeakElement(nums) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/b7aa30ba4ee54f769ba45b3b48e447b2.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.3 方法3 ~ 利用二分法
### 2.3.1 思路
其实本题在力扣中的目标主要是练习二分法，上面的两种方法都是简单易实现的。 利用二分法求解的主要思路是：

因为在题目描述中说明了 `nums[-1] = nums[n] = -∞`，因此可以说明只要数组中存在一个元素比相邻元素大，如此沿着它一定可以找到一个峰值。基于此便可利用二分法找到峰值。

查找时，左指针`start`，右指针`end`，循环条件设置为 `start<end` 即可，然后计算中间位置 `mid`，并比较数组中下标为 `mid` 与 `mid+1` 的值，如果 `nums[mid]` 较大，则左侧存在峰值，`end = mid`；如果 `nums[m + 1]` 较大，则右侧存在峰值，`satrt = mid + 1`。
### 2.3.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	#include<algorithm>
	
	void shownums(vector<int>& nums)
	{
		for (int& d : nums)
			cout << d <<" ";
		cout << endl;
	}
	
	/* 方法3 ~ 二分法 */
	int findPeakElement(vector<int>& nums) {
		int start = 0, end = nums.size() - 1;
		while (start < end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] > nums[mid + 1])
				end = mid;
			else
				start = mid + 1;
		}
		return start;
	}
	
	void test()
	{
		vector<int> nums = { 1, 2, 1, 3, 5, 6, 4 };
		/*vector<int> nums = { 1, 2 };*/
		cout << "\n原数组："; shownums(nums); cout << endl;
		cout << "数组中某一峰值位置：" << findPeakElement(nums) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.3.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/01126d5e33424a2ea083619183da951c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 3、总结
 上述三种方法，从简单的调用API再到利用二分法，我觉得这就像三种做题的态度，害，挺有意思的，快乐~