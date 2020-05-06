//
//  114二叉树展开为链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/20.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"


class Solution {
public:
    void flatten(TreeNode* root) {
        root = traverse(root);
    }
    
    TreeNode* traverse(TreeNode *cur) {
        if (cur == NULL) {
            return NULL;
        }
        
        //保存右子树
        TreeNode *r = cur->right;
        
        cur->right = traverse(cur->left);
        cur->left = NULL;
        
        TreeNode *t = cur;
        while (t->right) {
            t = t->right;
        }
        
        t->right = traverse(r);
        
        return cur;
    }
};

//int main(int argc, const char * argv[]) {
//
//    TreeNode *t1 = new TreeNode(1);
//    TreeNode *t2 = new TreeNode(2);
//    TreeNode *t3 = new TreeNode(3);
//    TreeNode *t4 = new TreeNode(4);
//    TreeNode *t5 = new TreeNode(5);
//    TreeNode *t6 = new TreeNode(6);
//    
//    t1->left = t2;
//    t1->right = t5;
//    
//    t2->left = t3;
//    t2->right = t4;
//    
//    t5->right = t6;
//
//    Solution s;
//    s.flatten(t1);
//    
//    return 0;
//}
