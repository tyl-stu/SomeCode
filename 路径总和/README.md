
作文以记之 ~  路径总和
=
# 0、前言
本篇博客是力扣上 [112. 路径总和](https://leetcode-cn.com/problems/path-sum/) 题的题解，题目简单，写博客主要是因为它也可以作为`BFS`和`DFS`的例题~

相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124444432) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/e8c6f8cdad5e41d28bb1262262c696ff.png)

# 2、解题思路
## 2.1 方法1 ~ BFS
### 2.1.1 思路
此种思路即是从根节点开始记录到每层节点的路径和，当路径和满足要求时，则返回`true`，反之则返回`false`。但为了方便比较，又因为是`BFS`，所以使用两个队列，分别存储将要遍历的节点，以及根节点到这些节点的路径和，具体代码如下。

但此种利用两个队列的方法，可以替换成哈希表，直接利用哈希表将节点和对应的路径和进行对应保存，此处就不再写此代码，有兴趣可以下去自己编写！

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
	    bool hasPathSum(TreeNode* root, int targetSum) {
	        if(!root) return false;
	        queue<TreeNode*> que_node;que_node.push(root);
	        queue<int> que_val;que_val.push(root->val);
	        while(!que_node.empty())
	        {
	            TreeNode* cur = que_node.front();
	            que_node.pop();
	            int val = que_val.front();
	            que_val.pop();
	            if(cur->left == nullptr && cur->right == nullptr)
	            {
	                if(val == targetSum)
	                    return true;
	                continue;//为了遍历完当前队列中的节点
	            }
	            if(cur->left != nullptr) 
	            {
	                que_node.push(cur->left);
	                que_val.push(val+cur->left->val);
	            }
	            if(cur->right != nullptr)
	            {
	                que_node.push(cur->right);
	                que_val.push(val+cur->right->val);
	            }
	        }
	        return false;
	    }
	};

## 2.2 方法2 ~ DFS
### 2.2.1 思路

本题是让判断从根节点到叶子节点的所有路径中，有没有那条路径上节点的和等于`targetSum`。

此可以从根节点开始遍历每一条支路上的节点，遍历的时候减去当前节点的值，如果减到最后，值等于叶子节点的值，说明存在满足题目要求的结果，直接返回`true`，否则就返回`false`。

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
	    bool isTrue(TreeNode* root,int obj)
	    {
	        if(!root)
	            return false;
	        if(!root->left && !root->right && root->val==obj) 
	            return true;
	        return isTrue(root->left,obj-root->val) || isTrue(root->right,obj-root->val);
	    }
	    bool hasPathSum(TreeNode* root, int targetSum) {
	        return isTrue(root,targetSum);
	    }
	};

