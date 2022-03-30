作文以记之~两个数组的交集
=
本篇博客依然是一题解，题目可 [点击此处](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/) 进行查看！相关博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123833720) 进行查看！

而写这篇文章的主要原因是感觉自己大脑有点固化，不太灵通，然后便将做题过程中的感触记录一下！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/7991c9b03b2e45998aff2b0c0ee3f376.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、做题思路
## 2.1 利用map
### 2.1.1 思路
遇到这种数组题，我的第一想法就是直接利用map、unordered_map以及其他哈希结构进行求解，这种方法虽然简单，但有点上瘾，以至于用习惯后就不想其他方法了。

而利用`map`的**主要思路**是：将两个数组中的一个数组以其各元素作为键值存入`map`中，并随该数组中数据的出现频次从0开始计数。当这个数组中的所有数保存结束后，便用另一个数组的元素值作为键值，在上述`map`中进行查找，若可查到，则将该数存入需要输出的数组中，同时将该数对应`map`中的次数减1，若次数为0，则尽管可查到，但也不可存入答案数组，然后遍历其他数，直至结束！

### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	#include<map>
	using namespace std;
	
	/*两个数组的交集 https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2y0c2/ */
	
	void shownums(vector<int> &nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/*方法1*/
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		map<int, int> m1;//存储nums1
		vector<int> ans;
		for (int &d : nums1)
			m1[d]++;
		for (int &i : nums2)
		{
			if (m1[i] > 0)
			{
				ans.push_back(i);
				--m1[i];
			}
		}
		return ans;
	}
	
	void test()
	{
		vector<int> nums1 = { 4, 9, 5 };
		vector<int> nums2 = { 9, 4, 9, 8, 4 };
		cout << "nums1: "; shownums(nums1);
		cout << "nums2: "; shownums(nums2);cout  << endl;
	
		vector<int> ans = intersect(nums1, nums2);
		cout << "两数组的交集："; shownums(ans); cout << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}


### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/dabc280b10114d0d96f42aceac83ac3f.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)


## 2.2 利用双指针
### 2.2.1 思路
该方法比上述方法的性能更高一些，且易实现！

**思路**为：首先将两个数组进行同方向排序，比如从左至右由小到大，然后设置两个指针，各自从两个数组的第一个元素开始，依次比较与另一个数组指针指向元素的大小，若小于则本数组指针后移；若大于则另一个数组指针后移；若等于则将该数存至答案数组中，并使两个数组的指针都后移，直至其中一个或两个数组的元素遍历结束！

### 2.2.2 程序代码

	#include<iostream>
	#include<vector>
	#include<map>
	#include<algorithm>
	using namespace std;
	
	/*两个数组的交集 https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2y0c2/ */
	
	void shownums(vector<int> &nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/*方法2  利用双指针*/
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> ans;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int index1 = 0;
		int index2 = 0;
		while (index1<nums1.size() && index2<nums2.size())
		{
			if (nums1[index1]<nums2[index2])
				index1++;
			else if (nums1[index1]>nums2[index2])
				index2++;
			else
			{
				ans.push_back(nums1[index1]);
				index2++;
				index1++;
			}
		}
		return ans;
	}
	
	void test()
	{
		vector<int> nums1 = { 4, 9, 5 };
		vector<int> nums2 = { 9, 4, 9, 8, 4 };
		cout << "nums1: "; shownums(nums1);
		cout << "nums2: "; shownums(nums2);cout  << endl;
	
		vector<int> ans = intersect(nums1, nums2);
		cout << "两数组的交集："; shownums(ans); cout << endl << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}


### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/e1eb5cefe6524b5aaaaf256560444748.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
写这篇文章的主要目的并不是主要说明文中题目的求解方法，而是想记录一下当时自己做题时的所思所想或者感触！就是觉得自己做题多少有点偷懒，能调用函数就调用函数，这让自己想想有点羞愧，整天想着捷径！

害，加油吧！