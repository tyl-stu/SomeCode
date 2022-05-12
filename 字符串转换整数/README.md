作文以记之 ~ 字符串转换整数 _atoi
=
# 0、前言
这是力扣上 [8. 字符串转换整数 (atoi)](https://leetcode.cn/problems/string-to-integer-atoi/) 题的题解，力扣上标的难度为中等，但其中还是有简单的实现办法。而本博客将记录作者的一个题解~

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124735378) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/8bb7a619c1da427eafdc18cf4fc783e5.png)


# 2、解题思路
## 2.1 方法1 ~ 暴力解法
### 2.1.1 思路
直接对目标字符串的内容进行遍历，根据条件判断所遍历到的元素是否满足要求，若满足要求则返回最终的数值，否则返回0~
### 2.1.2 程序代码


	class Solution {
	public:
		int myAtoi(string s)
		{
			int start = 0, n = s.size(), flag = 0;// start -- 遍历索引，n--字符串元素个数，flag -- 数字的符号位
			while (s[start] < '0' || s[start] > '9' && start < n)
			{
				if (s[start] == '-' && flag == 0)
					flag = -1;
				else if (s[start] == '+' && flag == 0)
					flag = 1;
				else if (flag != 0) //防止出现其他的 + / -
					return 0;
				if (s[start] == '-' || s[start] == '+' || s[start] == ' ')
				{
					start++;
				}
				else
					return 0;
			}
			flag = flag == 0 ? 1 : flag;//判断flag的值，若不为0，则说明已确定符号位，若为0，则说明字符串中没出现+/-，即flag需设为1
			long ans = 0;//设为长整型，是为了防止数字越界
			while (start < n && s[start] >= '0' && s[start] <= '9')
			{
				ans = ans * 10 + s[start] - '0';
				if (ans > INT_MAX)
					return flag == 1 ? INT_MAX : INT_MIN;//当越界后根据符号位返回最大或最小值
				start++;
			}
			ans *= flag;//最后乘符号位
			return (int)ans;//将长整型强转为整型
		}
	};

## 2.2 其他方法
这个题挺有意思的，还有其他做法，比如官方题解中的自动机等，此处就不再赘述，后续有时间再补充~
