作文以记之 ~ 丢失的数字
=
# 0、前言
本篇博客是力扣上 [268. 丢失的数字](https://leetcode.cn/problems/missing-number/) 题的题解，很简单的一个题，写博客主要是想记载看到的一个有意思的解法！

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/125100233) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/b9a84db93662475eb2efb901870f082e.png)



# 2、解题思路
## 2.1 方法1 ~ 排序
### 2.1.1 思路
先排序，然后找少的那个数！
### 2.1.2 程序代码


	class Solution {
	public:
	    int missingNumber(vector<int>& nums) {
	        sort(nums.begin(),nums.end());
	        for(int i=0;i<nums.size();i++)
	        {
	            if(i!=nums[i])
	                return i;
	        }
	        return nums.size();
	    }
	};

## 2.2 方法2 ~ 异或
### 2.2.1 思路
利用异或，即将所给的数组和`[0,n+1]`相异或，相同为0，相异为一，找出少的那个数！
### 2.1.2 程序代码


	class Solution {
	public:
	    int missingNumber(vector<int>& nums) {
	        int res = 0;
	        for(int i=0;i<nums.size();i++)
	            res^=nums[i]^i;
	        return res^nums.size();
	    }
	};

