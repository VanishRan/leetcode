//
//  23合并K个升序链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/20.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//方法1:两两合并 垃圾
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        
        ListNode *cur = lists[0];
        for (int i=1; i<lists.size(); i++) {
            cur = mergeTwoLists(cur, lists[i]);
        }
        return cur;
    }
    
    ListNode* mergeTwoLists(ListNode *t1, ListNode *t2) {
        ListNode *root = new ListNode(0);
        ListNode *pre = root;
        
        while (t1 && t2) {
            if (t1->val <= t2->val) {
                pre->next = t1;
                pre = t1;
                t1 = t1->next;
            } else {
                pre->next = t2;
                pre = t2;
                t2 = t2->next;
            }
        }
        
        pre->next = t1 ? t1 : t2;
        return root->next;
    }
};

//方法2:分治法
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        
        return merge(lists, 0, lists.size()-1);
    }
    
    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if (left == right)
            return lists[left];
        
        if (left > right)
            return NULL;
        
        int mid = (left + right) / 2;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid+1, right)); //⚠️
    }
    
    ListNode* mergeTwoLists(ListNode *t1, ListNode *t2) {
        ListNode *root = new ListNode(0);
        ListNode *pre = root;
        
        while (t1 && t2) {
            if (t1->val <= t2->val) {
                pre->next = t1;
                pre = t1;
                t1 = t1->next;
            } else {
                pre->next = t2;
                pre = t2;
                t2 = t2->next;
            }
        }
        
        pre->next = t1 ? t1 : t2;
        return root->next;
    }
};

/*
 给你一个链表数组，每个链表都已经按升序排列。

 请你将所有链表合并到一个升序链表中，返回合并后的链表。

  

 示例 1：

 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 输出：[1,1,2,3,4,4,5,6]
 解释：链表数组如下：
 [
   1->4->5,
   1->3->4,
   2->6
 ]
 将它们合并到一个有序链表中得到。
 1->1->2->3->4->4->5->6
 示例 2：

 输入：lists = []
 输出：[]
 示例 3：

 输入：lists = [[]]
 输出：[]
  

 提示：

 k == lists.length
 0 <= k <= 10^4
 0 <= lists[i].length <= 500
 -10^4 <= lists[i][j] <= 10^4
 lists[i] 按 升序 排列
 lists[i].length 的总和不超过 10^4

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
