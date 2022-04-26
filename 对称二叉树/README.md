
作文以记之 ~  对称二叉树
=
# 0、前言
本篇博客是力扣上 [101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/) 题的题解，题目简单，写博客主要是因为它也可以作为`BFS`和`DFS`的例题~

相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124420078) 进行查看！


# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/1f9cf0029b9d4d3c984174c10f1cec86.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ BFS
### 2.1.1 思路
此种思路即是先将二叉树对称位置的两个节点插入队列`que`中，即给定一个初始值，然后从`que`中将其取出，并判断是否满足要求，若满足要求则将下一层节点插入`que`中，方便下一次的遍历，同时将遍历过的节点从`que`中删除掉，直至遍历结束！
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
	    bool isTrue(TreeNode* left,TreeNode* right)
	    {
	        queue<TreeNode*> que;
	        que.push(left);que.push(right);
	        while(!que.empty())
	        {
	            left = que.front(); que.pop();
	            right = que.front(); que.pop();
	            if(!left && !right) continue;
	            if(!left || !right || left->val != right->val) return false;
	            que.push(left->left);que.push(right->right);
	            que.push(left->right);que.push(right->left);
	        }
	        return true;
	    }
	    bool isSymmetric(TreeNode* root) {
	        return isTrue(root,root);
	    }
	};

## 2.2 方法2 ~ DFS
### 2.2.1 思路

根据本题意思可有，若二叉树中对称位置的两个节点同时为空则为 `true`，两个节点其中一个为空`false` ；
两个节点相等的情况下， 左节点的左子树等于右节点的右子树 且 左节点的右子树等于右节点的左子树，则满足对称返回`true`。

因此可利用`DFS`的方法，或者说是递归来计算二叉树的最大深度。


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
	    bool isSymmetric(TreeNode* root) {
	        return isTrue(root,root);
	    }
	    bool isTrue(TreeNode* r1,TreeNode* r2)
	    {
	        if(r1 == nullptr && r2 == nullptr) return true;
	        if(r1 == nullptr || r2 == nullptr) return false;
	        return r1->val == r2->val && isTrue(r1->right,r2->left) && isTrue(r1->left,r2->right);
	    }
	};

