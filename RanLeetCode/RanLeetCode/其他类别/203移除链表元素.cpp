//
//  203移除链表元素.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/6.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *root = new ListNode(0);
        root->next = head;
        ListNode *pre = root;
        while (head) {
            while (head && head->val == val) {
                head = head->next;
            }
            pre->next = head;
            pre = head;
            head = head ? head->next : NULL;
        }
        
        return root->next;
    }
};

/*
 删除链表中等于给定值 val 的所有节点。

 示例:

 输入: 1->2->6->3->4->5->6, val = 6
 输出: 1->2->3->4->5
 */
