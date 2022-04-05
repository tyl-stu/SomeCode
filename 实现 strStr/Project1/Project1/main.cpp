#include<iostream>
#include<string>
#include<vector>
using namespace std;

/* 方法1 ~ 暴力遍历*/
//int strStr(string haystack, string needle) 
//{
//	int n = haystack.size(), m = needle.size();
//	if (m <= 0)
//		return 0;
//	int i, j;
//	for (i = 0; i <= (n - m); i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			if (haystack[i + j] != needle[j])
//				break;
//		}
//		if (j == m)
//			return i;
//	}
//	return -1;
//}

/* 方法2 ~ KMP算法的代码1 */
vector<int> GetNext(const string& str)
{
	vector<int> next(str.size());
	int j = 0, k = -1;
	next[0] = k;	
	while (j<(str.size()-1))//因为构造next的根据是模式串的最长公共前后缀的长度，而这最长不可超过 str.size()-1
	{
		if (k == -1 || str[j] == str[k])
		{
			++j;
			++k;
			next[j] = k;
		}
		else
			k = next[k];
	}
	return next;
}

int strStr(string haystack, string needle) 
{
	vector<int> next = GetNext(needle);
	int n = haystack.size(), i = 0;
	int m = needle.size(), j = 0;
	if (m <= 0)
		return 0;
	while (i < n && j < m)
	{
		if (0>j || haystack[i] == needle[j])//其中j<0相当于是重新开始判断，因为next 中的第一个数是 -1
			i++, j++;
		else
			j = next[j];
		if (j == m )
			return i -j;
	}
	return -1;
}

/* KMP算法的代码2 */
//int strStr(string haystack, string needle) {
//	int n = haystack.size(), m = needle.size();
//	if (m == 0) {
//		return 0;
//	}
//	vector<int> pi(m);
//	//找寻模式串中的最大公共前缀后缀长度
//	for (int i = 1, j = 0; i < m; i++) {
//		while (j > 0 && needle[i] != needle[j]) {//相当于是此时元素不相同，然后转到上一个位置重新开始
//			j = pi[j - 1];
//		}
//		if (needle[i] == needle[j]) {
//			j++;
//		}
//		pi[i] = j;
//	}
//	for (int i = 0, j = 0; i < n; i++) {
//		while (j > 0 && haystack[i] != needle[j]) {//j发生变化只是为了更有效的遍历模式串
//			j = pi[j - 1];
//		}
//		if (haystack[i] == needle[j]) {
//			j++;
//		}
//		if (j == m) {
//			return i - m + 1;
//		}
//	}
//	return -1;
//}

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