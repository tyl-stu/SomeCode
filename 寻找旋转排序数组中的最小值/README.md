作文以记之 ~ 寻找旋转排序数组中的最小值
=
# 0、前言
这是一篇题解，具体题目描述可 [点击此处](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/) 进行查看！相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123968509) 进行查看！

刚开始做这个题时，以为是 [作文以记之 ~ 轮转数组](https://blog.csdn.net/m0_51961114/article/details/123807492?spm=1001.2014.3001.5501)  这篇博客中同类型的题，后面才发现并不是，只不过有些共同点。

没有其他想法，就是想记录一下
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/a5e36bf8d0ff4f7fa6d911594c65ec95.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 调用API
### 2.1.1 思路
因为这个题其实只是让找出数组中的最小值，所以最简单的方法就是先给数组排序，然后找出最小的数即可，这种可以直接调用`API`实现，如下面的程序！
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	#include<algorithm>
	
	void shownums(vector<int>& nums)
	{
		for (int& d : nums)
			cout << d << " ";
		cout << endl;
	}
	
	/* 方法1 ~ 调用API */
	int findMin(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		return nums[0];
	}
	
	void test()
	{
		//原数组为：0,1,2,3,4,5,6,7
		vector<int> nums = { 4, 5, 6, 7, 0, 1 };
		cout << "\n需处理的数组："; shownums(nums); cout << endl;
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		cout << "\n目标数组的原数组："; shownums(tmp); cout << endl;
		cout << "\n最小值：" << findMin(nums) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/b033ffd9bbe1488d8d2ac3a78664078b.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 方法2 ~ 利用二分法
### 2.2.1 思路
这种方法就是利用正常的二分查找，然后逐步去寻找最小值，但需要注意的是，这种方法可以找到数组的最小值，但无法用其准确的找到最大值！
### 2.2.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	#include<algorithm>
	
	void shownums(vector<int>& nums)
	{
		for (int& d : nums)
			cout << d << " ";
		cout << endl;
	}
	/*方法2 利用二分法*/
	int findMin(vector<int>& nums)
	{
		int start = 0, end = nums.size() - 1;
		while (start < end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] < nums[end])
				end = mid;
			else
				start = mid + 1;
		}
		return nums[start];
	}
	
	void test()
	{
		//原数组为：0,1,2,3,4,5,6,7
		vector<int> nums = { 4, 5, 6, 7, 0, 1 };
		cout << "\n需处理的数组："; shownums(nums); cout << endl;
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		cout << "\n目标数组的原数组："; shownums(tmp); cout << endl;
		cout << "\n最小值：" << findMin(nums) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/f9d47be85f674c95b4bccf9de2819798.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
此题不难，有简单的解法，也有比较有意思的做法。但个人建议，做题时候不要单纯的使用`API`，虽然使用`API`爽，一直使用一直爽，但对程序编码思维没有太大帮助！