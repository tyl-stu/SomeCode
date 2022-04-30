
@[TOC](作文以记之 ~  字符串解码)
# 0、前言
本篇博客是力扣上 [394. 字符串解码](https://leetcode-cn.com/problems/decode-string/) 题的题解，题目难度还可以，挺有意思的，写博客主要是想记录一下！

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124517278) 进行查看！


# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/e5385228055643f38df1c3357afac76c.png)

# 2、解题思路
## 2.1 方法1 ~ 利用迭代
### 2.1.1 思路
此种思路主要是以数字和`']'` 为判断界限进行相关操作，具体过程为：

1. 从字符串`s`的起始位置开始进行遍历，当遇到**数字**、**没有包含`'[]'`中任一字符的连续字符串**、**只包含`'['`的连续字符串** 中任一类型数据时，则将对应内容保存至栈 `st` 中；

2. 当遇到`']'` 即说明需要对此符号前面的字符串进行翻倍操作，此处主要是先从`st`中取出对应的字符串和数字，需要注意的是，此处在取到合适数字前可能不止一个字符串，所以需要对满足要求的字符串进行拼接然后再进行其他操作;


3. 当`s`遍历结束之后，此时`st`中可能不止一个字符串，因此也需对`st`中的内容进行拼接，以获得最终答案！
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	#include<stack>
	#include<string>
	using namespace std;
	
	/* 迭代实现 - 利用栈 （未优化） */
	//class Solution {
	//public:
	//	stack<string> st;
	//	void addData(string s, int idx)
	//	{
	//		string data;
	//		while (isdigit(s[idx]))
	//		{
	//			data += s[idx];
	//			idx++;
	//		}
	//		st.push(data);
	//	}
	//	void addString(string s, int idx)
	//	{
	//		string str;
	//		while (isalpha(s[idx]) || s[idx] == '[')
	//		{
	//			str += s[idx];
	//			idx++;
	//		}
	//		st.push(str);
	//	}
	//	string decodeString(string s) {
	//		int idx = 0;
	//		string ans;
	//		while (idx < s.size())
	//		{
	//			if (isdigit(s[idx]))
	//			{
	//				addData(s, idx);
	//				idx += st.top().size();
	//			}
	//			else if (isalpha(s[idx]) || s[idx] == '[')
	//			{
	//				addString(s, idx);
	//				idx += st.top().size();
	//			}
	//			else
	//			{
	//				string tmp;
	//				string t2,t1;
	//				int n;
	//				if (s[idx] == ']')
	//				{
	//					t1 = st.top();
	//					string top2;
	//					while(!isdigit(t1[0]))
	//					{
	//						st.pop();
	//						top2 = t1 + top2;
	//						t1 = st.top();	
	//					}
	//					tmp = top2 == "" ? t1 : top2;
	//					tmp = tmp.substr(1);
	//					n = stoi(st.top());
	//					st.pop();
	//					idx++;
	//				}
	//				while (n--)
	//					t2 += tmp;
	//				if (!st.empty())
	//				{
	//					string top = st.top();
	//					st.pop();
	//					top += t2;
	//					st.push(top);
	//				}
	//				else
	//					st.push(t2);
	//			}
	//		}
	//		int size = st.size();
	//		while (size--)
	//		{
	//			string top = st.top();
	//			ans.insert(0, top);
	//			st.pop();
	//		}
	//		return ans;
	//	}
	//};
	
	/* 迭代实现 - 利用栈 （已优化） */
	class Solution {
	public:
		stack<string> st;
		void addData(string s, int idx)
		{
			string data;
			while (isdigit(s[idx]))
			{
				data += s[idx];
				idx++;
			}
			st.push(data);
		}
		void addString(string s, int idx)
		{
			string str;
			while (isalpha(s[idx]) || s[idx] == '[')
			{
				str += s[idx];
				idx++;
			}
			st.push(str);
		}
		string decodeString(string s) {
			int idx = 0;
			string ans;
			while (idx < s.size())
			{
				if (isdigit(s[idx])) //先获取数字部分，然后索引 idx 跳到当前整体数字的后一位，并插入栈st
				{
					addData(s, idx);
					idx += st.top().size();
				}
				else if (isalpha(s[idx]) || s[idx] == '[') //获取是字母或者以'['为开头，以']' 为结尾的部分,并插入栈st
				{
					addString(s, idx);
					idx += st.top().size();
				}
				else
				{
					string tmp, top;//tmp,top 为中间变量，方便对 st 中的内容进行操作
					int n;
					if (s[idx] == ']') //当遇到 ']' 时说明需要按照前面的数字对当前的字符进行翻倍拼接
					{
						string top2;
						while (!isdigit(st.top()[0])) //将 st 中遇到 ']' 前的位置的所有字符进行整合
						{
							tmp = st.top() + tmp;
							st.pop();
						}
						tmp = tmp.substr(1);//将tmp中的 '[' 去掉，只保留字母部分
						n = stoi(st.top());//获取数字
						st.pop();
						idx++;//索引自加，不能缺少！！！
					}
					while (n--)
						top += tmp;
					st.push(top);//将翻倍后的字符插入st中以方便后续操作
				}
			}
			while (!st.empty())//最后操作结束后，st中可能不止一个元素，此时需进行整合
			{
				ans = st.top() + ans;
				st.pop();
			}
			return ans;
		}
	};
	
	void test()
	{
		string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
		Solution sol;
		cout << sol.decodeString(s) << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}


***注意**：此处程序中，注释部分处即为一开始写代码时的实现程序，其未进行优化，未注释的部分即为进行优化后的程序！*
## 2.2 方法2 ~ 利用递归
### 2.2.1 思路

当明白第一个思路后，这个递归其实挺容易实现的，思路也大致相同，只不过将许多显式代码利用递归进行了实现！

具体内容就自己看代码吧，或者看[官方题解](https://leetcode-cn.com/problems/decode-string/solution/zi-fu-chuan-jie-ma-by-leetcode-solution/) ，此处就不再赘述！

### 2.2.2 程序代码


	#include<iostream>
	#include<vector>
	#include<stack>
	#include<string>
	using namespace std;
	
	/* 递归实现 */
	class Solution {
	public:
		string src;
		int idx; //索引，定为全局变量只是为了方便后续操作
		int getNums()
		{
			int ret = 0;
			while (idx < src.size() && isdigit(src[idx]))
				ret = ret * 10 + src[idx++] - '0';
			return ret;
		}
		string getString()
		{
			if (idx == src.size() || src[idx] == ']')
				return "";
			int nums;
			string ret;
			if (isdigit(src[idx]))
			{
				nums = getNums();
				++idx;//过滤'['
				string tmp = getString();
				++idx;//过滤 ']'
				while (nums--)
					ret += tmp;
			}
			else if (isalpha(src[idx]))
			{
				ret = string(1, src[idx++]);//此处idx必须自加或者右移，否则无法进行后面字符的遍历！！！！
			}
			return ret + getString();
		}
		string decodeString(string s) {
			src = s;
			idx = 0;
			return getString();
		}
	};
	
	void test()
	{
		string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
		Solution sol;
		cout << sol.decodeString(s) << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

