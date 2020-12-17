//
//  25K 个一组翻转链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/20.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //看看剩余的节点是否 n>=k
        ListNode *cur = head;
        int n = 0;
        while (cur) {
            if (++n >= k) break;
            cur = cur->next;
        }
        
        if (n < k)
            return head;
        
        //翻转当前k个结点
        ListNode *pre = NULL;
        cur = head;
        int m = k;
        while (m--) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        
        //翻转剩余的节点
        head->next = reverseKGroup(cur, k);
        
        return pre;
    }
};
/*
 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

 k 是一个正整数，它的值小于或等于链表的长度。

 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

  

 示例：

 给你这个链表：1->2->3->4->5

 当 k = 2 时，应当返回: 2->1->4->3->5

 当 k = 3 时，应当返回: 3->2->1->4->5

  

 说明：

 你的算法只能使用常数的额外空间。
 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
