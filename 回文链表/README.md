作文以记之 ~ 回文链表
=
# 0、前言
本篇博客是力扣上 [234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/) 题的题解，题目不难，写一下博客记录一下自己解题的方法！

相关博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124198808) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/96393fd2d3ef416496c23fca121146fb.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 利用快慢指针+翻转前半链表
### 2.1.1 思路
此种思路，即通过快指针`fast`遍历出链表的结尾，同时利用`prev`以及`next`得出链表中 翻转部分 与 未翻转部分 的头节点，然后对比两个子链表对应位置的数据。但由于链表的长度可为奇数也可为偶数，直接利用上述来操作偶数位长度链表时没有问题，但操作奇数位时会导致`next`的链表相较于`prev`的链表多一位，因此设置了一个变量`flag`，用来对奇数位长度的链表进行操作。

这种思路有一个缺陷，就是会导致原链表发生变化，所以如果有可能的话，需先对原链表备份再进行操作！

### 2.1.2 程序代码


	/**
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     ListNode *next;
	 *     ListNode() : val(0), next(nullptr) {}
	 *     ListNode(int x) : val(x), next(nullptr) {}
	 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
	 * };
	 */
	class Solution {
	public:
	    bool isPalindrome(ListNode* head) {
	        
	        ListNode* prev =nullptr;//将链表进行翻转的头节点
	        ListNode* fast = head;//快指针，用于找出链表的末尾
	        ListNode* next = head;//链表中未翻转部分的头节点
	        int flag = 1;
	        while(fast->next)
	        {
	            if(fast->next->next == nullptr)
	            {
	                flag = 0;
	                fast = fast->next;
	            }
	            else
	                fast = fast->next->next;
	            ListNode* cur = next;
	            next = next->next;
	            cur->next = prev;
	            prev = cur;
	
	        }
	        if(flag == 1)//当链表为奇数位时flag=1,如此prev所指的前半链表会比next指向的后半链表少一位，因此需对next进行一次右移
	        {
	            next = next->next;
	        }
	        while(prev != nullptr)
	        {
	            if(prev->val != next->val)
	                return false;
	            prev = prev->next;
	            next = next->next;
	        }
	        return true;
	    }
	};


## 2.2 其他方法
这个题还有其他做法，比如直接将链表的值保存至一个数组里，再进行判断，挺容易实现的；还可将原链表全部翻转，然后进行对比，也不难实现；也可用其他方法，将链表的前半部分的数据和后半部分的数据分开，然后比较也可以。方法较多，后续有时间再补充！

*侵权删~*