//
//  2两数相加.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/12/30.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;

        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1 && l2) {
                sum += l1->val + l2->val;
                
            } else if (l1 && !l2) {
                sum += l1->val;
            } else if (!l1 && l2) {
                sum += l2->val;
            }
            
            carry = sum / 10;
            sum = sum % 10;

            ListNode *node = new ListNode(0);
            node->val = sum;
            cur->next = node;
            cur = node;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        return head->next;
    }
};
