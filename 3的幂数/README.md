作文以记之 ~ 3的幂数
=
# 0、前言
本篇博客是力扣上 [326. 3 的幂](https://leetcode.cn/problems/power-of-three/) 题的题解，很简单的一个题，写博客主要是想记载看到的一个有意思的解法！

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124931220) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/19d601c159e04c008633aee14a0f04dd.png)


# 2、解题思路
## 2.1 方法1 ~ 暴力解法
### 2.1.1 思路
此思路即对目标数连续除3，直至最后判断是否为1，为1则为3的幂数！
### 2.1.2 程序代码


	class Solution {
	public:
	    bool isPowerOfThree(int n) {
	        while(n && n%3==0)
	            n/=3;
	        return n==1;
	    }
	};


## 2.2 方法2 ~ 判断约数
### 2.2.1 思路
这个方法就是想记录的一种较为取巧的做法。

即在有符号整数的范围内，最大的 `3` 的幂为 `3^19 = 1162261467`。然后只需要判断 目标数 是否是 上述数 的约数即可。
只不过需要判断 `n` 是负数或 `0` 的情况。
### 2.1.2 程序代码


	class Solution {
	public:
	    bool isPowerOfThree(int n) {
	        return n > 0 && 1162261467 % n == 0;
	    }
	};

