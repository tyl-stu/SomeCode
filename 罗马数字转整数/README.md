作文以记之 ~ 罗马数字转整数
=
# 0、前言
本篇博客是力扣上 [13. 罗马数字转整数](https://leetcode.cn/problems/roman-to-integer/) 题的题解，很简单的一个题，写博客主要是因为~就是想写！

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124955823) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/178e1e94ab29417997c6e5e16c5a235c.png)

# 2、解题思路
## 2.1 方法1 ~ 暴力解法
### 2.1.1 思路
先利用哈希表将罗马字与各自的数字对应起来，然后通过判断当前罗马字的数是否大于下一位罗马字的数，大于则当前罗马字的数的符号定为`1`，小于则定为 `-1` 。然后遍历 `s` ，根据上述方法进行数的求和。需要注意的是，遍历时不能越界！
### 2.1.2 程序代码


	class Solution {
	public:
	    int romanToInt(string s) {
	        unordered_map<char,int> obj;
	        obj.insert({{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}});
	        int ans = 0;
	        for(int i = 0;i<s.size();i++)
	        {
	            int flag = 1;
	            if((i+1)<s.size() && obj[s[i]] < obj[s[i+1]])
	                flag = -1;
	            ans += flag*obj[s[i]];
	        }
	        return ans;
	    }
	};


## 2.2 其他方法
此题简单，有多种解法，除了上述的之外，还可结合递归等方法去进行求解，有机会再补充！
