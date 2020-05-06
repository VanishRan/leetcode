//
//  236二叉树的最近公共祖先.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/29.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    TreeNode *ancestor;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root, p, q);
        return ancestor;
    }
    
    bool traverse(TreeNode *t,TreeNode* p, TreeNode* q) {
        if (t == NULL) {
            return false;
        }
        
        int left = traverse(t->left, p, q) ? 1 : 0;
        int right = traverse(t->right, p, q) ? 1 : 0;
        int mid = (t->val == p->val || t->val == q->val) ? 1 : 0;
        
        if (left + right + mid >= 2) {
            ancestor = t;
        }
        
        return left + right + mid > 0;
    }
};
