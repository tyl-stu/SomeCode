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
//			if (isdigit(s[idx])) //先获取数字部分，然后索引 idx 跳到当前整体数字的后一位，并插入栈st
//			{
//				addData(s, idx);
//				idx += st.top().size();
//			}
//			else if (isalpha(s[idx]) || s[idx] == '[') //获取是字母或者以'['为开头，以']' 为结尾的部分,并插入栈st
//			{
//				addString(s, idx);
//				idx += st.top().size();
//			}
//			else
//			{
//				string tmp, top;//tmp,top 为中间变量，方便对 st 中的内容进行操作
//				int n;
//				if (s[idx] == ']') //当遇到 ']' 时说明需要按照前面的数字对当前的字符进行翻倍拼接
//				{
//					string top2;
//					while (!isdigit(st.top()[0])) //将 st 中遇到 ']' 前的位置的所有字符进行整合
//					{
//						tmp = st.top() + tmp;
//						st.pop();
//					}
//					tmp = tmp.substr(1);//将tmp中的 '[' 去掉，只保留字母部分
//					n = stoi(st.top());//获取数字
//					st.pop();
//					idx++;//索引自加，不能缺少！！！
//				}
//				while (n--)
//					top += tmp;
//				st.push(top);//将翻倍后的字符插入st中以方便后续操作
//			}
//		}
//		while (!st.empty())//最后操作结束后，st中可能不止一个元素，此时需进行整合
//		{
//			ans = st.top() + ans;
//			st.pop();
//		}
//		return ans;
//	}
//};

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