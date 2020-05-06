//
//  538把二叉搜索树转换为累加树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/27.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"


class Solution {
public:
    int sum;
public:
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        traverse(root);
        return root;
    }
    
    void traverse(TreeNode *t) {
        if (t == NULL) {
            return;
        }
        
        traverse(t->right);
        t->val += sum;
        sum = t->val;
        traverse(t->left);
        
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
//    TreeNode *t7 = new TreeNode(7);
//
//    t2->left = t1;
//    t2->right = t3;
//
//
//
//    Solution s;
//    s.convertBST(t2);
//
//    return 0;
//}
