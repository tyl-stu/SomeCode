作文以记之 ~ 两数之和
=
# 0、前言
此博客依然是一题解，具体题目可 [点击此处](https://leetcode-cn.com/problems/two-sum/) 进行查看！相关博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/123860585) 进行查看！该题依然不难，就是想写一下博客！
# 1、题目描述
简单说就是找出一个给定值在目标数组中的两个可进行求和得到的元素！
![在这里插入图片描述](https://img-blog.csdnimg.cn/3dd555a422ab42488d04e8c54eff109e.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解决思路
## 2.1 利用哈希表
### 2.1.1 思路
此处思路是将原数组元素作为哈希表的键值，如此只是为了方便找出对应的值！然后利用哈希表找寻对应的差值，具体就看下述代码！
### 2.1.2 程序代码


	#include<iostream>
	#include<vector>
	#include<unordered_map>
	#include<string>
	
	using namespace std;
	
	/* https://leetcode-cn.com/problems/two-sum/ */
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/* 方法1 利用哈希表 */
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		for (int i = 0; i<nums.size(); i++)
		{
			int tmp = target - nums[i];
			if (m.find(tmp) != m.end())
				return { m[tmp], i};
			m[nums[i]] = i;
		}
		return{};
	}
	
	void test()
	{
		vector<int> arr = { 1, 9, 9, 8 };
		cout << "\n原数组："; showarr(arr);
		cout << "指定值：" << 10 << endl;
		cout << "处理后："; showarr(twoSum(arr,10)); cout << endl;
		
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.1.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/6fe2b26a12374e45b5ea4635849eff08.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
## 2.2 暴力求解
### 2.2.1 思路
此处思路就是通过遍历，实现上述哈希表找值得操作。比较简单，很暴力！具体可见下述代码！
### 2.2.2 程序代码


	#include<iostream>
	#include<vector>
	#include<unordered_map>
	#include<string>
	
	using namespace std;
	
	/* https://leetcode-cn.com/problems/two-sum/ */
	
	void showarr(vector<int>& nums)
	{
		for (int &i : nums)
			cout << i << " ";
		cout << endl;
	}
	
	/* 方法2 循环遍历 */
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = 0; i<nums.size(); i++)
		{
			int tmp = target - nums[i];
			for (int j = i+1; j < nums.size(); j++)
			{
				if (nums[j] == tmp)
					return{ i, j };
			}
		}
		return{};
	}
	
	void test()
	{
		vector<int> arr = { 1, 9, 9, 8 };
		cout << "\n原数组："; showarr(arr);
		cout << "指定值：" << 10 << endl;
		cout << "处理后："; showarr(twoSum(arr,10)); cout << endl;
		
	}
	
	int main()
	{
		test();
		system("pause");
		return 0;
	}

### 2.2.3 运行结果
![在这里插入图片描述](https://img-blog.csdnimg.cn/df97a2bf96264cb6a24c8c2792987942.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
# 3、总结
没啥总结的，就是想写一个博客，希望能对别人有点帮助！