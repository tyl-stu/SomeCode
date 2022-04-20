作文以记之 ~ 每日温度
=
# 0、前言
本篇博客是力扣上 [739. 每日温度](https://leetcode-cn.com/problems/daily-temperatures/) 题的题解，题目难度不高，有点意思，只不过在coding过程中有点小问题！

相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124286040) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/0f3270aab7cd4c56b166df1aba538153.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 2、解题思路
## 2.1 方法1~暴力求解
### 2.1.1 思路
这个方法就是从目标数组中的第一个数开始，将其与其后面的元素进行对比，找出第一个比他大的数的下标差即可。

这种方法实现起来挺简单的，但问题在于我下面的程序在有些案例会显示超时~
所以需要换方法！
### 2.1.2 程序代码

	class Solution {
	public:
	    vector<int> dailyTemperatures(vector<int>& temperatures) {
	        vector<int> ans(temperatures.size());
	        for(int i=0;i<temperatures.size()-1;i++)
	        {
	            for(int j=i+1;j<temperatures.size();j++)
	            {
	                if(temperatures[j]>temperatures[i])
	                {
	                    ans[i] = j-i;
	                    break;
	                }
	            }
	        }
	        return ans;
	    }
	};

## 2.2 方法2 ~ 利用单调栈
### 2.2.1 思路
正向遍历目标数组，对于其中的每个元素 `temperatures[i]`，如果栈`st`为空，则直接将 `i` 进栈，如果栈不为空，则比较栈顶元素 `st.top()` 对应的温度 `temperatures[st.top()]` 和当前温度 `temperatures[i]`的大小，如果 `temperatures[i] > temperatures[st.top()]`，则将栈顶元素对应的等待天数赋为 `i - st.top()`，并将栈顶元素出栈。重复上述操作直到栈为空或者栈顶元素对应的温度小于等于当前温度。

其实这个题目我一开始想到了用栈，但我想的是栈里保存温度值，而不是保存温度值对应的下标，这导致我一开始coding出了点问题~
但总归来说，这个题有点开拓人眼界的效果，挺有意思的~

### 2.2.2 程序代码


	class Solution {
	public:
	    vector<int> dailyTemperatures(vector<int>& temperatures) {
	        vector<int> ans(temperatures.size());
	        stack<int> st;
	        for(int i=0;i<temperatures.size();i++)
	        {
	            while(!st.empty() && temperatures[st.top()] < temperatures[i])
	            {
	                ans[st.top()] = i-st.top();
	                st.pop();
	            }
	            st.push(i);
	        }
	        return ans;
	    }
	};


