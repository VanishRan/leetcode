//
//  142环形链表 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//哈希法
//class Solution {
//public:
//    ListNode *detectCycle(ListNode *head) {
//        ListNode *cur = head;
//        map<ListNode *, bool> mp;
//        while (cur) {
//            if (mp.find(cur) != mp.end()) {
//                return cur;
//            }
//            mp[cur] = true;
//            cur = cur->next;
//        }
//        return NULL;
//    }
//};

//快慢指针 + 双指针
//f = 2s
//f = s + nb
// => s = nb , f = 2nb 即s走了n个环。

// s = nb , s再走a步就到了入口
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            //有环
            if (slow == fast) {
                fast = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        
        return NULL;
    }
};
