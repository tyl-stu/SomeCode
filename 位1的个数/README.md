作文以记之 ~ 位1的个数
=
# 0、前言
本篇博客是力扣上 [191. 位1的个数](https://leetcode.cn/problems/number-of-1-bits/) 题的题解，很简单的一个题，写博客主要是督促自己保持每天写的习惯！

博客具体内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124974767) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/36c10b03001243f0a43b4902a7a9929a.png)


# 2、解题思路
## 2.1 方法1 ~ 循环求解
### 2.1.1 思路
题目中已经限定了二进制串的位数为32位，故而可通过循环32次来寻找目标串中1的个数！
### 2.1.2 程序代码


	class Solution {
	public:
	    int hammingWeight(uint32_t n) {
	        int ans = 0;
	        for (int i = 0; i < 32; i++) {
	            ans += n&1;
	            n=n>>1;
	        }
	        return ans;
	    }
	};

这个代码其实可换一种写法，如下

	class Solution {
	public:
	    int hammingWeight(uint32_t n) {
	        int ans = 0;
	        while(n!=0)
	        {
	            ans += n&1;
	            n=n>>1;
	        }
	        return ans;
	    }
	};

这个更简洁一些！