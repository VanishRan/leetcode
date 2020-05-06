//
//  543二叉树的直径.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/28.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"


class Solution {
public:
    int maxDeep;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDeep = 0;
        traverse(root);
        return maxDeep>0 ? maxDeep-1 : 0;  //为啥要-1 智障？
    }
    
    int traverse(TreeNode *t) {
        if (t == NULL) {
            return 0;
        }
        
        //左子树的最大深度
        int t1 = traverse(t->left);
        
        //右子树的最大深度
        int t2 = traverse(t->right);
        
        //当前节点的最大深度
        int t3 = t1 + t2 + 1;
        
        maxDeep = max(t3, maxDeep);
        
        return max(t1+1, t2+1);
    }
};
