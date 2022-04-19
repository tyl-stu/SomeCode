作文以记之 ~ 打开转盘锁
=
# 0、前言
本篇博客是一篇题解，题目是力扣上的 [752. 打开转盘锁](https://leetcode-cn.com/problems/open-the-lock/) 题。这个题是练习 **广度优先搜索BFS** 的例题，挺有意思的，虽然自己第一次 coding 不出来~ `φ(*￣0￣)`

相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124260198) 进行查看！

**注**：我写的博客里有关`BFS`的练习题还有一些，比如 [作文以记之 ~ 岛屿数量](https://blog.csdn.net/m0_51961114/article/details/124217986) ~ （*初级*）

本篇中的题 (*中等*)

[作文以记之 ~ 单词接龙](https://blog.csdn.net/m0_51961114/article/details/124239143) （*困难*）

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/37011323d894420884a490972988eec5.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 利用BFS
### 2.1.1 思路
首先检测锁死的条件：也就是 `deadends` 元素数至少为`8`且正好将`target`包围，则说明必然锁死。或者一开始就是锁死状态。
初始化就是从`0000`开始，向周围`8`个结点发散，从无向图中来看就是从核心向周围不断扩散，同时记录扩散的圈数作为旋转次数，如果遇到`deadends`直接跳过，或者达到`target`直接返回即可。这种操作方式十分符合优化的`BFS`，每次处理相同循环步骤的结点，同时将下一层可能的结点加进去。其中利用哈希表中存储的就是不可能入队的结点，包括`deadends`和已入过队并处理的结点。

**实现**：
1. 进行锁死状态的检测（0000为锁死状态）
2. 初始化0000结点作为开始
3. 每次循环时计算队列长度，处理队头结点，将队头结点相邻的结点入队并加入哈希集，能在哈希集中找到的结点就不再入队，同时step每次循环时增加1
4. 遇到target则直接返回step找到答案

上面这一段是我抄的官方题解，具体可 [点击此处](https://leetcode-cn.com/problems/open-the-lock/solution/c-bfs-jie-jue-zhuan-dong-kai-suo-by-bei-lpvye/) 进行查看！

### 2.1.2 程序实现


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

这个代码也是借鉴上面的题解，说起这就感觉这个博客没有一点自己的内容，害。但写博客主要是给自己写，加油吧！
## 2.2 其他方法
这个题还有其他方法，比如启发式搜索，但这个自己暂时没会，后面会了再补充吧！

*侵权删~*

