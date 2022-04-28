@[TOC](作文以记之 ~ 寻找旋转排序数组中的最小值2)
# 0、前言
这是一篇题解，具体题目描述可 [点击此处](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/) 进行查看！c此题与 [作文以记之 ~ 寻找旋转排序数组中的最小值](https://blog.csdn.net/m0_51961114/article/details/123968509) 这篇博客中的题极为相似，只不过所给示例中出现了重复的值。

写此博客没有其他想法，就是想记录一下
相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124485167?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22124485167%22%2C%22source%22%3A%22m0_51961114%22%7D&ctrtid=X3sxL) 进行查看！


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


## 2.2 方法2 ~ 利用二分法
### 2.2.1 思路
这种方法就是利用正常的二分查找，然后逐步去寻找最小值，但需要注意的是，此题需要增添一个对重复值的判断，关于这一点，最简单的就是将遇到重复值的位置也就是`end`进行左移，直至遇不到重复值。这种方法可以找到数组的最小值，但无法用其准确的找到最大值！
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
	class Solution {
	public:
	    int findMin(vector<int>& nums) {
	        int start=0,end=nums.size()-1;
	        while(start<end)
	        {
	            int mid = start+(end-start)/2;
	            if(nums[mid] < nums[end])
	                end = mid;
	            else if(nums[mid] > nums[end])
	                start = mid+1;
	            else
	                end--;
	        }
	        return nums[start];
	    }
	};
	/*方法2 利用二分法*/
	int findMin(vector<int>& nums)
	{
		int start=0,end=nums.size()-1;
	    while(start<end)
	    {
	        int mid = start+(end-start)/2;
	        if(nums[mid] < nums[end])
	            end = mid;
	        else if(nums[mid] > nums[end])
	            start = mid+1;
	        else //遇到相同的值则左移
	            end--;
	    }
	    return nums[start];
	}
	
	void test()
	{
		//原数组为：0,1,2,3,4,5,6,7
		vector<int> nums = { 2, 2, 2, 2, 0, 2 };
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


# 3、总结
此题不难，有简单的解法，也有比较有意思的做法。但个人建议，做题时候不要单纯的使用`API`，虽然使用`API`爽，一直使用一直爽，但对程序编码思维没有太大帮助！