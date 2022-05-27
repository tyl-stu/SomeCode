作文以记之 ~ 汉明距离
=
# 0、前言
本篇博客是力扣上 [461. 汉明距离](https://leetcode.cn/problems/hamming-distance/) 题的题解，很简单的一个题，写博客主要是因为~就是想写！

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/125011607) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/a8bf775e08fb439e9f3669dbb19dca15.png)


# 2、解题思路
## 2.1 方法1 ~ 异或
### 2.1.1 思路
一个简单思路就是先将所给的两个数进行异或，再求解结果中1的个数即可。其中求1的个数可参考 [作文以记之 ~ 位1的个数](https://blog.csdn.net/m0_51961114/article/details/124974767) 中的内容！
### 2.1.2 程序代码


	class Solution {
	public:
	    int hammingDistance(int x, int y) {
	        int res = x^y;
	        int num = 0;
	        while(res!=0)
	        {
	            if(res&1)
	                num++;
	            res = res>>1;
	        }
	        return num;
	    }
	};


## 2.2 其他方法
此题简单，有多种解法，除了上述的之外，还可通过调用API或直接求两个数1的个数等方法去进行求解，有机会再补充！
