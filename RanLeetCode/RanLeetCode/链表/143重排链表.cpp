//
//  143重排链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/16.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//下次用递归试试
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL)
            return;

        //1 找链表中点
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //2 翻转后半部分
        ListNode *pre = NULL;
        ListNode *cur = slow->next;
        slow->next = NULL;
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        //3 拼接两个链表
        ListNode *p1 = head;
        ListNode *p2 = pre;
        while (p2) {
            ListNode *t2 = p2->next;
            p2->next = p1->next;
            p1->next = p2;

            p1 = p2->next;
            p2 = t2;
        }
    }
};
/*
 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 示例 1:

 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 示例 2:

 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reorder-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
