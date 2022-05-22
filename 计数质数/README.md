作文以记之 ~ 计数质数
=
# 0、前言
本篇博客是力扣上 [204. 计数质数](https://leetcode.cn/problems/count-primes/) 题的题解，挺简单的，就是想写个博客！

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124915392) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/9a8cea1cc1974d3fbf8ef82a68a57cc4.png)


# 2、解题思路
## 2.1 方法1 ~ 暴力解法
### 2.1.1 思路
这个思路就是直接对范围内的每个数进行判断，检验其是否满足质数要求。

该方法实现简单，但在此题中会超出时间限制~
### 2.1.2 程序代码


	class Solution {
	public:
	    int isTrue(int x)
	    {
	        for(int j=2;j*j<=x;j++)
	        {
	            if(x%j == 0)
	                return 0;
	        }
	        return 1;
	    }
	
	    int countPrimes(int n) {
	        int ans = 0;
	        for(int i=2;i<n;i++)
	            ans+=isTrue(i);
	        return ans;
	    }
	};

## 2.2 方法2 ~ 利用埃氏筛
### 2.2.1 思路
此处思路主要是利用了一种简单的筛法，具体内容可自己上网查资料！或者可直接查看[官方题解](https://leetcode.cn/problems/count-primes/solution/ji-shu-zhi-shu-by-leetcode-solution/)！
### 2.1.2 程序代码


	class Solution {
	public:
	    int countPrimes(int n) {
	        vector<int> flag(n,1);
	        int ans = 0;
	        for(int i=2;i<n;i++)
	        {
	            if(flag[i])
	                ans++;
	            if((long long)i*i < n)
	            {
	                for(int j = i*i; j<n;j+=i)//满足倍数的去掉
	                    flag[j] = 0;
	            }
	        }
	        return ans;
	    }
	};

