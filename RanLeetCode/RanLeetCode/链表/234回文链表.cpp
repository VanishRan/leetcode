//
//  234回文链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/*
 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 输入: 1->2->2->1
 输出: true
 */

//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        vector<int> v;
//        while (head) {
//            v.push_back(head->val);
//            head = head->next;
//        }
//
//        int left = 0;
//        int right = v.size()-1;
//        while (left<right) {
//            if (v[left++] != v[right--]) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//};



/*
找到前半部分链表的尾节点。
反转后半部分链表。
判断是否为回文。
恢复链表。
返回结果。
*/
// 输入: 1->2->2->1
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast->next) {
            fast = fast->next;
        }
        
        //1->2->2->1
        //1->2<-2<-1
        //反转后半部分链表
        ListNode *cur = slow->next;
        ListNode *pre = slow;
        pre->next  = NULL;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        ListNode *t1 = head;
        ListNode *t2 = fast;
        while (t1 && t2) {
            if (t1->val != t2->val) {
                return false;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        
        return true;
    }
};

//int main() {
//    ListNode *t1 =new ListNode(1);
//    ListNode *t2 =new ListNode(2);
//    ListNode *t3 =new ListNode(1);
//    ListNode *t4 =new ListNode(1);
//    
//    t1->next = t2;
//    t2->next = t3;
//    //t3->next = t4;
//    
//    Solution s;
//    s.isPalindrome(t1);
//}
