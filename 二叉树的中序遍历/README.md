作文以记之 ~ 二叉树的中序遍历
=
# 0、前言
本篇博客是力扣上 [94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/) 题的题解，题目简单，写博客主要是因为它也可以作为DFS的例题~

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124323488) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/c35955d4ecda4159b809a18e33d44d51.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 递归
### 2.1.1 思路
二叉树的中序遍历是按照访问 左子树 -- 根节点 -- 右子树 的方式遍历目标树，而在访问左子树或者右子树的时候可按照同样的方式遍历，直到遍历完整棵树。结合这种方式可直接使用递归！
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
	    void inorder(TreeNode* root, vector<int>& ans)
	    {
	        if(!root)
	            return;
	        inorder(root->left,ans);
	        ans.push_back(root->val);
	        inorder(root->right,ans);
	    }
	    vector<int> inorderTraversal(TreeNode* root) {
	        vector<int> ans;
	        inorder(root,ans);
	        return ans;
	    }
	};

## 2.2 方法2 ~ DFS
### 2.2.1 思路
这个思路呢，是基于力扣上所给 [DFS 模板2](https://leetcode-cn.com/leetbook/read/queue-stack/g2g9c/) 的内容编写的。虽然感觉更像是迭代，害！

而此处的思路相当于是将方法1的思路展开，从隐式栈转成了显式栈，其他都相同，具体实现可以看下面的代码。

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
	    vector<int> inorderTraversal(TreeNode* root) {
	        stack<TreeNode*> st;
	        vector<int> vec;
	        TreeNode* cur = root;
	        while(cur || !st.empty())
	        {
	            while(cur)
	            {
	                st.push(cur);
	                cur = cur->left;
	            }
	            cur = st.top();
	            vec.push_back(cur->val);
	            st.pop();
	            cur = cur->right;
	            
	        }
	        return vec;
	    }
	};

