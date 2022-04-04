#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include<stack>
using namespace std;

/* 方法1 ~ 利用正则表达式 */
//vector<string> split(const string& input, const string& regex)
//{
//	std::regex re(regex);
//	std::sregex_token_iterator first { input.begin(), input.end(), re, -1 }, last;
//	return{ first, last };
//}
//string reverseWords(string s) 
//{
//	auto res = split(s, " ");
//	string ans;
//	for (int i = res.size() - 1; i >= 0; i--)
//	{
//		if (res[i] != "")
//		{
//			ans += res[i];
//			ans += " ";
//		}
//	}
//	ans.pop_back();
//	return ans;
//}

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