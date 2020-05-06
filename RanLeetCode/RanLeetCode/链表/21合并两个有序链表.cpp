//
//  21合并两个有序链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        cur->next = l1 ? l1 : l2;
        
        return head->next;
    }
};

//int main() {
//    ListNode *t1 = new ListNode(0);
//    ListNode *t2;
//    ListNode *t3;
//    
//    ListNode *t4;
//    
//    Solution s;
//    s.mergeTwoLists(t1, t2);
//}
