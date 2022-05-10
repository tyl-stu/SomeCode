作文以记之 ~ 有效的字母异位词
=
# 0、前言
这是力扣上 [242. 有效的字母异位词](https://leetcode.cn/problems/valid-anagram/) 题的题解，题目简单，写博客主要是因为我自己在coding时一开始的方法有点复杂，用了两次循环，然后看了另外一种方法，只用了一次循环，觉得挺有意思的，故而在此记录~

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124695865) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/5ba8d93cf2484f28a0c2bdd8beac1298.png)

# 2、解题思路
## 2.1 方法1 ~ 两次循环
### 2.1.1 思路
这个思路主要是先通过一次循环对字符串`s`中的字母进行统计，再用一次循环判断字符串`t`中对应字母个数是否与`s`中的一致！
### 2.1.2 程序代码


	class Solution {
	public:
	    bool isAnagram(string s, string t) {
	        int len1 = s.size(),len2 = t.size();
	        if(len1 != len2) //若两字符串的长度不同，则铁定不符合要求
	            return false;
	        int nums[26] = {0};
	        for(int i = 0;i<len1;i++)
	            nums[s[i]-'a']++;
	        for(int i = 0;i<len2;i++)
	        {
	            nums[t[i]-'a']--;
	            if(nums[t[i]-'a'] < 0) 
	                return false;
	        }
	        return true;
	    }
	};

## 2.2 方法2 ~ 一次循环
### 2.2.1 思路
这个方法就是我一开始没想到的方法，只不过是在`方法1` 的基础上添加了一个整型变量，然后在字符串一次循环中，根据要求对该变量进行`+1/-1`，循环结束后，若变量为`0`，则说明满足题目要求！
### 2.2.2 程序代码


	class Solution {
	public:
	    bool isAnagram(string s, string t) {
	        int len1 = s.size(),len2 = t.size();
	        if(len1 != len2)
	            return false;
	        int n = 0;
	        int nums[26] = {0};
	        for(int i=0;i<len1;i++)
	        {
	            if(++nums[s[i]-'a'] == 1)
	                n++;
	            if(--nums[t[i]-'a'] == 0)
	                n--;
	        }
	        return n == 0;
	    }
	};

## 2.3 其他方法
这个题挺简单的，还有很多其他做法，比如先排序后判断是否相等，利用哈希表等，此处就不再赘述，后续有时间再补充~