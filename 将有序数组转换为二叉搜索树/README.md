作文以记之 ~ 将有序数组转换为二叉搜索树
=
# 0、前言
本篇博客是力扣上 [108. 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/) 题的题解，也是一个 DFS 的练习题，只要按照DFS的逻辑来，整个coding过程不难，挺有意思的~

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124865230) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/765ce7bd29ce45ec8d1ea2a973b50cb3.png)

# 2、解题思路
## 2.1 方法1 ~ 利用DFS
### 2.1.1 思路
此处的一个最简单的思路即，由于题目所给数组是升序数组，故而可以直接通过递归，每次递归都以当前所给数组的中间数作为当前树的根节点，直至将题目所给数组遍历结束即可！

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
	    TreeNode* sortedArrayToBST(vector<int>& nums) {
	        return createTree(nums,0,nums.size()-1);
	    }
	    TreeNode* createTree(vector<int>& nums, int start, int end)
	    {
	        if(start > end)
	            return nullptr;
	        int mid = start+(end-start)/2;
	        TreeNode* root = new TreeNode(nums[mid]);
	        root->left = createTree(nums,start,mid-1);
	        root->right = createTree(nums,mid+1,end);
	        return root;
	    }
	};

## 2.2 其他方法
此题还可使用中序遍历等方式去进行实现，后续有时间则继续补充！
