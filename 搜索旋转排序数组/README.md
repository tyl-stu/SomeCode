作文以记之 ~ 搜索旋转排序数组
=
# 0、前言
本篇是力扣上33题的题解，具体题目可 [点击此处](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/) 进行查看！相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124023658) 进行查看！

这个题主要是用于练习二分法，与力扣中 [153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/) 题有些类似，可以进行对比学习！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/6e6da9efe14149a3b4fd759f75354b8b.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 利用二分法
### 2.1.1 思路
这道题中，数组旋转前是有序的，但进行旋转后只保证了数组的局部是有序的，经过分析后可知：

在常规二分查找的时候查看当前 `mid` 为分割位置分割出来的两个部分 `[start, mid]` 和 `[mid + 1, end]` 哪个部分是有序的，并根据有序的那个部分确定二分查找的上下界，如此能够根据有序的那部分判断出 `target` 在不在这个部分。

- 如果 `[start, mid - 1]` 是有序数组，且 `target` 的大小满足`nums[start] <= target < nums[mid]`，则可将搜索范围缩小至 `[start, mid - 1]`，否则在 `[mid + 1, end]` 中寻找。
- 如果 `[mid, end]` 是有序数组，且 `target` 的大小满足`nums[mid+1] < target <= nums[end]`，则可将搜索范围缩小至 `[mid + 1,end]`，否则在 `[start, mid - 1]` 中寻找。
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	
	using namespace std;
	
	void shownums(vector<int>& nums)
	{
		for (int& d : nums)
			cout << d << " ";
		cout << endl;
	}
	
	int search(vector<int>& nums, int target)
	{
		int n = nums.size();
		if (n == 0) return -1;
		if (n == 1) return nums[0] == target ? 0 : -1;
		int start = 0, end = n - 1;
		while (start <= end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] == target) return mid;
			if (nums[0] <= nums[mid])//确定前半部分是否有序 -- 此时为 [0,mid]
			{
				if (nums[0] <= target && target < nums[mid])//确定是否存在于当前有序部分数组中，在则确定该部分的结尾end
					end = mid - 1;
				else//不在则确定下一部分的起始位置
					start = mid + 1;
			}
			else
			{
				if (nums[mid] < target && target <= nums[n - 1])
					start = mid + 1;
				else
					end = mid - 1;
			}
		}
		return -1;
	}
	
	void test()
	{
		vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
		int target = 1;
		cout << "\n原数组为："; shownums(nums); 
		cout << "要查找的值为：" << target << endl; cout << endl;
		cout << "目标数据所在的位置：" << search(nums, target) << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/3ec7056ee24e46788ee2b0bb78284392.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 其他方法
这个题还有其他方法，比如先根据目标数组的最大值确定数组中的有序部分，然后以这两个部分的首尾值判断目标数据所在那个范围，然后再去寻找具体的位置！此种方法实现不难，后续再补充吧！
# 3、总结
一开始以为的二分法，经过这几天的专项训练，我忽然发现我想得简单了，越学越觉得自己菜，害，加油吧！