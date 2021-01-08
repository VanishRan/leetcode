//
//  572另一个树的子树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/7.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution2 {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL)
            return false;

        bool t = false;
        if (B && A->val == B->val) { //B==NULL 注意
            t = isSub(A, B);
        }

        bool l = isSubStructure(A->left, B);
        bool r = isSubStructure(A->right, B);

        return t || l || r;
    }

    bool isSub(TreeNode *t1, TreeNode *t2) {
        if (t2 == NULL)
            return true;

        if (t1 == NULL)
            return false;

        if (t1->val == t2->val) {
            return isSub(t1->left, t2->left) && isSub(t1->right, t2->right);
        }

        return false;
    }
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return false;
        }
        
        bool t1, t2, t3;
        if (s->val == t->val) {//t==NULL?
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
