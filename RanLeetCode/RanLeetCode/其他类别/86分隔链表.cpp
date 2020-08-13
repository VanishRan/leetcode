//
//  86分隔链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/1.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//1->4->3->2->5->2
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)
            return head;
        
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *t1 = pre;
        
        //先找到>=x的节点的前一个点
        while(t1->next && t1->next->val < x) {
            t1 = t1->next;
        }

        ListNode *t2 = t1->next;
        ListNode *t3 = t2 ? t2->next : NULL;
        while (t3) {
            if (t3->val < x) {
                t2->next = t3->next;
                t3->next = t1->next;
                t1->next = t3;
                t1 = t3;
                t3 = t2->next;
            } else {
                t2 = t2->next;
                t3 = t3->next;
            }
        }
        
        return pre->next;
    }
};

/*
 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

 你应当保留两个分区中每个节点的初始相对位置。

 示例:

 输入: head = 1->4->3->2->5->2, x = 3
 输出: 1->2->2->4->3->5

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/partition-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
