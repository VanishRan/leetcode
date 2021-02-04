//
//  148排序链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
示例 1:
输入: 4->2->1->3
输出: 1->2->3->4
 
示例 2:
输入: -1->5->3->4->0
输出: -1->0->3->4->5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *res = merge(head, NULL); //⚠️NULL
        return res;
    }

    ListNode* merge(ListNode *left, ListNode *right) {
        if (left == right || left == NULL)
            return left;

        ListNode *mid = findMid(left, right);
        ListNode *tmp = mid->next;
        mid->next = NULL;//⚠️断开
        ListNode *l = merge(left, mid);
        ListNode *r = merge(tmp, right);
        ListNode *res = mergeTowSorted(l, r);
        return res;
    }

    ListNode *mergeTowSorted(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *pre = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }

        if (l1) pre->next = l1;
        if (l2) pre->next = l2;
        return head->next;
    }

    ListNode *findMid(ListNode *left, ListNode *right) {
        ListNode *slow = left;
        ListNode *fast = left;
        while (fast!=right && fast->next != right) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    ListNode *t1 = new ListNode(4);
    ListNode *t2 = new ListNode(2);
    ListNode *t3 = new ListNode(1);
    ListNode *t4 = new ListNode(3);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    Solution s;
    s.sortList(t1);

}
