作文以记之 ~ 杨辉三角2
=
# 0、前言
本篇博客依然是题解，且此题相较于 [作文以记之~杨辉三角](https://blog.csdn.net/m0_51961114/article/details/123962284) 中的题目多了一些条件，但可基于该博客中的内容对本次这个题进行求解！具体题目可 [点击此处](https://leetcode-cn.com/problems/pascals-triangle-ii/) 进行查看！相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123965133) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/28bd8f7749b248c98f731e2303a219b7.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 先生成再输出
### 2.1.1 思路
这个思路就很简单，即先生成整体的杨辉三角，此处程序可在 [博客](https://blog.csdn.net/m0_51961114/article/details/123962284) 中进行查看，然后把目标行输出即可！
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	
	void shownums(vector<vector<int>>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums[i].size(); j++)
			{
				cout << nums[i][j] << " ";
			}cout << endl;
		}cout << endl;
	}
	
	void showrow(vector<int>& row)
	{
		for (int& d : row)
			cout << d << " ";
		cout << endl;
	} 
	
	/* 方法1 ~ 通过生成杨辉三角再输出 */
	vector<int> getRow(int rowIndex) 
	{
		rowIndex++;
		vector<vector<int>> ans;
		for (int i = 0; i < rowIndex; ++i)  
			ans.push_back(vector<int>(i+1,0));
		ans[0][0] = 1;
		for (int i = 1; i < rowIndex; i++)
		{
			ans[i][0] = 1; ans[i][i] = 1;
			for (int j = 1; j < i; j++)
			{
				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
		}
		return ans[rowIndex-1];
	}
	
	void test()
	{
		int n = 4;
		//cout << n << "的阶乘 = " << factorial(n) << endl;
		cout << "输入的行数：" << n << endl;
		cout << "\n生成的杨辉三角：\n";
		showrow(getRow(n)); cout << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/89d30f8dbee64e21bda4dfe0e15441fe.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 方法2 ~ 利用数学
### 2.2.1 思路
杨辉三角每行 数与数之间，行与行之间，都满足一定的数学规律，然后可以根据这些数学规律去编写代码，如此就可避免方法1中需要生成整个杨辉三角多余的工作了！具体的杨辉三角的规律，可 [点击此处](https://leetcode-cn.com/problems/pascals-triangle/solution/yang-hui-san-jiao-by-leetcode-solution-lew9/) 进行查看，说明的很详细！

下述代码中，一开始我是利用阶乘去求得每行中的数，但因为当行数比较大时，如此会越界，所以就利用了第二个写法，读者可根据自己需求，进行选择分析！
### 2.2.2 程序代码


	#include<iostream>
	#include<vector>
	using namespace std;
	
	void shownums(vector<vector<int>>& nums)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums[i].size(); j++)
			{
				cout << nums[i][j] << " ";
			}cout << endl;
		}cout << endl;
	}
	
	void showrow(vector<int>& row)
	{
		for (int& d : row)
			cout << d << " ";
		cout << endl;
	} 
	
	///* 方法2 ~ 利用数学方法 利用阶乘*/
	//int factorial(int x)
	//{
	//	if (x == 1)
	//		return 1;
	//	return x*factorial(x - 1);
	//}
	//vector<int> getRow(int rowIndex)
	//{
	//	vector<int> ans(rowIndex + 1);
	//	ans[0] = 1, ans[rowIndex] = 1;
	//	for (int i = 1; i < rowIndex; i++)
	//	{
	//		ans[i] = 1LL*factorial(rowIndex) / (factorial(i) * factorial(rowIndex - i));
	//	}
	//	return ans;
	//}
	
	/* 方法2 ~ 利用数学方法2*/
	vector<int> getRow(int rowIndex)
	{
		vector<int> ans(rowIndex + 1);
		ans[0] = 1;
		for (int i = 1; i <= rowIndex; i++)
		{
			ans[i] = 1LL * ans[i - 1] * (rowIndex - i + 1) / i;//1LL,LL其实代表long long，*1LL是为了在计算时，把int类型的变量转化为long long，然后再赋值给long long类型的变量
		}
		return ans;
	}
	
	void test()
	{
		int n = 4;
		//cout << n << "的阶乘 = " << factorial(n) << endl;
		cout << "输入的行数：" << n << endl;
		cout << "\n生成的杨辉三角：\n";
		showrow(getRow(n)); cout << endl;
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/ad1ccc4c09154c21b58f0433eff9b1eb.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
杨辉三角是一个很经典的规律模型，为了更好的理解学习，可根据一些代码进行分析，所以有需要者可做做对应的程序题，比如 [题1](https://leetcode-cn.com/problems/pascals-triangle/solution/yang-hui-san-jiao-by-leetcode-solution-lew9/) 、[题2](https://leetcode-cn.com/problems/pascals-triangle-ii/submissions/).