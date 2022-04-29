作文以记之 ~ 奇偶链表
=
# 0、前言
本题是力扣上 [328. 奇偶链表](https://leetcode-cn.com/problems/odd-even-linked-list/) 的题解，题目难度中等，在此记载一下自己的解题方法！

相关博客可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124183381) 进行查看！

# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/b452a77113f94232a5dc6a74f8937db2.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 利用指针
### 2.1.1 思路
本题主要是按顺序交换链表的奇偶位，我觉得主要可分为两种思路，一个是交换节点的值，一个是交换节点。

此处的思路主要是交换节点！但我一开始的实现思路有点浪费较多资源，具体程序思路如下：
![在这里插入图片描述](https://img-blog.csdnimg.cn/6c8d341bcb0e4b2c8296b9224ed4f5dd.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
![在这里插入图片描述](https://img-blog.csdnimg.cn/73b683278eba437f9e409394a210f3b3.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)
*（注：不想用Visio画，太浪费时间了~）*
### 2.1.2 程序代码
根据上述照片最后的代码为


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
	    ListNode* oddEvenList(ListNode* head) {
	        if(head == nullptr) return NULL;
	        int mid = 0;
	        ListNode* cur = head->next;
	        ListNode* up = head;
	        ListNode* prev = head;
	        while(cur)
	        {
	            if(mid %2 != 0)
	            {
	                ListNode* tmp = prev->next;
	                prev->next = cur;
	                if(up == tmp)
	                    tmp->next = cur->next;
	                else
	                    up->next = cur->next;
	                cur->next = tmp;
	                cur = up;
	                prev = prev->next;
	            }
	            up = cur;
	            cur = cur->next;
	            mid++;
	        }
	        return head;
	    }
	};
## 2.2 其他方法
这个题难度不高，还有其他实现方法，比如利用将目标链表先处理为奇数链表和偶数链表，然后相连即可，这种方法挺好实现的。还可以利用特定的数据结构或者其他，例如哈希表、栈等，将原链表中各节点进行保存，再配合奇偶顺序规则，将原链表拆开再进行相连等。后续若有时间再进行补充！

侵权删~