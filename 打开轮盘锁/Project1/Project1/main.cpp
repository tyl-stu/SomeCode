#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int openLock(vector<string>& deadends, string target) 
	{
		unordered_set<string> list;//list保存不可能入队的和已经访问过的节点
		list.insert(deadends.begin(), deadends.end());
		if (list.count("0000"))
			return -1;
		int step = 0;
		queue<string> que;
		que.push("0000");//从 "0000" 开始查找
		while (!que.empty())
		{
			int len = que.size();
			while (len)
			{
				string cur = que.front();
				que.pop();
				if (cur == target)
					return step;
				for (int i = 0; i < 4; i++)
				{
					for (int j = -1; j < 2; j += 2)
					{
						char a = (cur[i] - '0' + 10 + j) % 10 + '0';
						string newOne = cur;
						newOne[i] = a;
						if (!list.count(newOne))
						{
							list.emplace(newOne);
							que.push(newOne);
						}
					}
				}
				len--;
			}
			step++;
		}
		return -1;
	}
};

void test()
{
	vector<string> deadends = { "0201", "0101", "0102", "1212", "2002" };
	string target = "0202";
	Solution s;
	cout << "旋转次数：" << s.openLock(deadends, target) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}