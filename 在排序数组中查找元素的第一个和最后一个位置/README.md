作文以记之 ~ 在排序数组中查找元素的第一个和最后一个位置
=
# 0、前言
本篇博客是一篇题解，其题目是力扣上的34题，具体可 [点击此处](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/) 进行查看！相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124057008) 进行查看！

这个题其实难度不高，只不过有点意外的是，因为这个题是力扣中二分法专项训练的模板3的例题，一开始还以为是练习模板3呢，结果自己实现后看官方题解，大多数都是模板2，对了，二分法的三个模板写法可点击 [作文以记之 ~ 二分法总结](https://blog.csdn.net/m0_51961114/article/details/124028325) 此博客进行查看，或者直接在力扣上搜二分法算法！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/cadcfbca359e4584b88875c4eca876ad.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 结合一部分的二分法
### 2.1.1 思路
这个方法的思路呢，主要是结合二分法找到数组中与 `target` 相符的数字，然后针对此数字的前后进行处理，找到该数字的首尾位置。因为目标数组是一个升序数组，所以也不用考虑目标数字在数组中是否随机存在。
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
	
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		int n = nums.size();
		if (n == 0) return{ -1, -1 };
		int start = 0, end = n - 1;
		vector<int> ans;
		while ((start + 1) < end)
		{
			int mid = start + (end - start) / 2;
			if (nums[mid] == target)
			{
				int left = mid, right = mid;
				while (0<=left && nums[left] == target) left--;
				while (right<= n-1 && nums[right] == target) right++;
				ans.push_back(left + 1);
				ans.push_back(right - 1);
				break;
			}
			else if (nums[mid] < target) start = mid;
			else end = mid;
		}
		if (nums[start] == target) ans.push_back(start);
		if (nums[end] == target) ans.push_back(end);
		if (ans.size() == 1) return{ ans[0], ans[0] };
		else if (ans.size() == 0) return { -1, -1 };
		else
		{
			sort(ans.begin(), ans.end());
			return{ ans[0], ans[ans.size() - 1] };
		}
	}
	
	void test()
	{
		/*vector<int> nums = { 1, 2, 1, 3, 5, 6, 4 };*/
		vector<int> nums = { 0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 5, 5};
		/*vector<int> nums = { 5, 7, 7, 8, 8, 10 };*/
		/*vector<int> nums = { 1};*/
		int target = 5;
		cout << "\n原数组："; shownums(nums); cout << endl;
		vector<int> ans = searchRange(nums,target);
		cout << "数组中" << target << "的起始和终止位置："<< ans[0]<<" " << ans[1] << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/d23a84dfdc9e4824b71b2c97c7dcdab9.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 其他方法
这个题不难，解决方法较多，比如调用`API`、直接遍历数组、还有就是以二分法找到的位置作为起始点，结合二分法向两边扩展等，后续如果有时间再补充或者完善其他方法！
# 3 、总结
没啥总结的，就是上述二分法用的不太好，还需再精进一些！