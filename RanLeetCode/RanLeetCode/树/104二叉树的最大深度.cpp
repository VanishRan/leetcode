//
//  104二叉树的最大深度.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/9.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"



class Solution {
public:
    int maxDeep;
public:
    int maxDepth(TreeNode* root) {
        maxDeep = 0;
        if (root)
            traverse(root, 1);
        return maxDeep;
    }
    
    void traverse(TreeNode *node, int deep) {
        if (deep > maxDeep) {
            maxDeep = deep;
        }
        
        if (node->left)
            traverse(node->left, deep+1);
        
        if (node->right)
            traverse(node->right, deep+1);
        
    }
};
