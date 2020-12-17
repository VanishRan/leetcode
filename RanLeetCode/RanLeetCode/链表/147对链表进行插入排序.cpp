//
//  147对链表进行插入排序.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/20.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL)
            return NULL;

        ListNode *root = new ListNode(0);
        root->next = head;
        ListNode *last = head;
        ListNode *cur = head->next;
        while (cur) {

            if (cur->val < last->val) {
                last->next = cur->next;

                ListNode *pre = root;
                while (pre->next != last && pre->next->val < cur->val) {
                    pre = pre->next;
                }

                cur->next = pre->next;
                pre->next = cur;
                cur = last->next;
            } else {
                cur = cur->next;
                last = last->next;
            }
        }
        return root->next;
    }
};
