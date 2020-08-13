//
//  83删除排序链表中的重复元素.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/26.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/*
 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

 示例 1:

 输入: 1->1->2
 输出: 1->2
 示例 2:

 输入: 1->1->2->3->3
 输出: 1->2->3

 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while (p2) {
            while (p2 && p1->val == p2->val) {
                p1->next = p2->next;
                p2 = p2->next;
            }
            
            p1 = p1->next;
            p2 = p2 ? p2->next : NULL;
        }
        
        return head;
    }
};
