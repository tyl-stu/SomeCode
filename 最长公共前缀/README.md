作文以记之 ~ 最长公共前缀
=
# 0、前言
本篇博客是一篇题解，具体题目可 [点击此处](https://leetcode-cn.com/problems/longest-common-prefix/) 进行查看！相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123929205) 进行查看！下述所给两种解法，虽说是两种，起始是一种算法的双写，一个简洁，一个冗杂，正文开始！
# 1、问题描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/12e0e3fabf79405091f7140f68ed6fa9.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解决思路
## 2.1 方法1 ~ 利用双层循环
### 2.1.1 思路
简单说就是从所给string数组的第一个元素的第一个字符开始，通过循环遍历与其他元素进行比较，若相同则插入指定数组，不同则直接退出！
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	#include<string>
	#include<algorithm>
	
	using namespace std;
	
	void showstrs(vector<string>& strs)
	{
		for (string& s : strs)
			cout << s << " ";
		cout << endl;
	}
	
	/* 方法1 ~ 通过双层遍历*/
	string longestCommonPrefix(vector<string>& strs) 
	{
		string ans;
		int len = strs[0].size();
		for (string& s : strs)
			len = len < s.size() ? len : s.size();
		char tmp;
		int t = 0;
		for (int i = 0; i < len; i++)
		{
			tmp = strs[0][i];
			for (int j = 1; j < strs.size(); j++)
			{
				if (strs[j][i] == tmp)
					++t;
				else
					return ans;
			}
			if (t == (strs.size()-1))
				ans.push_back(tmp);	
			t = 0;
		}
		return ans;
	}
	
	void test()
	{
		vector<string> strs = { "cir", "car","abc" };
		cout << "\n字符串数组：\n";
		showstrs(strs); cout << endl;
		cout << "\n公共前缀：\n";
		cout << longestCommonPrefix(strs) << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/bd0f07d010af452bb516589964d43d43.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 方法2 ~ 利用嵌套循环
### 2.2.1 思路
相比于上述方法1，我更推荐方法2，因为方法2相比于方法1减少了资源开销，提高了运行效率。具体思路是通过横向扫描，结果嵌套循环，内核与方法1大致相同，详细情况直接看下述代码！

### 2.2.2 程序代码


	#include<iostream>
	#include<vector>
	#include<string>
	#include<algorithm>
	
	using namespace std;
	
	void showstrs(vector<string>& strs)
	{
		for (string& s : strs)
			cout << s << " ";
		cout << endl;
	}
	
	/* 方法2 利用给嵌套循环*/
	string sublongestCommonPrefix(string& str1, string& str2)
	{
		int len = min(str1.size(), str2.size());
		int index = 0;
		while (index < len && str1[index] == str2[index])
		{
			++index;
		}
		return str1.substr(0, index);
	}
	
	string longestCommonPrefix(vector<string>& strs) {
		string ans = strs[0];
		for (int i = 1; i<strs.size(); i++)
			ans = sublongestCommonPrefix(ans, strs[i]);
		return ans;
	}
	
	void test()
	{
		vector<string> strs = { "cir", "car","cab" };
		cout << "\n字符串数组：\n";
		showstrs(strs); cout << endl;
		cout << "\n公共前缀：\n";
		cout << longestCommonPrefix(strs) << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/ecc109a2bdd445388d710057e84e64c9.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
本次这个题是一个简单题，可有多种解决方法，上述只是列出了最常用的方法，但相比之下推荐第二种方法！fighting~