//
//  109有序链表转换二叉搜索树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/16.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//方法1：直接操作链表 O(NlogN) O(logN）
//方法1: 链表转数组咯，空间换时间 O(N)  O(N)

//方法3:有点看不懂 下次再看

//再做一遍
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        return dfs(head, NULL);//⚠️NULL
    }
    
    TreeNode* dfs(ListNode *left, ListNode *right) {
        if (left == right) {
            return NULL;
        }
        
        ListNode *mid = findMid(left, right);
        TreeNode *node = new TreeNode(mid->val);
        node->left = dfs(left, mid);//⚠️
        node->right = dfs(mid->next, right);
        return node;
    }
    
    ListNode *findMid(ListNode *left, ListNode *right) {
        ListNode *slow = left;
        ListNode *fast = left;
        
        while (fast!=right && fast->next!=right) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};


/*
 
 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

 示例:

 给定的有序链表： [-10, -3, 0, 5, 9],

 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

       0
      / \
    -3   9
    /   /
  -10  5

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
