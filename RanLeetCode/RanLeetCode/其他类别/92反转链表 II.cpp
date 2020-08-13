//
//  92反转链表 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/1.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *root = new ListNode(0);
        root->next = head;
        ListNode *t1 = root;
        ListNode *t2 = head;
        
        if (m == n)
            return head;
        
        //1->2->3->4->5->NULL, m = 2, n = 4
        
        int i = m-1;
        while (i--) {
            t1 = t1->next;
            t2 = t2->next;
        }
        
        int j = n-m+1;
        ListNode *pre = NULL;
        ListNode *cur = t2;
        while(j--) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        
        t1->next = pre;
        t2->next = cur;
        
        return root->next;
    }
};

/*
 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

 说明:
 1 ≤ m ≤ n ≤ 链表长度。

 示例:

 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 输出: 1->4->3->2->5->NULL

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
