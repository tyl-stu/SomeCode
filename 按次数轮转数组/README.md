作文以记之 ~ 轮转数组
=
**注**：本篇博客的题目来源于[力扣习题](https://leetcode-cn.com/problems/rotate-array/submissions/)！
其他内容可点击 [同款博客](https://blog.csdn.net/m0_51961114/article/details/123807492?spm=1001.2014.3001.5502) 进行查看！
# 0、前言
写本篇博客主要是想记录一下刷上述算法题时的一些感触！
上述算法题不难，但做该题中途还是出现了或多或少的问题。先贴上题目描述：
![在这里插入图片描述](https://img-blog.csdnimg.cn/4b2f76b76a92442aba2a130786e78369.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 1、实现方法
此处将对实现该题的方法进行记录说明，而目前所实现的方法可分为 **超时方法** 和 **合格方法**！下面按点叙述！

## 1.1 超时方法
### 1.1.1 调用库函数
此方法主要是调用 `vector` 相关的库函数进行操作，方法思路都很简单，堪称暴力，但如此虽然结果是达到了题目要求，但其运行超时。

**思路**：根据提供的轮转次数`k`，调用`vector`类函数依序将 数组最后的元素 插入 数组的起始位置，并删除原有的数组最后的元素。

具体代码如下：

	#include<iostream>
	#include<vector>
	#include<stack>
	
	using namespace std;
	
	void display(vector<int> &v)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
	}
	
	void rotate(vector<int>& nums, int k) {
		/* 方法1 -- 超时 */
		while (k--)
		{
			nums.insert(nums.begin(), nums[nums.size() - 1]);
			nums.pop_back();
			cout << "现数组：";
			display(nums);
		}
	}
	
	void test()
	{
		// 插入数据
		vector<int> nums;
		for (int i = 1; i < 8; i++)
			nums.push_back(i);
		cout << "原数组：";
		display(nums);
	
		rotate(nums, 3);
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}


### 1.1.2 暴力遍历
**思路**：根据提供的轮转次数`k`，利用遍历，将原数组中前 `nums.size() - k` 个元素依序后移，同时将数组后 `k` 个元素依序前移。

此方法比第一个方法更暴力，不推荐，如果不计成本的话，倒可以使用！

具体代码如下：


	#include<iostream>
	#include<vector>
	#include<stack>
	
	using namespace std;
	
	void display(vector<int> &v)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
	}
	
	void rotate(vector<int>& nums, int k) {
		/* 方法2  -- 超时 */
		int tmp;
		int n = nums.size() - 1;
		while (k--)
		{
			tmp = nums[n];
			while (n > 0)
			{
				nums[n] = nums[n - 1];
				n--;
			}
			nums[0] = tmp;
			n = nums.size() - 1;
			cout << "现数组：";
			display(nums);
		}
	}
	
	void test()
	{
		// 插入数据
		vector<int> nums;
		for (int i = 1; i < 8; i++)
			nums.push_back(i);
		cout << "原数组：";
		display(nums);
	
		rotate(nums, 3);
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

## 1.2 合格算法
此处所说算法即为可满足题目要求的算法，将对其进行具体描述！

### 1.2.1 利用新的数组
![在这里插入图片描述](https://img-blog.csdnimg.cn/1b85bb3222444e78914793b21300af1a.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
上图中说明了轮转前后索引的变化规律，所以只要利用新旧数组的索引就可实现轮转前后元素的对应，然后再利用`vector`自带的函数`assign()`，便可将数组实现轮转！

具体代码如下：


	#include<iostream>
	#include<vector>
	#include<stack>
	
	using namespace std;
	
	void display(vector<int> &v)
	{
		for (int i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		cout << endl;
	}
	
	void rotate(vector<int>& nums, int k) {
		/* 方法三 -- 用新的数组进行操作 */
		vector<int> newArr(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			newArr[(i + k) % nums.size()] = nums[i];
		}
		nums.assign(newArr.begin(), newArr.end());
		cout << "\n现数组：";
		display(nums);
	}
	
	void test()
	{
		// 插入数据
		vector<int> nums;
		for (int i = 1; i < 8; i++)
			nums.push_back(i);
		cout << "\n原数组：";
		display(nums);
	
		rotate(nums, 3);
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

运行结果：<br>
![在这里插入图片描述](https://img-blog.csdnimg.cn/a61ce73012664382b617cae86d56925d.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
### 1.2.2 基于数组本身
具体思路如图
![在这里插入图片描述](https://img-blog.csdnimg.cn/b914dacff8e74c0aba09cb7cc477b696.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
![在这里插入图片描述](https://img-blog.csdnimg.cn/719fcadf8a9545ac8e1c575f11c10f8c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
代码如下：
	
	
	#include<iostream>
	#include<vector>
	#include<stack>
	
	using namespace std;
	
	void display(vector<int> &v)
	{
		for (int i = 0; i < v.size(); i++)
			std::cout << v[i] << " ";
		cout << endl;
	}
	
	void reverse(vector<int>& nums, int start, int end)
	{
		while (start < end)
		{
			swap(nums[start], nums[end]);
			start++;
			end--;
		}
	}
	
	void rotate(vector<int>& nums, int k) {
			/*方法四 -- 在原数组上进行操作*/
		k %= nums.size();
		if (k != 0)
		{
			//下述两种皆可实现目标
			//先小部分翻转，再大部分翻转
			/*reverse(nums, 0, nums.size() - k - 1);
			reverse(nums, nums.size() - k, nums.size() - 1);
			reverse(nums, 0, nums.size() - 1);*/
			//先大部分翻转，再小部分翻转
			reverse(nums, 0, nums.size() - 1);
			reverse(nums, 0, k - 1);
			reverse(nums, k, nums.size() - 1);
		}
		cout << "\n现数组：";
		display(nums);
		cout << "\n"; 
	}
	
	void test()
	{
		// 插入数据
		vector<int> nums;
		for (int i = 1; i < 8; i++)
			nums.push_back(i);
		cout << "\n原数组：";
		display(nums);
	
		rotate(nums, 3);
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}
	
运行结果：
![在这里插入图片描述](https://img-blog.csdnimg.cn/c3c4eef1b7084ceca8240d5c0e012867.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
### 1.2.3 其他方法
后续复习时再补上其他算法！

# 2、总结
以后这种问题还需多多锻炼自己的思路，有时简单并不是最优，还需大脑多转转！加油吧！