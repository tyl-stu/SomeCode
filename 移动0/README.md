作文以记之 ~ 移动零
=
# 0、前言
本篇博客主要用于记载力扣中一题的解决思路与对应代码，具体的题目描述可 [点击此处](https://leetcode-cn.com/problems/move-zeroes/) 进行查看！相关博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123860370) 进行查看！
# 1、题目描述
改题目简单说就是将数组中的非零值按数组原有顺序依序前移，并将0后移。
![在这里插入图片描述](https://img-blog.csdnimg.cn/ec3cd9ffda1448bda0cd8e6132a4a353.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解决思路
## 2.1 调用函数
### 2.1.1 思路
此处的思路简单说就是通过一遍的遍历，将数组中的0元素删除，然后根据数组原来的长度对现有元素进行补0.
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	
	using namespace std;
	
	/* https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode-solution/ */
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/*方法1*/
	void moveZeroes(vector<int>& nums) {
		int n1 = nums.size();
		int i = 0;
		while ( i<nums.size())
		{
			if (nums[i] == 0)
			{
				nums.erase(nums.begin() + i);
				i = -1;
			}
			i++;
		}
		int n2 = n1 - nums.size();
		while (n2--)
		{
			nums.push_back(0);
		}
	}
	
	void test()
	{
		vector<int> arr = { 0,0,1,0,2 };
		cout << "\n原数组："; showarr(arr);
		moveZeroes(arr);
		cout << "处理后：";  showarr(arr); cout << endl;
		
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

## 2.2 新建数组
### 2.2.1 思路
此处思路就是通过遍历将原有数组的非零元素依次插入新数组中，然后为新数组补零。
### 2.2.2 程序代码

	#include<iostream>
	#include<vector>
	
	using namespace std;
	
	/* https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode-solution/ */
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/*方法2 新开数组*/
	void moveZeroes(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n);
		int i = 0;
		for (int &d : nums)
		{
			if (d != 0)
				ans[i++] = d;
		}
		nums = ans;
	}
	
	void test()
	{
		vector<int> arr = { 0,0,1,0,2 };
		cout << "\n原数组："; showarr(arr);
		moveZeroes(arr);
		cout << "处理后：";  showarr(arr); cout << endl;
		
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

## 2.3 单指针
### 2.3.1 思路
具体思路为通过单指针，依次遍历，将非0元素插入至数组前序，然后再此之后将剩下位置的元素进行置零。
### 2.3.2 程序代码


	#include<iostream>
	#include<vector>
	
	using namespace std;
	
	/* https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode-solution/ */
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/*方法3 单指针*/
	void moveZeroes(vector<int>& nums) {
		int start = 0;
		for (int &d:nums)
		{
			if (d != 0)
			{
				nums[start] = d;
				start++;
			}
		}
		for (int i = start; i < nums.size(); i++)
			nums[i] = 0;
	}
	
	void test()
	{
		vector<int> arr = { 0,0,1,0,2 };
		cout << "\n原数组："; showarr(arr);
		moveZeroes(arr);
		cout << "处理后：";  showarr(arr); cout << endl;
		
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

## 2.4 双指针
### 2.4.1 思路
思路为通过双指针，将非0元素放置在数组前序。此处我不想具体描述，可自行查看下述程序！
### 2.4.2 程序代码


	#include<iostream>
	#include<vector>
	
	using namespace std;
	
	/* https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode-solution/ */
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/*方法4 双指针*/
	void moveZeroes(vector<int>& nums) {
		int start = 0, end = 0;
		while (end<nums.size())
		{
			if (nums[end])
			{
				swap(nums[start], nums[end]);
				start++;
			}
			end++;
		}
	}
	
	void test()
	{
		vector<int> arr = { 0,0,1,0,2 };
		cout << "\n原数组："; showarr(arr);
		moveZeroes(arr);
		cout << "处理后：";  showarr(arr); cout << endl;
		
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

# 3、总结
上述四种方法，我没有配运行结果，主要是都可实现题目目标，然后就不想添加。有需要者可自行复制代码进行实现！