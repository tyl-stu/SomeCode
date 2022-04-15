作文以记之 ~ 相交链表
=
# 0、前言
此篇博客是力扣上 [160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) 题目的题解，题目不难，写这篇博客是为了记录一下官方题解中给出的精彩答案！

相关博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124170214) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/41f1a8a8151e4be49377542c8788df0b.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 简单利用双指针
### 2.1.1 思路
解决这个题采用了一个取巧的方式，即先求出两个链表各自的长度`lenA、lenB`，再以最短的链长为基准，将较长链表的节点遍历至其自身第`（max(lenA,lenB)-min(lenA,LenB)）`个节点。

此时，该链表与另一链表同时开始遍历，找寻相同节点！

### 2.1.2 程序代码


	/**
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     ListNode *next;
	 *     ListNode(int x) : val(x), next(NULL) {}
	 * };
	 */
	class Solution {
	public:
	    int ComputeLen(ListNode* head)
	    {
	        int len = 0;
	        while(head)
	        {
	            len++;
	            head=head->next;
	        }
	        return len;
	    }
	    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	        int lenA = ComputeLen(headA);
	        int lenB = ComputeLen(headB);
	        ListNode* nextA = headA;
	        ListNode* nextB = headB;
	        if(lenA > lenB)
	        {
	            int tmp = lenA-lenB;
	            while(tmp)
	            {
	                nextA = nextA->next;
	                tmp--;
	            }
	        }
	        else
	        {
	            int tmp = lenB-lenA;
	            while(tmp)
	            {
	                nextB = nextB->next;
	                tmp--;
	            }
	        }
	        int mid = min(lenA,lenB);
	        while(mid)
	        {
	            if(nextA == nextB)
	                return nextA;
	            nextA=nextA->next;
	            nextB=nextB->next;
	            mid--;
	        }
	        return NULL;
	    }
	};



## 2.2 方法2 ~ 利用双指针
### 2.2.1 思路
![在这里插入图片描述](https://img-blog.csdnimg.cn/8368a882b454492e95e6ee94afd6f1d7.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

注：此处思路来源于官方题解中的一个思路，具体可 [点击此处](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode-solutio-a8jn/) 进行查看！

### 2.2.2 程序代码


	/**
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     ListNode *next;
	 *     ListNode(int x) : val(x), next(NULL) {}
	 * };
	 */
	class Solution {
	public:
	    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	        if(headA==nullptr||headB==nullptr) return NULL;
	        ListNode* s1 = headA,*s2=headB;
	        while(s1 != s2)
	        {
	            s1 = s1 == nullptr? headB:s1->next;
	            s2 = s2 == nullptr? headA:s2->next;
	        }
	        return s1;
	    }
	};

## 2.3 其他方法
关于该题还有其他方法，比如哈希表，但觉得太简单了，此处就不配代码了。后面若有其他想法，再补充吧！