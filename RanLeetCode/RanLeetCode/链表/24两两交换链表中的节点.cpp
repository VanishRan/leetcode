//
//  24两两交换链表中的节点.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/20.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return head;
            
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        head = p2 ?: p1;
        ListNode *p0 = new ListNode(0);
        while (p1 && p2) {
            p1->next = p2->next;
            p2->next = p1;
            p0->next = p2;
            
            p0 = p1;
            p1 = p1->next;
            p2 = p1 ? p1->next : NULL;
        }
        
        return head;
    }
};

//int main() {
//    ListNode *t1 =new ListNode(1);
//    ListNode *t2 =new ListNode(2);
//    ListNode *t3 =new ListNode(3);
//    ListNode *t4 =new ListNode(4);
//
//    t1->next = t2;
//    t2->next = t3;
//    t3->next = t4;
//
//    Solution s;
//    s.swapPairs(t1);
//}

/*
 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

  

 示例:

 给定 1->2->3->4, 你应该返回 2->1->4->3.


 */
