//
//  876链表的中间结点.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/27.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        while (p2->next) {
            if (p2->next->next) {
                p2 = p2->next->next;
            } else {
                p2 = p2->next;
            }
            p1 = p1->next;
        }
        
        return p1;
    }
};
