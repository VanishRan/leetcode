//
//  572另一个树的子树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/7.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return false;
        }
        
        bool t1, t2, t3;
        if (s->val == t->val) {
            t1 = func(s, t);
        }
        
        t2 = isSubtree(s->left, t);
        
        t3 = isSubtree(s->right, t);
        
        return t1 || t2 || t3;
    }
    
    bool func(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) {
            return true;
        }
        
        if (s == NULL || t == NULL) {
            return false;
        }
        
        bool t1 = s->val == t->val ? true : false;
        
        bool t2 = func(s->left, t->left);
        
        bool t3 = func(s->right, t->right);
        
        return t1 && t2 && t3;
    }
};
