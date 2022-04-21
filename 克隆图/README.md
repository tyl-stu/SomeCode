作文以记之 ~ 克隆图
=
# 0、前言
本题是力扣上 [133. 克隆图](https://leetcode-cn.com/problems/clone-graph/) 题的题解，这个题是 BFS 和 DFS的例题，挺有意思的，虽然一开始看题的描述没怎么看懂~

相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124309183) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/13b5cca3e82541b8b813d3d12a35057c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
具体描述可点击前言中的链接进行查看！
# 2、解题思路
## 2.1 方法1 ~ 利用BFS
### 2.1.1 思路
**利用BFS** 做题的一个特点就是，需要有一个保存已被访问数据的容器，常用的如哈希表，还需有一个保存当前条件下满足要求的数据的容器，常用的如队列。基于此，该题的利用`BFS`的思路可如下：

1. 使用一个哈希表 `visited` 存储所有已被访问和克隆的节点。此题中的哈希表的 `key` 是原始图中的节点，`value` 是克隆图中的对应节点。
2. 将题目中未在`visited`出现过的节点添加到队列，同时克隆该节点并存储到哈希表中。
3. 每次从队列首部取出一个节点，遍历该节点的所有邻接点。如果`visited`中有这个邻接点，即该邻接点已被访问，则从 `visited` 获得该邻接点，否则创建一个新的节点存储在 `visited` 中，并将邻接点添加到队列，以便后续查找。然后将克隆的邻接点添加到克隆图对应节点的邻接表中。重复上述操作直到队列为空，则整个图遍历结束。

### 2.1.2 程序代码

	class Solution {
	public:
	    unordered_map<Node*, Node*> visited;
	    Node* cloneGraph(Node* node) {
	        if (node == nullptr) {
	            return node;
	        }
	        visited[node] = new Node(node->val);
	        queue<Node*> que;
	        que.push(node);
	        while(!que.empty())
	        {
	            Node *n = que.front();
	            que.pop();
	            for(auto& nei:n->neighbors)
	            {
	                if(!visited.count(nei))
	                {
	                    visited[nei] = new Node(nei->val);
	                    que.push(nei);
	                }
	                //n代表了原图中的节点，visited[n]代表了克隆图中的节点
	                visited[n]->neighbors.push_back(visited[nei]);
	            }
	        }
	        return visited[node];
	    }
	};

## 2.2 方法2 ~ 利用 DFS
### 2.2.1 思路
此处的思路和上述方法1中的思路相近，只不过采用了递归，这也是`DFS`的特点。具体思路是，设定一个哈希表`visited`表示已被访问和克隆的节点，当其中没有目标点的邻接点时，则创建节点并将其存入`visited`中，如果有，则直接返回该节点作为克隆图对应节点的邻接点。然后重复上述步骤，直至节点遍历结束！
### 2.2.2 程序代码


	class Solution {
	public:
	    unordered_map<Node*, Node*> visited;
	    Node* cloneGraph(Node* node) {
	        if(node == nullptr)
	            return node;
	        if(visited.count(node))
	            return visited[node];
	        Node* newNode = new Node(node->val);
	        visited[node] = newNode;
	        for(auto& n:node->neighbors)
	        {
	            newNode->neighbors.push_back(cloneGraph(n));
	        }
	        return newNode;
	    }
	};

