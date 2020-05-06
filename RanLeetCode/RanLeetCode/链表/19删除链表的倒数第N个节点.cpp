//
//  19删除链表的倒数第N个节点.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
 给定一个链表: 1->2->3->4->5, 和 n = 2.

 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *myHead = new ListNode(0);
        myHead->next = head;
        ListNode *slow = myHead;
        ListNode *fast = myHead;
        
        int t1 = n;
        while (t1--) {
            fast = fast->next;
        }
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode *mid;
        if (slow->next) {
            mid  = slow->next->next;
            slow->next = mid;
        }
        
        return myHead->next;
    }
};
