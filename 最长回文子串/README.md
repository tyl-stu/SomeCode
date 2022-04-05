作文以记之 ~ 最长回文子串
=
# 0、前言
该篇博客是力扣上一题，即最长回文子串的题解，具体题目可 [点击此处](https://leetcode-cn.com/problems/longest-palindromic-substring/) 进行查看！相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123933440) 进行查看！

题目难度中等，有较多解法！有需要者可直接点击上述题目查看所有题解！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/29dcccfa11574608b1b1ed0c4dfc8b13.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法一 ~ 中心扩展法
### 2.1.1 思路
该种方法的思路主要是从字符串中每一个元素位置开始，向该位置的两边元素进行扩展，遇到不是回文子串则停止。其中扩展初始包含了两种情况，一种是单个字符，一种是两个相同的字符，因此在编写代码时，需对两种不同情况进行分析！
### 2.1.2 程序代码

	#include<iostream>
	#include<string>
	#include<vector>
	using namespace std;
	
	vector<int> findRange(string& s, int left, int right)
	{
		while (left >= 0 && right < s.size() && s[left] == s[right])
		{
			--left;
			++right;
		}
		return { ++left, --right };
	}
	
	string longestPalindrome(string s) 
	{
		int start = 0, end = 0;
		vector<int> n1, n2;
		for (int i = 0; i < s.size(); i++)
		{
			n1 = findRange(s, i, i);//检测回文字符串中心为单字符
			n2 = findRange(s, i, i + 1);//检测回文字符串中心为双字符
			if ((n1[1] - n1[0]) > (end - start))
			{
				start = n1[0];
				end = n1[1];
			}
			if ((n2[1] - n2[0]) > (end - start))
			{
				start = n2[0];
				end = n2[1];
			}
		}
		return s.substr(start, end - start + 1);
	}
	
	void test()
	{
		string s = "babad";
		cout << "\n原字符串：" << s << endl << endl;
		cout << "\n最长回文字串：" << longestPalindrome(s) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/871b230b35ea4b3483ecfc9e56dc07d0.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 其他方法
关于本体的解法还有很多，比如动态规划、Manacher 算法等，只不过作者暂时没实现其他方法，等后续有时间再进行补充！

# 3、总结
本题难度中等，是字符串类型习题的典型例题，对初学者挺有开拓思维之功能！加油~