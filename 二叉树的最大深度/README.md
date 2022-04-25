
作文以记之 ~  二叉树的最大深度
=
# 0、前言
本篇博客是力扣上 [104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/) 题的题解，题目简单，写博客主要是因为它也可以作为`BFS`和`DFS`的例题~

相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124405670) 进行查看！


# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/280dec8180a44e3a8636b4bb582ae6ef.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)


# 2、解题思路
## 2.1 方法1 ~ BFS
### 2.1.1 思路
此种思路即是先将二叉树的头节点插入队列que中，然后从que中取值，寻找目标节点下一层的可用节点并将其存入que中，同时将遍历过的节点从que中删除掉，直至遍历结束！
### 2.1.2 程序代码


	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
	 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	 * };
	 */
	class Solution {
	public:
	    int maxDepth(TreeNode* root) {
	        if(!root) return 0;
	        queue<TreeNode*> que;
	        que.push(root);
	        int len = 0;
	        while(!que.empty())
	        {
	            int size = que.size();
	            while(size--)
	            {
	                TreeNode* cur = que.front();
	                que.pop();
	                if(cur->left) que.push(cur->left);
	                if(cur->right) que.push(cur->right);
	            }
	            len++;
	        }
	        return len;
	    }
	};

## 2.2 方法2 ~ DFS
### 2.2.1 思路

本题所求的深度，即若左子树和右子树的最大深度 `l` 和 `r`，则该二叉树的最大深度即为 `max(l,r)+1` 。而左子树和右子树的最大深度又可以以同样的方式进行计算。因此可以用`DFS`的方法，或者说是递归来计算二叉树的最大深度。

具体而言，在计算当前二叉树的最大深度时，可以先递归计算出其左子树和右子树的最大深度，然后在 `O(1)` 时间内计算出当前二叉树的最大深度。递归在访问到空节点时退出。

### 2.2.2 程序代码


	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
	 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	 * };
	 */
	class Solution {
	public:
	    int maxDepth(TreeNode* root) {
	        if(!root) return 0;
	        return max(maxDepth(root->left),maxDepth(root->right))+1;
	    }
	};

