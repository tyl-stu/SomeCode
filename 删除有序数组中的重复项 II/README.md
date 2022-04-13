作文以记之 ~ 删除有序数组中的重复项 II
=
# 0、前言
本篇博客用于记载在做力扣上 [80. 删除有序数组中的重复项 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/) 题时的一些题解，很精彩，所以需要记录一下！相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124113130) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/eb9dff86b150469a87dbc523f75258fc.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法一 ~ 双指针
### 2.1.1 思路
这个方法是做这种题时的第一反应，结果一开始做这题的时候，忽然发现自己越做越复杂，最后查看题解后，忽然感觉自己真的是一个菜鸡！我在这说一下官方对这个题的题解：
![在这里插入图片描述](https://img-blog.csdnimg.cn/2a9d65a343414c54bb03599fad07ed50.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
*注：上述思路解释来源于力扣[官方题解](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/solution/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-yec2/)！*
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	
	void shownums(vector<int>& nums,int n)
	{
		for (int i = 0; i < n;i++)
			cout << nums[i] << " ";
		cout << endl;
	}
	
	/* 方法1 */
	int removeDuplicates(vector<int>& nums) 
	{
		int n = nums.size();
		if (n <= 2) {
			return n;
		}
		int slow = 2, fast = 2;
		while (fast < n) {
			if (nums[slow - 2] != nums[fast]) {
				nums[slow] = nums[fast];
				++slow;
			}
			++fast;
		}
		return slow;
	}
	
	void test()
	{
		vector<int> nums = { 0, 0, 1, 1, 1, 1, 2, 3, 3 };
		cout << "\n原数组："; shownums(nums, nums.size()); cout << endl << endl;
		cout << removeDuplicates(nums) << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

## 2.2 方法二 ~ 该类型题的通解
### 2.2.1 思路
这个方法依然是这个题下一题解，就觉得很优秀，害！
![在这里插入图片描述](https://img-blog.csdnimg.cn/99e5d4a40086445cb3b938eb2d63bb0d.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
注：此题解来源于 [【宫水三叶】关于「删除有序数组重复项」的通解](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/solution/gong-shui-san-xie-guan-yu-shan-chu-you-x-glnq/)！有需要者可点击查看！

### 2.2.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	
	void shownums(vector<int>& nums,int n)
	{
		for (int i = 0; i < n;i++)
			cout << nums[i] << " ";
		cout << endl;
	}
	
	/* 方法2 */
	int removeDuplicates(vector<int>& nums)
	{
		int len = 0;
		for (int &d : nums)//d是在遍历的，哪怕len不变，len也在变！！！
			if (len < 2 || nums[len - 2] != d)
				nums[len++] = d;
		return len;
	}
	
	void test()
	{
		vector<int> nums = { 0, 0, 1, 1, 1, 1, 2, 3, 3 };
		cout << "\n原数组："; shownums(nums, nums.size()); cout << endl << endl;
		cout << removeDuplicates(nums) << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

# 3、总结
上述两种方法可以说都来源于题目下面的题解，只不过因为觉得对自己有帮助，才在此进行记录，挺有意思的！

*侵权删~*