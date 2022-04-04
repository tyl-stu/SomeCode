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
//string longestCommonPrefix(vector<string>& strs) 
//{
//	string ans;
//	int len = strs[0].size();
//	for (string& s : strs)
//		len = len < s.size() ? len : s.size();
//	char tmp;
//	int t = 0;
//	for (int i = 0; i < len; i++)
//	{
//		tmp = strs[0][i];
//		for (int j = 1; j < strs.size(); j++)
//		{
//			if (strs[j][i] == tmp)
//				++t;
//			else
//				return ans;
//		}
//		if (t == (strs.size()-1))
//			ans.push_back(tmp);	
//		t = 0;
//	}
//	return ans;
//}

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