@[TOC](作文以记之 ~ 验证二叉搜索树)
# 0、前言
本篇博客是力扣上 [98. 验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/) 题的题解，也是一个 DFS 的练习题，只要按照DFS的逻辑来，整个coding过程不难，挺有意思的~

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124845656) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/f2936f317213471f81f325cefd6079de.png)

# 2、解题思路
## 2.1 方法1 ~ 利用DFS
### 2.1.1 思路
只要所给二叉树不满足以下条件，则不为二叉搜索树，故而可以按照以下条件设置合理判断即可！
如果该二叉树的左子树不为空，则左子树上所有节点的值均小于它的根节点的值； 若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值；它的左右子树也为二叉搜索树。

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
	    bool isValidTree(TreeNode* root, long minval, long maxval)
	    {
	        if(root == nullptr)
	            return true;
	        if(root->val >= maxval || root->val <= minval)
	            return false;
	        return isValidTree(root->left,minval,root->val) && isValidTree(root->right,root->val,maxval);
	    }
	    bool isValidBST(TreeNode* root) {
	        return isValidTree(root,LONG_MIN,LONG_MAX);
	    }
	};

## 2.2 方法2 ~ 利用迭代
### 2.2.1 思路
此处思路就是将上面方法的递归给展开实现，具体看代码吧
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
	    bool isValidBST(TreeNode* root) {
	        stack<TreeNode*> st;
	        long minval = LONG_MIN;
	        while(!st.empty() || root != nullptr)
	        {
	            while(root)
	            {
	                st.push(root);
	                root = root->left;
	            }
	            root = st.top();
	            st.pop();
	            if(root->val <= minval)
	                return false;
	            minval = root->val;
	            root = root->right;
	        }
	        return true;
	    }
	};

