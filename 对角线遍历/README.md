作文以记之 ~ 对角线遍历
=
# 0、前言
本篇博客是记载作者在做题时的题解，程序有复杂有简洁。具体题目可 [点击此处](https://leetcode-cn.com/problems/diagonal-traverse/) 进行查看！相关博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123927280) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/94fdd3977fbb4ed6a4b003cca0d1c699.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 2、解题思路
## 2.1 方法1 ~ 以对角线个数为主
### 2.1.1 思路
该思路是以对角线个数为主进行循环，其中设置`index`代指第几条对角线。以此判断当前对角线属于向右下方向（`index`为奇数）或者是向左上方向（`index`为偶数），然后设定合适的元素坐标初始值，通过遍历，将对角线上对应的数据插入指定数组中！

结合下图很容易发现，在偶数对角线（红色线条所指）情况下，除了边界元素，其他元素满足 `i--,j++`的规律；在奇数对角线（蓝色线条所指）下，除了边界元素，其他元素满足 `i++,j--`的规律。而对于边界元素，可根据矩阵的行列以及`index`来进行坐标的确定。然后便可以此编写代码！
![在这里插入图片描述](https://img-blog.csdnimg.cn/61ce0be5ff194df79a5b5e81f113132c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	
	using namespace std;
	
	void shownums(vector<vector<int>>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums[0].size(); j++)
				cout << nums[i][j] << " ";
			cout << "\n";
		}cout << endl;
	}
	
	void shownums2(vector<int>& nums)
	{
		for (int &d : nums)
			cout << d << " ";
		cout << endl;
	}
	
	/* 方法1 -- 利用对角线的个数 */
	vector<int> findDiagonalOrder(vector<vector<int>>& mat)
	{
		int index = 0;//代表次数
		int m = mat.size();
		int n = mat[0].size();
		int i, j;//代表元素的横纵坐标
		int tmp;//中间值
		vector<int> ans;
		while (index < (m + n))
		{
			if (index % 2 == 0)
			{
				i = index, j = 0;
				if (index >= m)//设定边界元素
				{
					i = mat.size() - 1;
					j = index - i;
				}
				tmp = (index > (n - 1)) ? n : (index + 1);
				while (j < tmp)
				{
					ans.push_back(mat[i][j]);
					i--; j++;
				}
			}
			else if (index % 2 == 1)
			{
				i = 0, j = index;
				if (index >= n)
				{
					j = mat[0].size() - 1;
					i = index - j;
				}
				tmp = (index > (m - 1)) ? m : (index + 1);
				while (i < tmp)
				{
					ans.push_back(mat[i][j]);
					i++; j--;
				}
			}
			index++;
		}
		return ans;
	}
	
	void test()
	{
		vector<vector<int>> nums = {
				{ 0, 1, 2, 3, 4 },
				{ 5, 6, 7, 8, 9 },
				{ 10, 11, 12, 13, 14 } };
		/*vector<vector<int>> nums = {
				{ 1,2},
				{3,4}};*/
		cout << "\n原数组：\n"; shownums(nums);
		cout << "\n按对角线遍历后的结果：\n";
		shownums2(findDiagonalOrder(nums));
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/8783ccf80d9f4778ab7cf20f404dd58c.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 方法2 ~ 以数据个数为主
### 2.2.1 思路
此种方法的思路是判断数据元素的横纵坐标之和是为偶数或奇数，然后结合2.1.1中的图，可推导出对应规律，我不想用话去描述，有需要者可以自己根据上面的图再结合下面的程序自己推导，或者[点击此处](https://leetcode-cn.com/problems/diagonal-traverse/solution/dui-jiao-xian-bian-li-zhao-gui-lu-by-tra-9owb/)进行查看！
### 2.2.2 程序代码


	#include<iostream>
	#include<vector>
	
	using namespace std;
	
	void shownums(vector<vector<int>>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums[0].size(); j++)
				cout << nums[i][j] << " ";
			cout << "\n";
		}cout << endl;
	}
	
	void shownums2(vector<int>& nums)
	{
		for (int &d : nums)
			cout << d << " ";
		cout << endl;
	}
	
	/* 方法2 -- 利用元素的个数 */
	vector<int> findDiagonalOrder(vector<vector<int>>& mat)
	{
		int x = 0, y = 0;//横纵坐标
		int n = mat[0].size(), m = mat.size();
		vector<int> ans;
		for (int i = 0; i < n*m; i++)
		{
			ans.push_back(mat[x][y]);
			if ((x + y) % 2 == 0)
			{
				if (y == n - 1) ++x;
				else if (x == 0) ++y;
				else --x, ++y;
			}
			else
			{
				if (x == m - 1) ++y; 
				else if (y == 0) ++x;
				else ++x, --y;
			}
		}
		return ans;
	}
	
	void test()
	{
		vector<vector<int>> nums = {
				{ 0, 1, 2, 3, 4 },
				{ 5, 6, 7, 8, 9 },
				{ 10, 11, 12, 13, 14 } };
		/*vector<vector<int>> nums = {
				{ 1,2},
				{3,4}};*/
		cout << "\n原数组：\n"; shownums(nums);
		cout << "\n按对角线遍历后的结果：\n";
		shownums2(findDiagonalOrder(nums));
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/881335b8941049cbb51e0534bc8a5536.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
上述两种方法，第一个是一开始想到的，程序有点冗杂，没有进行优化，第二个方法起始和第一个差不多，只不过是在边界元素的处理上有些许差别，更简洁，也比较推荐！加油吧~