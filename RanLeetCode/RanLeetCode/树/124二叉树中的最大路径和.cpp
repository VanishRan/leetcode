//
//  124二叉树中的最大路径和.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/22.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"


class Solution {
public:
    int maxSum;
public:
    int maxPathSum(TreeNode* root) {
        maxSum = 0;
        if (root) {
            maxSum = root->val;
            traverse(root);
        }
        
        return maxSum;
    }
    
    int traverse(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        
        //左子树的最大路径和
        int t1 = traverse(node->left);
        
        //右子树的最大路径和
        int t2 = traverse(node->right);
        
        int t3 = node->val;
        int t4 = node->val;
        if (t1 > 0)
            t4 += t1;
        if (t2 > 0)
            t4 += t2;
        
        maxSum = max(maxSum, t4);
        
        return max(t3 , max(t3+t1, t3+t2));
    }
};

//int main(int argc, const char * argv[]) {
//
//    TreeNode *t1 = new TreeNode(-3);
//    TreeNode *t2 = new TreeNode(2);
//    TreeNode *t3 = new TreeNode(3);
//    TreeNode *t4 = new TreeNode(4);
//    TreeNode *t5 = new TreeNode(5);
//    TreeNode *t6 = new TreeNode(6);
//    TreeNode *t7 = new TreeNode(7);
//
//    //t1->left = t2;
//    //t1->right = t3;
//
////    t2->left = t4;
////    t2->right = t5;
////
////    t3->left = t6;
////    t3->right = t7;
//
//    Solution s;
//    s.maxPathSum(t1);
//
//    return 0;
//}
