作文以记之 ~ 单词接龙
=
# 0、前言
这是一篇题解，题目是针对**广度优先搜索BFS**的练习题，挺有意思的。难度怎么说呢，可以说知道怎么做，也知道`BFS`的原理，可就是写不出代码，自己太菜了，所以下面的实现代码大多是对官方题解中的代码的阐述！

具体题目可 [点击此处](https://leetcode-cn.com/problems/word-ladder/) 进行查看！

相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124239143) 进行查看！

**注**：我写的博客里有关`BFS`的练习题还有一些，比如 [作文以记之 ~ 岛屿数量](https://blog.csdn.net/m0_51961114/article/details/124217986) ~


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
此种方法还在学习，等清楚再补充！

侵权删~