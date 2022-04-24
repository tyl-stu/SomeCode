作文以记之 ~ 二叉树的层序遍历
=
# 0、前言
本篇博客是力扣上 [102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/) 题的题解，也是一个 BFS 的练习题，只要按照BFS的逻辑来，整个coding过程不难，挺有意思的~

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124355643) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/b010b01a96524853826003ef7680b4f6.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 利用BFS
### 2.1.1 思路
简单来说，从二叉树的根节点开始，先将同一层的节点存入合适的队列`que`中，然后边通过遍历`que`中的节点保存每个节点的值，边`pop`掉已保存过的节点，同时将下一层的节点存入`que`中。重复以上工作，直至遍历完整个二叉树！

注意：关于本题BFS的讲解，推荐一个大佬的题解，有需要者可[点击此处](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/bfs-de-shi-yong-chang-jing-zong-jie-ceng-xu-bian-l/)进行查看！
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
	    vector<vector<int>> levelOrder(TreeNode* root) {
	        vector<vector<int>> ans;
	        queue<TreeNode*> que;
	        if(root) que.push(root);
	        while(!que.empty())
	        {
	            vector<int> tmp;
	            int size = que.size();
	            while(size--)//遍历同一层的所有节点
	            {
	                TreeNode* cur = que.front();
	                que.pop();
	                tmp.push_back(cur->val);
					//插入当前节点的下一层节点
	                if(cur->left)
	                    que.push(cur->left);
	                if(cur->right)
	                    que.push(cur->right);
	            }
	            ans.push_back(tmp);
	        }
	        return ans;
	    }
	};

## 2.2 其他方法
该题还有其他方法，比如贪心算法，或者利用堆等。后续有时间有精力再补充！