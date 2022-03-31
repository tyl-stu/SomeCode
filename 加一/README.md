作文以记之 ~ 数组元素加一
=
# 0、前言
这篇博客是一题解，具体题目内容可以 [点击此处](https://leetcode-cn.com/problems/plus-one/) 进行查看！对应的博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123859719?spm=1001.2014.3001.5502) 进行查看！题目不难，只不过多少还是有点感触！具体内容如下。
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/23dad6f3bed2440d8a4987e46a23c132.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解决措施
## 2.1 结合库函数
### 2.1.1 思路
具体思路就是从数组最后一个元素开始加1，若有进位则给前一个元素进行加1，直至数组首元素。若数组首元素在加1后还有进位，则给数组最开始添加一个值为1的元素。
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	#include<map>
	#include<string>
	
	using namespace std;
	
	/* https://leetcode-cn.com/problems/plus-one/solution/ */
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/*方法1  -- 调用库函数*/
	vector<int> plusOne(vector<int>& digits) 
	{
		int end = ++digits[digits.size() - 1];
		int i = 1;
		while (1)
		{
			if (end / 10 == 1)
			{
				digits[digits.size() - i] = 0;
				if (digits.size()>i)
					++digits[digits.size() - (i + 1)];
				else
					digits.insert(digits.begin(), 1);
			}
			else
				break;
			end = digits[digits.size() - (i + 1)];
			i++;
		}
		return digits;
	}
	
	void test()
	{
		vector<int> arr = { 1, 9, 9, 8 };
		cout << "\n原数组："; showarr(arr);
		cout << "处理后："; showarr(plusOne(arr)); cout << endl;
		vector<int> arr2 = { 9, 9, 9 };
		cout << "\n原数组："; showarr(arr2);
		cout << "处理后："; showarr(plusOne(arr2)); cout << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/e677f96cc48a481fa535c5cbbdf9e17e.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 分情况实现
### 2.2.1 思路
此种方法就是先判断数组从后向前9的个数，若数组元素并非全9，则从元素最后一位开始进行加1，有进位则向前一位元素加1；若数组元素都是9，则直接定义一个长度比原数组个数多1的数组，使其首元素为1，其他元素为0.
### 2.2.2 程序代码


	#include<iostream>
	#include<vector>
	#include<map>
	#include<string>
	
	using namespace std;
	
	/* https://leetcode-cn.com/problems/plus-one/solution/ */
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/*方法2 -- 分情况实现*/
	vector<int> plusOne(vector<int>& digits)
	{
		int n = digits.size();
		for (int i = n-1; i >= 0; i--)
		{
			if (digits[i] != 9)
			{
				++digits[i];
				for (int j = i + 1; j < n; j++)
					digits[j] = 0;
				return digits;
			}
		}
		vector<int> ans(n + 1);
		ans[0] = 1;
		return ans;
	}
	
	void test()
	{
		vector<int> arr = { 1, 9, 9, 8 };
		cout << "\n原数组："; showarr(arr);
		cout << "处理后："; showarr(plusOne(arr)); cout << endl;
		vector<int> arr2 = { 9, 9, 9 };
		cout << "\n原数组："; showarr(arr2);
		cout << "处理后："; showarr(plusOne(arr2)); cout << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/2961b1b3c6d44dac9bde3c31958c3cbd.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
本篇文章中的题目并不难，只不过在自己实现的过程中，感觉自己有点头铁，想一直用自己的方法实现，哪怕自己的方法不是最优，哪怕浪费太多的时间，但还是做的津津有味。我觉得我头铁的毛病可能消除不了，希望后面可以从一开始就想到最优或较优方法！加油吧！