作文以记之 ~ 完全平方数
=
# 0、前言
本篇是力扣上 [279.完全平方数](https://leetcode-cn.com/problems/perfect-squares/submissions/) 的题解，这个题目和我另外一篇题解即 [作文以记之 ~ 平方根 与 完全平方数](https://blog.csdn.net/m0_51961114/article/details/124073372) 中的题目有点类似，但还是有一些差别。前者是找出一个数可由几个完全平方数进行累加，后者是判断一个数是否是完全平方数！

同时这也是**广度优先搜索BFS**的练习题，难度中等。

具体题目可 [点击此处](https://leetcode-cn.com/problems/perfect-squares/submissions/) 进行查看！
相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124267518) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/4d07e1228c134e86897fc1163ea90573.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 利用BFS
### 2.1.1 思路
![在这里插入图片描述](https://img-blog.csdnimg.cn/cba51c075f8349dfa152c9657f64d460.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
### 2.1.2 程序代码


	class Solution {
	public:
		int numSquares(int n) {
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
		}
	};

**注**：以上思路中的图以及代码借鉴于力扣上[一大佬的题解](https://leetcode-cn.com/problems/perfect-squares/solution/zhong-gui-zhong-ju-duo-jie-fa-tuo-zhan-jie-ti-si-l/)，侵权删~

## 2.2 方法2 ~ 利用动态规划
### 2.2.1 思路
![在这里插入图片描述](https://img-blog.csdnimg.cn/c794c60900f44cf1887aba5889fd15ab.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
### 2.2.2 程序代码


	class Solution {
	public:
		//方法2~动归
		int numSquares(int n) {
			vector<int> f(n + 1);
			for (int i = 1; i <= n; i++) {
				f[i] = i;
				for (int j = 1; j * j <= i; j++) {
					f[i] = min(f[i], f[i - j * j]+1);
				}
			}
			return f[n];
		}
	
	};


注：以上思路代码借鉴于又一大佬的题解，有需要者[点击此处](https://leetcode-cn.com/problems/perfect-squares/solution/hua-jie-suan-fa-279-wan-quan-ping-fang-shu-by-guan/)查看！
## 2.3 方法3 ~ 数学规律-- 四方平和定理
### 2.3.1 思路
![在这里插入图片描述](https://img-blog.csdnimg.cn/72bb601eca844e6c8b10a81ba602a91c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

### 2.3.2 程序代码


	class Solution {
	public:
	
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

注：以上思路以及程序代码来源于[力扣官方题解](https://leetcode-cn.com/problems/perfect-squares/solution/wan-quan-ping-fang-shu-by-leetcode-solut-t99c/)，有需要者自己点击查看！

上述三种方法真的是，有点意思，我自己一开始三种都没有coding出来，自己真的是太菜了，害

*侵权删~*