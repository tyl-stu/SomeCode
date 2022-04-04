作文以记之 ~ 颠倒字符串中的单词
=
# 0、前言
本篇博客是力扣上 151.颠倒字符串中单词 题的题解，具体题目可 [点击此处](https://leetcode-cn.com/problems/reverse-words-in-a-string/) 进行查看！相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123936928) 进行查看！

题目依然不难，解法也很多，下面提供两种解法！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/b94129212e184bc1a2a5ec6fb5bc62e5.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 利用正则表达式
### 2.1.1 思路
此种方法的主要思路是 通过正则表达式获取目标字符串中的单词，然后将获取后的结果从后先前输入至指定字符串即可！

但该种方法虽然可以成功提交，但其资源消耗以及运行效率等不理想，只是在此处进行开拓思路而用！
### 2.1.2 程序代码


	#include<iostream>
	#include<string>
	#include<vector>
	#include<regex>
	#include<stack>
	using namespace std;
	
	/* 方法1 ~ 利用正则表达式 */
	vector<string> split(const string& input, const string& regex)
	{
		std::regex re(regex);
		std::sregex_token_iterator first { input.begin(), input.end(), re, -1 }, last;
		return{ first, last };
	}
	string reverseWords(string s) 
	{
		auto res = split(s, " ");
		string ans;
		for (int i = res.size() - 1; i >= 0; i--)
		{
			if (res[i] != "")
			{
				ans += res[i];
				ans += " ";
			}
		}
		ans.pop_back();
		return ans;
	}
	
	void test()
	{
		string s = " hello world ";
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
![在这里插入图片描述](https://img-blog.csdnimg.cn/eec6a5ee2ac34abd846868fc6bb686dd.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 方法2 ~ 利用栈
### 2.2.1 思路
该方法的思路是 将目标字符串从后向前遍历 ，遇到非空格的元素就将其压入栈，然后当遇到空格时将栈中元素添加至指定字符串中，只不过为了方便操作，若原字符串的0位置不是空格，则需为其添加一个空格。具体可对照下述代码！
### 2.2.2 程序代码


	#include<iostream>
	#include<string>
	#include<vector>
	#include<regex>
	#include<stack>
	using namespace std;
	
	/* 方法2 ~ 利用栈 */
	//string reverseWords(string s)
	//{
	//	
	//	stack<char> tmp;
	//	string ans;
	//	int i = s.size() - 1;
	//	while (s[i] == ' ')
	//		i--;
	//	for (; i >= 0; i--)
	//	{
	//		if (s[i] != ' ')
	//			tmp.push(s[i]);
	//		else if (s[i] == ' ')
	//		{
	//			if (i == 0 || s[i-1] != ' ')
	//			{
	//				while (!tmp.empty())
	//				{
	//					ans.push_back(tmp.top());
	//					tmp.pop();
	//				}
	//				ans.push_back(' ');
	//			}
	//			
	//		}
	//	}
	//	while (!tmp.empty())
	//	{
	//		ans.push_back(tmp.top());
	//		tmp.pop();
	//	}
	//	if (ans[ans.size() - 1] == ' ')
	//		ans.pop_back();
	//	return ans;
	//}
	
	string reverseWords(string s)
	{
		
		stack<char> tmp;
		string ans;
		if (s[0] != ' ')
			s = ' ' + s;
		int i = s.size() - 1;
		while (s[i] == ' ')
			i--;
		for (; i >= 0; i--)
		{
			if (s[i] != ' ')
				tmp.push(s[i]);
			else if (s[i] == ' ')
			{
				if (i == 0 || s[i-1] != ' ')
				{
					while (!tmp.empty())
					{
						ans.push_back(tmp.top());
						tmp.pop();
					}
					ans.push_back(' ');
				}
				
			}
		}
		
		if (ans[ans.size() - 1] == ' ')
			ans.pop_back();
		return ans;
	}
	
	void test()
	{
		string s = " hello world ";
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
![在这里插入图片描述](https://img-blog.csdnimg.cn/8e98c391e09a4e50ace5fc5ec68f7a14.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
上述两种方法中，逻辑都比较简单，但相比之下，不同的方法有不同的资源消耗和运行效率。同种情况下，资源消耗当然是越少越好。所以不建议使用第一种方法，同时第二种方法时利用了栈，但不建议使用`stack`，而是用`deque`。关于本体还有其他方法，比如记录空格的位置，然后根据空格的位置进行操作等，此处不再进行其他方法的实现，有需要者可自行探究！