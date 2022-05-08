作文以记之 ~ 寻找重复数
=
# 0、前言
这是力扣上 [287. 寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/) 的题解。这个题怎么说呢，有简单方法，但如果按照题目要求来做的话，这个题就很有意思！然后写此博客记录一下

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124645629) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/4387a62a59e74303a6af1b0f982058d8.png)

# 2、解题思路
## 2.1 方法1 ~ 利用二分法
### 2.1.1 思路
这个题是力扣上二分法专项训练的一个练习题，但自己一开始没有思路，最后看的官方题解才懂的。所以这块就直接附上官方题解的解释吧！
![在这里插入图片描述](https://img-blog.csdnimg.cn/c2e0e16962a04f1285b1ebc88dc6e646.png)
*注：上述题解来源于[力扣官方](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode-solution/)*

### 2.1.2 程序代码


	class Solution {
	public:
		/*利用二分法*/
		int findDuplicate(vector<int>& nums) {
			int start = 1, end = nums.size() - 1;
			int ans;
			while (start <= end)
			{
				int n = 0;//统计当前数组元素下满足要求的个数
				int mid = (end - start) / 2 + start;
				for (int i = 0; i<nums.size(); i++)
					n += nums[i] <= mid;
				if (n <= mid)
					start = mid + 1;
				else
				{
					end = mid - 1;
					ans = mid;
				}
			}
			return ans;
		}
		/*利用普通迭代  -- 这种会超出时间*/
		//int findDuplicate(vector<int>& nums) {
		//	int start = 1, end = nums.size() - 1;
		//	int ans;
		//	while (start <= end)
		//	{
		//		int n = 0;//统计当前数组元素下满足要求的个数
		//		//int mid = (end - start) / 2 + start;
		//		for (int i = 0; i<nums.size(); i++)
		//			n += nums[i] <= start;
		//		if (n <= start)
		//			start++;
		//		else
		//		{
		//			ans = start;
		//			break;
		//		}
		//	}
		//	return ans;
		//}
	};


## 2.2 方法2 ~ 利用快慢指针
### 2.2.1 思路
这种方法主要是利用了环形链表的相关理论，因为这个题换个角度来看就是环形链表。而针对环形链表的操作，则可以利用快慢指针进行解决。

在本题中，首先需要通过快慢指针找出环形链表中任一点的位置，然后利用快慢指针去找出环形链表的起始点，具体代码如下
### 2.2.2 程序代码

	class Solution {
	public:
		int findDuplicate(vector<int>& nums) {
			int slow = 0, fast = 0;
			// 先找出环形链表中的任一点
			do {
				slow = nums[slow];
				fast = nums[nums[fast]];
			} while (slow != fast);
			slow = 0;
			// 找出环形链表的起始点
			while (slow != fast) {
				slow = nums[slow];
				fast = nums[fast];
			}
			return slow;
		}
	};


## 2.3 其他方法
这个题解法确实很多，比如官方题解中的 利用数的比特位进行操作、利用哈希表等等，有兴趣的话可以再深入研究一下~

*注：以上一些解释和代码来源于[力扣官方题解](https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode-solution/)，侵权删~*