#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
	// 方法1 ~ BFS
	/*int numSquares(int n) {
		unordered_set<int> vis;
		queue<int> que;
		que.push(0);
		int step = 1;
		while (!que.empty())
		{
			int size = que.size();
			while (size--)
			{
				int cur = que.front();
				que.pop();
				for (int i = 1; i*i + cur <= n; i++)
				{
					int next = i*i + cur;
					if (next == n)
						return step;
					if (!vis.count(next))
					{
						que.push(next);
						vis.emplace(next);
					}
				}
			}
			step++;
		}
		return -1;
	}*/

	//方法2~动归
	/*int numSquares(int n) {
		vector<int> f(n + 1);
		for (int i = 1; i <= n; i++) {
			f[i] = i;
			for (int j = 1; j * j <= i; j++) {
				f[i] = min(f[i], f[i - j * j]+1);
			}
		}
		return f[n];
	}*/

	//方法3~数学规律--四方平和定理
	// 判断是否为完全平方数
	bool isSqrt(int x)
	{
		int y = sqrt(x);
		return y*y == x;
	}
	// 判断是否能表示为 4^k*(8m+7)
	bool checkAns(int x)
	{
		while (x % 4 == 0)
			x /= 4;
		return x % 8 == 7;
	}
	int numSquares(int n) {
		if (isSqrt(n))
			return 1;
		if (checkAns(n))
			return 4;
		for (int i = 1; i*i <= n; i++)
		{
			int j = n - i*i;
			if (isSqrt(j))
				return 2;
		}
		return 3;
	}
};

void test()
{
	Solution s;
	s.numSquares(12);
}

int main()
{
	test();
	system("pause");
	return 0;
}