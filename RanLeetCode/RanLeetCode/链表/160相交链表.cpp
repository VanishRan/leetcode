//
//  160相交链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/3.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//哈希法 时间复杂度 m+n 空间复杂度 m或n
//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        map<ListNode*, bool> mp;
//        while (headA) {
//            mp[headA] = true;
//            headA = headA->next;
//        }
//
//        while (headB) {
//            if (mp.find(headB) != mp.end()) {
//                return headB;
//            }
//            headB = headB->next;
//        }
//        return NULL;
//    }
//};

//双指针法 a+c+b = b+c+a 要么在交点相遇 要么在null相遇
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        
        ListNode *t1 = headA;
        ListNode *t2 = headB;
        while (t1 != t2) {
            t1 = t1 == NULL ? headB : t1->next;
            t2 = t2 == NULL ? headA : t2->next;
        }
        
        return t1;
    }
};
