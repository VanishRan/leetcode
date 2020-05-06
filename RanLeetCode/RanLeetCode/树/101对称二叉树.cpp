//
//  101对称二叉树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/9.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"



class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return traverse(root, root);
    }
    
    bool traverse(TreeNode* t1 ,TreeNode *t2) {
        if (t1 == NULL && t2 == NULL)
            return true;
        if (t1 == NULL || t2 == NULL || t1->val != t2->val)
            return false;
        if (!traverse(t1->left, t2->right))
            return false;
        if (!traverse(t1->right, t2->left))
            return false;
        
        return true;
    }
};
