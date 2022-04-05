作文以记之 ~ 实现strStr()
=
# 0、前言
本篇博客依然是一篇题解，具体题目可 [点击此处](https://leetcode-cn.com/problems/implement-strstr/) 进行查看！相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123943604) 进行查看！

其实这个题目主要是练习 KMP 算法的，所以下述两种解法中会有专门的应用！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/f8e5412caa4b4a6e8da8f74bf68b43f7.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 暴力遍历
### 2.1.1 思路
从两个字符串的首元素开始遍历，当完全遍历到与模式串相符合时，返回此时的起始位置。该思路简单，实现也简单，但相比较下会浪费较多的资源，因为一旦不满足模式串，就需要重新开始遍历。
### 2.1.2 程序代码


	#include<iostream>
	#include<string>
	#include<vector>
	using namespace std;
	
	/* 方法1 ~ 暴力遍历*/
	int strStr(string haystack, string needle) 
	{
		int n = haystack.size(), m = needle.size();
		if (m <= 0)
			return 0;
		int i, j;
		for (i = 0; i <= (n - m); i++)
		{
			for (j = 0; j < m; j++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}
			if (j == m)
				return i;
		}
		return -1;
	}
	
	void test()
	{
		string s1 = "mississippi";
		string s2 = "issip";
		cout << "\n主串：" << s1 << endl << "模式串：" << s2 << endl << endl;
		cout << "模式串在主串中出现的第一个位置：" << strStr(s1, s2) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/084315aa15f74776b77ae87f2a331321.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 方法2 ~ 利用KMP算法
### 2.2.1 思路
`Knuth–Morris–Pratt（KMP）`算法是一种改进的字符串匹配算法，它的核心是利用匹配失败后的信息，尽量减少模式串与主串的匹配次数以达到快速匹配的目的。有关KMP的内容，推荐两个网址（[网址1](https://leetcode-cn.com/leetbook/read/array-and-string/cpoo6/) 、 [网址2](https://blog.csdn.net/yyzsir/article/details/89462339)），有需要者可自行点击查看！此处不作过多解释~

而在该题中主要是利用`KMP`算法减少字符串的匹配次数，提高程序运行效率。
### 2.2.2 程序代码 


	#include<iostream>
	#include<string>
	#include<vector>
	using namespace std;
	
	/* 方法2 ~ KMP算法的代码1 */
	//vector<int> GetNext(const string& str)
	//{
	//	vector<int> next(str.size());
	//	int j = 0, k = -1;
	//	next[0] = k;	
	//	while (j<(str.size()-1))
	//	{
	//		if (k == -1 || str[j] == str[k])
	//		{
	//			++j;
	//			++k;
	//			next[j] = k;
	//		}
	//		else
	//			k = next[k];
	//	}
	//	return next;
	//}
	//
	//int strStr(string haystack, string needle) 
	//{
	//	vector<int> next = GetNext(needle);
	//	int n = haystack.size(), i = 0;
	//	int m = needle.size(), j = 0;
	//	if (m <= 0)
	//		return 0;
	//	while (i < n && j < m)
	//	{
	//		if (0>j || haystack[i] == needle[j])
	//			i++, j++;
	//		else
	//			j = next[j];
	//		if (j == m )
	//			return i - j;
	//	}
	//	return -1;
	//}
	
	/* KMP算法的代码2 */
	int strStr(string haystack, string needle) {
		int n = haystack.size(), m = needle.size();
		if (m == 0) {
			return 0;
		}
		vector<int> pi(m);
		for (int i = 1, j = 0; i < m; i++) {
			while (j > 0 && needle[i] != needle[j]) {
				j = pi[j - 1];
			}
			if (needle[i] == needle[j]) {
				j++;
			}
			pi[i] = j;
		}
		for (int i = 0, j = 0; i < n; i++) {
			while (j > 0 && haystack[i] != needle[j]) {
				j = pi[j - 1];
			}
			if (haystack[i] == needle[j]) {
				j++;
			}
			if (j == m) {
				return i - m + 1;
			}
		}
		return -1;
	}
	
	void test()
	{
		string s1 = "mississippi";
		string s2 = "issip";
		cout << "\n主串：" << s1 << endl << "模式串：" << s2 << endl << endl;
		cout << "模式串在主串中出现的第一个位置：" << strStr(s1, s2) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}


**注**：上述程序中提供了两种基于`KMP`算法的求解代码，第一个冗杂，第二个简洁，若有想了解第二个代码，可[点击此处](https://leetcode-cn.com/problems/implement-strstr/solution/shi-xian-strstr-by-leetcode-solution-ds6y/)进行具体分析！

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/e885ec53bba24332acfcb2340beaf374.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
本篇博客中的题目，最主要是用来练习`KMP`算法的，然后基于方法的多元性，又配上了一个简单的求解方法进行对比，读者可根据自己需求进行选择！只不过相比之下更推荐`KMP`算法！