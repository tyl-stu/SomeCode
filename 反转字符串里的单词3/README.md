作文以记之 ~ 反转字符串中的单词3
=
# 0、前言
本篇博客是一篇题解，此前有一篇名为 [作文以记之 ~ 颠倒字符串中的单词](https://blog.csdn.net/m0_51961114/article/details/123936928)  博客中的题目与本篇博客中的题目有些相似，或者说是进阶，整体难度不难，有需要者可了解一下上述博客内容！而本篇中的题目具体描述可 [点击此处](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/) 进行查看！而博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123966380) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/71b97e6133f3411e944b95643b9f57c3.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 在字符串上直接操作
### 2.1.1 思路
这种方法的思路是在原字符串上，设置双指针`fast`、`low`，其中快指针`fast`是用于查找空格，`low`则用于记载单词的起始位置。当检测到空格时，则直接对该空格之前或到上一个空格之间的内容进行逆置，然后将`fast`与`low`重新赋值，使其从下一个单词又重新开始上述操作！
### 2.1.2 程序代码


	#include<iostream>
	#include<string>
	#include<vector>
	using namespace std;
	
	/* 方法1 ~ 在字符串上直接操作 */
	void swaps(string& s, int start, int end)
	{
		while (start < end)
		{
			swap(s[start], s[end]);
			start++; end--;
		}
	}
	string reverseWords(string s) 
	{
		string ans = s;
		for (int fast = 0, low = 0; fast < ans.size(); fast++)
		{
			if (ans[fast] == ' ')
			{
				swaps(ans, low, fast - 1);
				++fast;
				low = fast;
			}
			if (fast == ans.size() - 1)
				swaps(ans, low, fast);
		}
		return ans;
	}
	
	void test()
	{
		string s = "Let's take LeetCode contest";
		cout << "\n原字符串：" << s << endl << endl;
		cout << "\n现字符串：" << reverseWords(s) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/289c2ec3ae594ede9cf3026717b66204.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 方法2 ~ 截取字符串
### 2.2.1 思路
这种方法还是通过检测目标字符串的空格找出字符串中单词的范围，然后将原字符串中单词截取后进行逆置，然后将逆置后的结果存入指定字符串中，直至原字符串遍历结束！

这个方法本质上其实和方法1 差不多，只不过一个是在字符串上进行操作，一个需要另开空间！
### 2.2.2 程序代码


	#include<iostream>
	#include<string>
	#include<vector>
	using namespace std;
	
	/*方法2 ~ 截取字符串实现*/
	string swap_s(string s)
	{
		char *start = (char *)s.c_str();
		char *ends = start + s.size() - 1;
		while (start < ends)
		{
			swap(*start, *ends);
			start++;
			ends--;
		}
		return s;
	}
	string reverseWords(string s) {
		int i = 0;
		string s2;
		while (i < s.size())
		{
			int j = s.find(' ', i + 1);
	
			string t = swap_s(s.substr(i, j - i));//sustr（pos,n） 是从pos截取n个字符
			//cout << "i = " << i << "  " << "j = " << j << endl;
			t.push_back(' ');
			s2.append(t);
			if (j == -1)
			{
				s2.pop_back();
				break;
			}
			i = j + 1;
		}
		return s2;
	}
	
	void test()
	{
		string s = "Let's take LeetCode contest";
		cout << "\n原字符串：" << s << endl << endl;
		cout << "\n现字符串：" << reverseWords(s) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/f09f45a1ac424b54a6962a5b1b3d68f3.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
博客中的题难度不高，有较多解法，人与人的思维不一样，所以不奢求与别人一致，但只愿可吸收别人的想法。没其他可说的了，加油吧，打工人~