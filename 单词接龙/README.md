作文以记之 ~ 单词接龙
=
# 0、前言
这是一篇题解，题目是针对**广度优先搜索BFS**的练习题，挺有意思的。难度怎么说呢，可以说知道怎么做，也知道`BFS`的原理，可就是写不出代码，自己太菜了，所以下面的实现代码大多是对官方题解中的代码的阐述！

具体题目可 [点击此处](https://leetcode-cn.com/problems/word-ladder/) 进行查看！

相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124239143) 进行查看！


**注**：我写的博客里有关`BFS`的练习题还有一些，比如 [作文以记之 ~ 岛屿数量](https://blog.csdn.net/m0_51961114/article/details/124217986) ~ (*初级*)


[作文以记之 ~ 打开转盘锁](https://blog.csdn.net/m0_51961114/article/details/124260198) (*中等*)


本篇题目 (*困难*)


# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/f5281271d2e649f0b2bbd3909bd4ff74.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 利用BFS
### 2.1.1 思路
这块附上本题的官方题解，上面讲的挺清晰的，有需要者直接 [点击此处](https://leetcode-cn.com/problems/word-ladder/solution/dan-ci-jie-long-by-leetcode-solution/) 进行查看！

自己的理解呢，我写在了纸上，字有些难看，看不清楚就直接看官方题解，其中做题思路如下
![在这里插入图片描述](https://img-blog.csdnimg.cn/7ad88e6ddaf2402e900aa8ceb1535b99.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_19,color_FFFFFF,t_70,g_se,x_16)
对应的实现过程，如下图
![在这里插入图片描述](https://img-blog.csdnimg.cn/4c98dcc4a6b44abda317cbe8a226413a.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_18,color_FFFFFF,t_70,g_se,x_16)
### 2.1.2 实现代码

	class Solution {
	public:
		unordered_map<string, int> wordId;
		vector<vector<int>> edge;
		int nodeNum = 0;
	
		void addWord(string& word) {
			if (!wordId.count(word)) {
				wordId[word] = nodeNum++;
				edge.emplace_back();
			}
		}
	
		void addEdge(string& word) {
			addWord(word);
			int id1 = wordId[word];
			for (char& it : word) {
				char tmp = it;
				it = '*';
				addWord(word);
				int id2 = wordId[word];
				edge[id1].push_back(id2);
				edge[id2].push_back(id1);
				it = tmp;
			}
		}
	
	 	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
			for (string& word : wordList) {
				addEdge(word);
			}
			addEdge(beginWord);
			if (!wordId.count(endWord)) {
				return 0;
			}
			vector<int> dis(nodeNum, INT_MAX);
			int beginId = wordId[beginWord], endId = wordId[endWord];
			dis[beginId] = 0;
	
			queue<int> que;
			que.push(beginId);
			while (!que.empty()) {
				int x = que.front();
				que.pop();
				if (x == endId) {
					return dis[endId] / 2 + 1;
				}
				for (int& it : edge[x]) {
					if (dis[it] == INT_MAX) {
						dis[it] = dis[x] + 1;
						que.push(it);
					}
				}
			}
			return 0;
		}
	};

## 2.2 方法2 ~ 利用双向BFS
### 2.2.1 思路
根据给定字典构造的图可能会很大，而广度优先搜索的搜索空间大小依赖于每层节点的分支数量。假如每个节点的分支数量相同，搜索空间会随着层数的增长指数级的增加。考虑一个简单的二叉树，每一层都是满二叉树的扩展，节点的数量会以 2 为底数呈指数增长。

如果使用两个同时进行的广搜可以有效地减少搜索空间。一边从 `beginWord` 开始，另一边从 `endWord` 开始。我们每次从两边各扩展一层节点，当发现某一时刻两边都访问过同一顶点时就停止搜索。这就是双向广度优先搜索，它可以可观地减少搜索空间大小，从而提高代码运行效率。

*以上思路来源于 [力扣官方题解](https://leetcode-cn.com/problems/word-ladder/solution/dan-ci-jie-long-by-leetcode-solution/)*

### 2.2.2 程序代码


	class Solution {
	public:
		unordered_map<string, int> wordId;
		vector<vector<int>> edge;
		int nodeNum = 0;
	
		void addWord(string& word) {
			if (!wordId.count(word)) {
				wordId[word] = nodeNum++;
				edge.emplace_back();
			}
		}
	
		void addEdge(string& word) {
			addWord(word);
			int id1 = wordId[word];
			for (char& it : word) {
				char tmp = it;
				it = '*';
				addWord(word);
				int id2 = wordId[word];
				edge[id1].push_back(id2);
				edge[id2].push_back(id1);
				it = tmp;
			}
		}
	
		/* 双边BFS */
		int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
			for (string& word : wordList) {
				addEdge(word);
			}
			addEdge(beginWord);
			if (!wordId.count(endWord)) {
				return 0;
			}
	
			int beginId = wordId[beginWord], endId = wordId[endWord];
	
			vector<int> disBegin(nodeNum, INT_MAX);
			disBegin[beginId] = 0;
			queue<int> queBegin;
			queBegin.push(beginId);
	
			vector<int> disEnd(nodeNum, INT_MAX);
			disEnd[endId] = 0;
			queue<int> queEnd;
			queEnd.push(endId);
	
			while (!queBegin.empty() && !queEnd.empty())
			{
				/*从beginWord开始顺流而下*/
				int queBeginSize = queBegin.size();
				while(queBeginSize)
				{
					int tmp = queBegin.front();
					queBegin.pop();
					if (disEnd[tmp] != INT_MAX)
						return (disBegin[tmp] + disEnd[tmp]) / 2 + 1;
					for (int& it : edge[tmp])
					{
						if (disBegin[it] == INT_MAX)
						{
							queBegin.push(it);
							disBegin[it] = disBegin[tmp] + 1;
						}
					}
					queBeginSize--;
				}
	
				/*从endWord开始逆流而上*/
				int queEndSize = queEnd.size();
				while (queEndSize)
				{
					int tmp2 = queEnd.front();
					queEnd.pop();
					if (disBegin[tmp2] != INT_MAX)
						return (disBegin[tmp2] + disEnd[tmp2]) / 2 + 1;
					for (int& it2 : edge[tmp2])
					{
						if (disEnd[it2] == INT_MAX)
						{
							queEnd.push(it2);
							disEnd[it2] = disEnd[tmp2] + 1;
						}
					}
					queEndSize--;
				}
			}
			return 0;	
		}
	};


*侵权删~*