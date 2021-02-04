//
//  82删除排序链表中的重复元素 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/1.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *preHead = new ListNode(0);
        ListNode *t1 = preHead; t1->next = head;
        ListNode *t2 = head;
        ListNode *t3 = head->next;

        while (t3) {
            //1 2 3 3
            //1 2 3 3 4
            //1 2 3 3 4 4
            //1 2 3 3 4 5
            if (t2->val == t3->val) {
                while(t3 && t3->val == t2->val) {
                    t3 = t3->next;
                }
                t1->next = t3;
                t2 = t3;
                t3 = t3 ? t3->next : NULL;
            } else {
                t1 = t2;
                t2 = t3;
                t3 = t3->next;
            }
        }
        
        return preHead->next;
    }
};

/*
 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

 示例 1:

 输入: 1->2->3->3->4->4->5
 输出: 1->2->5
 示例 2:

 输入: 1->1->1->2->3
 输出: 2->3

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
