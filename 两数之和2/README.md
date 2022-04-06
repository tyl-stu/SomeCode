作文以记之 ~ 两数之和2
=
# 0、前言
本篇博客依然是一题解，也是 [作文以记之 ~ 两数之和](https://blog.csdn.net/m0_51961114/article/details/123860761) 这篇博客的进阶版，因为此次所针对的题相较于[上述博客中的题](https://leetcode-cn.com/problems/two-sum/)，多了一些条件，具体题目可 [点击此处](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/) 进行查看！

本篇博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123953267) 进行查看！


# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/0752fa36b836479196d7f788c46f7bf3.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 利用哈希表
### 2.1.1 思路
此方法是利用哈希表将目标数组的所有数据位置进行记录，然后通过在其中找寻`target`与数组中某值的差值位置，来确定合适的两个整数 的下标!
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	#include<unordered_map>
	#include<string>
	
	using namespace std;
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/* 方法1 利用哈希表 */
	vector<int> twoSum(vector<int>& numbers, int target) {
		unordered_map<int, int> m;
		for (int i = 0; i<numbers.size(); i++)
		{
			int tmp = target - numbers[i];
			if (m.find(tmp) != m.end() && m[tmp] != i)
				return { m[tmp]+1, i+1};
			m[numbers[i]] = i;
		}
		return{};
	}
	
	void test()
	{
		vector<int> arr = {0,0,3,4};
		cout << "\n原数组："; showarr(arr);
		int target = 0;
		cout << "指定值：" << target << endl;
		cout << "处理后两个整数的下标："; showarr(twoSum(arr,target)); cout << endl;
		
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/d060c3b30c0547d8a889b1057c725ecf.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 方法2 ~ 利用双指针
### 2.2.1 思路
利用双指针的思路是 从数组的首尾开始，找寻两个整数之和等于目标值，其中大于目标值，则将末尾位置的指针左移，小于则将起始位置的指针右移，相等则将合适的下标进行返回，具体可以对照代码进行查看！
### 2.2.2 程序代码


	#include<iostream>
	#include<vector>
	#include<unordered_map>
	#include<string>
	
	using namespace std;
	
	/* https://leetcode-cn.com/problems/two-sum/ */
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/* 方法2 双指针 */
	vector<int> twoSum(vector<int>& numbers, int target) {
		int len = numbers.size();
		int start = 0, end = len - 1;
		while (start < end)
		{
			int sum = numbers[start] + numbers[end];
			if (sum == target)
				return{ start + 1, end + 1 };
			else if (sum > target)
				end--;
			else
				start++;
		}
		return{};
	}
	
	void test()
	{
		vector<int> arr = {0,0,3,4};
		cout << "\n原数组："; showarr(arr);
		int target = 0;
		cout << "指定值：" << target << endl;
		cout << "处理后两个整数的下标："; showarr(twoSum(arr,target)); cout << endl;
		
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/21062a9f8e294a469bbb802dc7a32d50.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.3 方法3 ~ 利用二分法
### 2.3.1 思路
此思路其实相当于是结合了方法2，即通过将数组元素与数组中值的和与指定值进行比较，大于则左移，小于则右移。可以通过下述代码进行对照！
### 2.3.2 程序代码


	#include<iostream>
	#include<vector>
	#include<unordered_map>
	#include<string>
	
	using namespace std;
	
	/* https://leetcode-cn.com/problems/two-sum/ */
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/* 方法3 二分查找 */
	vector<int> twoSum(vector<int>& numbers, int target) {
		for (int i = 0; i < numbers.size(); i++)
		{
			int start = i+1, end = numbers.size() - 1;
			while (start <= end)
			{
				int mid = (end - start) / 2 + start;
				if ((numbers[i] + numbers[mid]) == target)
					return{ i + 1, mid + 1 };
				else if ((numbers[i] + numbers[mid]) < target)//此时i的值不变，变得只能是mid，而他俩的和又小于target，因此需要将mid向右移，即mid++
					start = mid + 1;
				else
					end = mid - 1;
			}
		}
		return{};
	}
	
	void test()
	{
		vector<int> arr = {0,0,3,4};
		cout << "\n原数组："; showarr(arr);
		int target = 0;
		cout << "指定值：" << target << endl;
		cout << "处理后两个整数的下标："; showarr(twoSum(arr,target)); cout << endl;
		
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.3.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/6e0b685fff21492fb78d94f83546baef.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
上述题目难度不高，解法也比较多，同时在上面介绍了三种比较简单的解法，有需要者可自己通过运行上述代码进行实验分析！