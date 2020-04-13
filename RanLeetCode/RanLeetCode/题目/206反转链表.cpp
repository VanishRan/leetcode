//
//  206反转链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/25.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
//三指针法  下次看看递归法呀～
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode *p1 = NULL;
        ListNode *p2 = head;
        ListNode *p3 = head->next;
        
        while (p2) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3 ? p3->next : NULL;
        }

        return p1;
    }
};

//int main(int argc, const char * argv[]) {
//    ListNode *n1 = new ListNode(1);
//    ListNode *n2 = new ListNode(2);
//    ListNode *n3 = new ListNode(3);
//    
//    n1->next = n2;
//    n2->next = n3;
//    
//    Solution s;
//    s.reverseList(n1);
//    
//    return 0;
//}
