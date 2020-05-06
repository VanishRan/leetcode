//
//  617合并二叉树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/29.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL)
            return t2;
        
        if (t2 == NULL) {
            return t1;
        }
        
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
            
        return t1;
    }
};
