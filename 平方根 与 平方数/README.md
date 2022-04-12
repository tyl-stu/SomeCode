作文以记之 ~ 平方根 与 完全平方数
=
# 0、前言
本篇博客是对力扣上 [69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/) 和 [367. 有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/) 两个问题的题解。因为这两道题很相似，所以一起说明！相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124073372) 进行查看！
# 1、题目描述
## 1.1 x的平方根
此为 69. x 的平方根 的题目描述：
![在这里插入图片描述](https://img-blog.csdnimg.cn/cb9d7a8aa1c044ad9dbc677d1d3b9a1c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 1.2 有效的完全平方数
此为 367. 有效的完全平方数 的题目描述：
![在这里插入图片描述](https://img-blog.csdnimg.cn/9a505a46ae4b4740ba97e3e000b11952.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 x的平方根
### 2.1.1 方法1 ~ 普通解法
#### 2.1.1.1 思路
每次对目标数据进行减半，然后判断减半后的数据的平方与原有数据的大小，满足条件则返回对应平方根！
#### 2.1.1.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	
	/* 力扣上 69. x 的平方根 题的解法 https://leetcode-cn.com/problems/sqrtx/ */
	/*方法1 ~ 普通的解法*/
	int mySqrt(int x) 
	{
		if (x <= 1)  return x;
		int ans = x / 2;
		while (ans)
		{
			if ((x / ans) >= ans && (ans + 1)>(x / (ans + 1)))
				return ans;
			else if ((x / ans) < ans)
				ans /= 2;
			else if ((x / ans) > ans)
				ans++;
		}
		return -1;
	}
	
	void test()
	{
		int x = 9;
		cout << endl << x << "的平方根：" << mySqrt(x) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

#### 2.1.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/18324eee1ec444839744a3820fb9a0ee.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
### 2.1.2 方法2 ~ 二分法
#### 2.1.2.1 思路
此种思路中，将二分查找的下界设为 0，上界设定为 `x`。在二分查找的每一步中，比较中间元素`mid` 的平方与 `x` 的大小关系，并通过比较的结果调整上下界的范围。
#### 2.1.2.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	
	/* 力扣上 69. x 的平方根 题的解法 https://leetcode-cn.com/problems/sqrtx/ */
	/*方法2 ~ 利用二分法*/
	int mySqrt(int x) 
	{
		if (x <= 1) return x;
		int left = 0, right = x;
		int mid, ans;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (x / mid >= mid)
			{
				ans = mid;
				left = mid + 1;
			}
			else
				right = mid - 1;
		}
		return ans;
	}
	
	void test()
	{
		int x = 16;
		cout << endl << x << "的平方根：" << mySqrt(x) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

#### 2.1.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/e7166c825cf54de0bfecb62ef17c6d4a.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 有效的完全平方数
### 2.2.1 方法1 ~ 二分法
#### 2.2.1.1 思路
此思路和2.1.2.1中类似，也是通过二分法去判断数据的大与小，然后划分合适的范围并最终确定合适的数据！
#### 2.2.1.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	
	/* 力扣 367. 有效的完全平方数 的解法 https://leetcode-cn.com/problems/valid-perfect-square/ */
	/*方法1 二分法*/
	bool isPerfectSquare(int num) {
		int start = 0, end = num;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			long s = (long)mid*mid;
	
			if (s< num) start = mid + 1;
			else  if (s>num) end = mid - 1;
			else return true;
		}
		return false;
	}
	
	void test()
	{
		int x = 16;
		cout << endl << x << "的平方根：" << mySqrt(x) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

#### 2.2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/1640539f5ec9401cbcbc32925e8e274d.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
### 2.2.2 方法2 ~ 数学规律
#### 2.2.2.1 思路
这个思路是我在题解中看到的，具体可 [点击此处](https://leetcode-cn.com/problems/valid-perfect-square/solution/zhi-xing-yong-shi-0-ms-zai-suo-you-c-ti-jiao-zh-44/) 进行查看，真的是绝~

1 4=1+3 9=1+3+5 16=1+3+5+7以此类推，模仿它可以使用一个while循环，不断减去一个从1开始不断增大的奇数，若最终减成了0，说明是完全平方数，否则，不是。

**注**：此思路的来源如下：
*作者：lu-guo-de-feng-2
链接：https://leetcode-cn.com/problems/valid-perfect-square/solution/zhi-xing-yong-shi-0-ms-zai-suo-you-c-ti-jiao-zh-44/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*

#### 2.2.2.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	
	/* 力扣 367. 有效的完全平方数 的解法 https://leetcode-cn.com/problems/valid-perfect-square/ */
	/* 方法2 数学规律 https://leetcode-cn.com/problems/valid-perfect-square/solution/zhi-xing-yong-shi-0-ms-zai-suo-you-c-ti-jiao-zh-44/ */
	bool isPerfectSquare(int num) {
		int x = 1;
		while (num > 0)
		{
			num -= x;
			x += 2;
		}
		return num == 0;
	}
	
	void test()
	{
		int x = 25;
		cout << endl << x << "的平方根：" << mySqrt(x) << endl << endl;
		cout << x << "是否为完全平方数：" << boolalpha << isPerfectSquare(x) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

#### 2.2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/9056c44d3e534a42a637166036f8b5c7.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
这篇博客写了两个题，内容虽然有点多，但容易上手，特别是其中有些方法很惊艳，值得学习~

*侵权删~*