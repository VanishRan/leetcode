//
//  141环形链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow->next == fast->next) {
                return true;
            }
        }
        
        return false;
    }
};
