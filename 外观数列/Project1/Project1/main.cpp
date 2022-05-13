#include<iostream>
#include<queue>
#include<string>
using namespace std;

//class Solution {
//public:
//	string countAndSay(int n) 
//	{
//		queue<int> que, tmp;
//		que.push(1);
//
//		while (--n)
//		{
//			while (!que.empty())
//			{
//				int cur = que.front();
//				que.pop();
//				int num = 1;
//				while (!que.empty() && cur == que.front())
//				{
//					num++; que.pop();
//				}
//				tmp.push(num);
//				tmp.push(cur);
//			}
//			que = tmp;
//			tmp = queue<int>();
//		}
//		string ans;
//		while (!que.empty())
//		{
//			ans += que.front() + '0';
//			que.pop();
//		}
//		return ans;
//	}
//};

class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) 
			return "1";
		string s = countAndSay(n - 1), ans;
		int num = 1;
		for (int i = 0; i < s.size(); ++i) 
		{
			if (s[i] != s[i + 1]) 
			{
				ans.push_back(num + '0');
				ans.push_back(s[i]);
				num = 1;
			}
			else 
			{
				num++;
			}
		}
		return ans;
	}
};


void test()
{
	int n = 4;
	Solution s;
	cout << "n = " << n << " 时的外观序列为：" << s.countAndSay(n) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}