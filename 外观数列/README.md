作文以记之 ~ 外观数列
=
# 0、前言
这是力扣上 [38. 外观数列](https://leetcode.cn/problems/count-and-say/) 题的题解，题目简单，写博客主要是记录两个题解~

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124739615) 进行查看！


# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/2699b27fd291490ab6bf3a870828a45a.png)


# 2、解题思路
## 2.1 方法1 ~ 迭代
### 2.1.1 思路
这个思路的实现结合了队列，利用其先进先出的性质，对数据进行合理的计数，然后在最后将队列中的数据按顺序导入字符串即可，具体看代码，不想说步骤~
### 2.1.2 程序代码

	class Solution {
	public:
		string countAndSay(int n) 
		{
			queue<int> que, tmp;
			que.push(1);
			//这块其实一开始实现时以为是从1开始，即当n=1时，此时的外观数列为11；最后发现相较于题目要求，提前了一步。所以就把判断条件中的 n-- 变为了 --n
			while (--n)
			{
				while (!que.empty())
				{
					int cur = que.front();
					que.pop();
					int num = 1;
					while (!que.empty() && cur == que.front())
					{
						num++; que.pop();
					}
					tmp.push(num);
					tmp.push(cur);
				}
				que = tmp;
				tmp = queue<int>();
			}
			string ans;
			while (!que.empty())
			{
				ans += que.front() + '0';
				que.pop();
			}
			return ans;
		}
	};

## 2.2 方法2 ~ 递归
### 2.2.1 思路
这个方法实现起来也简单，设好判定条件一步步的迭代循环即可，具体看代码~
### 2.2.2 程序代码


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

