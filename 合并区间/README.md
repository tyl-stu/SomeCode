作文以记之 ~ 合并区间
=
# 0、前言
本篇博客是一个题解，具体题目可 [点击此处](https://leetcode-cn.com/problems/merge-intervals/) 进行查看！相关博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123902715) 进行查看！

这个题是一个中等难度，做起来挺快乐的，就是对我而言时间成本有点高，害！正文开始！

# 1、题目描述
有关题目描述就自己看图片吧
![在这里插入图片描述](https://img-blog.csdnimg.cn/5a345375430445d28e76c271c51b489d.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解决思路
## 2.1 排序 + 最大值
### 2.1.1 思路
简单说就是先将目标数组数据进行排序，再对排序后的数组设定两个初值，比如start、end，其中start是寻找满足要求的区间的左值，end是寻找满足要求的右值，通过与目标区间的左右值进行比较来确定start与end，即比如若end处于目标区间的范围内，则将该区间的右值赋给end，直至当end小于一个区间的左值，然后将其插入到指定数组中即可。具体可见于代码！
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	#include<algorithm>
	
	void shownums(vector<vector<int>>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			int j = 0;
			cout << "[";
			for (; j < nums[0].size()-1; j++)
			{
				cout << nums[i][j] << " ";
			}
			cout << nums[i][j] << "] ";
		}cout << endl;
	}
	
	vector<vector<int>> merge(vector<vector<int>>& intervals) 
	{
		int n = intervals.size();
		if (n <= 1)
			return intervals;
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		int start = intervals[0][0], end = intervals[0][1];
		int i;
		for (i = 1; i < intervals.size(); i++)
		{
			if (intervals[i][0] > end)
			{
				ans.push_back({ start, end });
				start = intervals[i][0], end = intervals[i][1];
				
			}
			else if (intervals[i][1] >= end)
			{
				end = intervals[i][1];
			}
		}
		if (i == n)
			ans.push_back({ start, end });
		return ans;
	}
	
	void test()
	{
		/*vector<vector<int>> nums = { { 1, 3 }, { 2, 4 }, { 3, 6 }, {7,8} };*/
		vector<vector<int>> nums = { { 0, 3 }, { 0, 1 }, { 0, 2 }, { 1, 9 }, { 2, 5 }, { 10, 11 }, { 12, 20 }, { 19, 20 } };
		cout << "原数组：";
		shownums(nums); cout << endl;
		cout << "处理后：";
		shownums(merge(nums)); cout << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/30dd45ae2f034466a6c48c295d886a69.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 其他方法
若后续有时间或者有想法，则补充其他方法！
# 3、总结
本次这个题难度还行，只不过我浪费了好些时间，但最终还是解决了它，希望后面遇到同类型的题能有更快更好的解决思路或方法！