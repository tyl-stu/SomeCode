作文以记之 ~ 目标和
=
# 0、前言
本篇博客是力扣上 [494. 目标和](https://leetcode-cn.com/problems/target-sum/) 题，题目难度中等，可以说是`DFS`的练习题，有点意思~

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124317987) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/5d4215594051439284f5a743260263c4.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
 
# 2、解题思路
## 2.1 方法1 ~ 利用 DFS
### 2.1.1 思路
数组nums 的每个元素都可以添加符号 + 或 -，因此每个元素有 2 种添加符号的方法，n 个数共有 2^n   种添加符号的方法。然后就可以给 n 个元素都添加符号之后，进行简单求和，如果结果等于目标数target，则该表达式即为符合要求的表达式。
### 2.1.2 程序代码


	class Solution {
	public:
		// DFS 写法1
		/*int findTargetSumWays(vector<int>& nums, int target) {
			return dfs(nums, target, 0);
		}
	
		int dfs(vector<int> &nums, int target, int left) {
			if (target == 0 && left == nums.size()) return 1;
			if (left >= nums.size()) return 0;
			int ans = 0;
			ans += dfs(nums, target - nums[left], left + 1);
			ans += dfs(nums, target + nums[left], left + 1);
			return ans;
		}*/
	
		// DFS 写法2
		int num = 0;
		int findTargetSumWays(vector<int>& nums, int target) {
			getNum(nums, target, 0, 0);
			return num;
		}
		void getNum(vector<int>& nums, int target, int index, int sum)
		{
			if (index == nums.size())
			{
				if (sum == target)
				{
					num++;
				}
			}
			else
			{
				getNum(nums, target, index + 1, sum + nums[index]);
				getNum(nums, target, index + 1, sum - nums[index]);
			}
		}
	};

## 2.2 其他方法
这个题还可以采用其他的方法，比如动归，后续有时间了继续补充！