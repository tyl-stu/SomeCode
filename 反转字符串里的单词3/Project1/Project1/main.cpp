#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include<stack>
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