作文以记之 ~ 钥匙和房间
=
# 0、前言
本篇博客是力扣上 [841. 钥匙和房间](https://leetcode-cn.com/problems/keys-and-rooms/) 题的一篇题解，写下这篇博客原因是 此题是`BFS` 和  `DFS`两种算法的练习题！

相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124578662) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/a428784b5d3f49bc9f633844546ef53a.png)


# 2、解题思路
## 2.1 方法1 ~ 利用BFS
### 2.1.1 思路
这个题主要是判断 `rooms` 中可遍历到的钥匙是否能打开 `rooms` 中的所有房间，所以这个题的一个简单的实现步骤就是：
1. 设定初值。先定义一个哈希表 `ans`，根据房间数即 `rooms.size()` 去为 `ans`  每个值设初值 `0`，其中`0`代表未开门，`非0`则代表已开过 ；定义一个队列 `que`，保存遍历房间时满足要求的钥匙；

2. 从`0`房间开始遍历房中的钥匙，并将其存入 `que` 中，后续遍历时则从 `que` 中取钥匙即可；

3. 从 `que` 取钥匙的同时，还需根据 `ans` 中对应的值判断是否已经开过对应的门，开过则返回上层继续遍历，未开过则将该钥匙存入 `que` 中，并将 `ans` 中对应的值 `+1` ；

4. 运行结束后，遍历`ans`中的值，若有`0`则说明还有门未开，则返回 `false`，否则返回 `true`.


### 2.1.2 程序代码


	class Solution {
	public:
	    bool canVisitAllRooms(vector<vector<int>>& rooms) {
	        unordered_map<int,int> ans;
	        for(int i=0;i<rooms.size();i++)
	            ans[i] = 0;
	        queue<int> que;
	        que.push(0);
	        while(!que.empty())
	        {
	            int cur = que.front();
	            que.pop();
	            ans[cur]++;
	            for(int& d:rooms[cur])
	            {
	                if(ans[d] >= 1)
	                    continue;
	                que.push(d);
	            }
	                
	        }
	        for(int i=0;i<rooms.size();i++)
	            if(ans[i] == 0)
	                return false;
	        return true;
	    }
	};

此处再提供另一个写法，消耗资源少一些，但整体思路和上述相似~


	class Solution {
	public:
	    bool canVisitAllRooms(vector<vector<int>>& rooms) {
	        int n = rooms.size(), num = 0;
	        vector<int> ans(n);
	        queue<int> que;
	        ans[0] = 1;
	        que.push(0);
	        while (!que.empty()) {
	            int cur = que.front();
	            que.pop();
	            num++;
	            for (auto& d : rooms[cur]) {
	                if (!ans[d]) {
	                    ans[d]++;
	                    que.push(d);
	                }
	            }
	        }
	        return num == n;
	    }
	};



## 2.2 方法2 ~ 使用DFS
### 2.2.1 思路
与`2.1.1`中的思路大致相似，此处只不过是将迭代转为了递归，同样的解决思路，此处我就不再赘述了，因为我觉得有浪费口水的时间各位大佬应该都就看懂了~

### 2.2.2 程序代码


	class Solution {
	public:
	    int num;
	
	    void dfs(vector<vector<int>>& rooms,vector<int>& ans, int key)
	    {
	        ans[key] = 1;
	        num++;
	        for(int& d:rooms[key])
	        {
	            if(!ans[d])
	                dfs(rooms, ans, d);
	        }
	    }
	
	    bool canVisitAllRooms(vector<vector<int>>& rooms) {
	        int n = rooms.size();
	        num = 0;
	        vector<int> ans(n);
	        dfs(rooms,ans,0);
	        return num == n;
	    }
	};


