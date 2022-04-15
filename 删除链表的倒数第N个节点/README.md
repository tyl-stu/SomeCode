作文以记之 ~ 删除链表的倒数第 N 个结点
=
# 0、前言
本篇博客是力扣上 [19. 删除链表的倒数第 N 个结点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/) 的题解，没有其他想法，就是想记录一下！

相关博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124173576) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/1243725dc4a94ed19665b51197cb1232.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5bCP5by6fg==,size_20,color_FFFFFF,t_70,g_se,x_16)

# 2、解题思路
## 2.1 方法1 ~ 好几个指针
### 2.1.1 思路
先根据所给的 `n` ，找出当前节点后面的第`n`个节点，设为`fast`，然后进行遍历，当`fast`为`nullptr`时，则说明当前节点已是目标节点，然后再以目标节点的上一个节点`prev`，以及目标节点的下一个节点`next`，对目标节点进行删除操作，最后再输出头节点即可！
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
	    ListNode* removeNthFromEnd(ListNode* head, int n) {
	        if(head == nullptr || (head->next==nullptr && n>=1)) return NULL;
	        ListNode* obj = head;//目标节点
	        ListNode* prev= obj;//目标节点的前一个结点
	        ListNode* next = obj->next;//目标节点的下一个节点
	        ListNode* fast = obj;//用于找出目标节点后面的第n个节点
	        while(n)
	        {
	            if(fast != nullptr)
	            {
	                fast = fast->next;
	                n--;
	            }
	            else
	                return NULL;
	        }
	        while(fast != nullptr)
	        {
	            prev = obj;
	            obj = obj->next;
	            next = obj->next;
	            fast = fast->next;
	        }
	        if(prev == obj)
	        {
	            head = next;
	        }
	        else
	            prev->next = next;
	        delete obj;
	        return head;
	    }
	};

## 2.2 其他方法
这个题难度不高，解法还有其他，比如利用栈的先进后出特性，也可先求出链表的长度再进行求解，也可对上述代码进行优化，减少资源的消耗，此处就先不补充了，后面再说！