//
//  958二叉树的完全性检验.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2021/2/23.
//  Copyright © 2021 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *pre = root;
        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            if (cur && pre == NULL)
                return false;
            
            if (cur) {
                q.push(cur->left);
                q.push(cur->right);
            }
            pre = cur;
        }
        return true;
    }
};
