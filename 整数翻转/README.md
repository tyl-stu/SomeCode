作文以记之 ~ 整数翻转
=
# 0、前言
这是力扣上 [7. 整数反转](https://leetcode.cn/problems/reverse-integer/) 的题解，力扣中难度为中等。

写此博客没有其他想法，就是想记录一下自己在`coding`时的一些问题~

相关博客内容可 点击此处 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/4febf61a4a984deab0b68cf2a974bcd0.png)


# 2、解题思路
## 2.1 方法1 ~ 数学方法
### 2.1.1 思路
这个思路简单来说就是，通过循环，每次把目标数字的最后一位变成答案数字的最后一位，直至遍历结束！

只不过需要注意的是，此处要防止越界问题！！！
### 2.1.2 程序代码


	class Solution {
	public:
	    int reverse(int x) {
	        int tmp = x;//对目标数字备份，防止原数据发生变化
	        long ans=0;//最终要输出的变量，只不过为了防止int型出界，所以才定义为long型
	        while(tmp)
	        {
	            ans= ans*10+tmp%10;//将目标数字的最后一位变为答案数字的最后一位
	            tmp = tmp/10;
	        }
	        return (int)ans == ans ? (int)ans : 0;//此处判断了ans是否越界，未越界直接输出ans的int型，出界则返回0
	    }
	};


## 2.2 其他方法
此题还有其他方法，比如利用栈、队列、位运算等，后续有时间再补充！