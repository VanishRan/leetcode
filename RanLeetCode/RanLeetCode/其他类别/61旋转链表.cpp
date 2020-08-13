//
//  61旋转链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/1.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        
        //有多少个节点
        int count = 0;
        ListNode *cur = head;
        while(cur) {
            count++;
            cur = cur->next;
        }
        
        int n = k % count; //实际上的偏移
        
        if (n == 0)
            return head;
        
        
        
        ListNode *t1 = head;
        ListNode *t2 = head;
        while(n--) {
            t2 = t2->next;
        }
        
        while (t2->next) {
            t1 = t1->next;
            t2 = t2->next;
        }
            
        ListNode *t3 = t1->next;
        t1->next = NULL;
        t2->next = head;
        
        return t3;
    }
};

/*
 示例 1:

 输入: 1->2->3->4->5->NULL, k = 2
 输出: 4->5->1->2->3->NULL
 解释:
 向右旋转 1 步: 5->1->2->3->4->NULL
 向右旋转 2 步: 4->5->1->2->3->NULL
 示例 2:

 输入: 0->1->2->NULL, k = 4
 输出: 2->0->1->NULL
 解释:
 向右旋转 1 步: 2->0->1->NULL
 向右旋转 2 步: 1->2->0->NULL
 向右旋转 3 步: 0->1->2->NULL
 向右旋转 4 步: 2->0->1->NULL

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/rotate-list
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
