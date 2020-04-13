//
//  98验证二叉搜索树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/8.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/*
 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 假设一个二叉搜索树具有如下特征：
 节点的左子树只包含小于当前节点的数。
 节点的右子树只包含大于当前节点的数。
 所有左子树和右子树自身必须也是二叉搜索树。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//确定每个节点的取值范围就很好做 有规律
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return traverse(root, LONG_MIN, LONG_MAX);
    }
    
    bool traverse(TreeNode *node, long min, long max) {
        if (node == NULL) {
            return true;
        }
        
        if (node->val <= min || node->val >= max)
            return false;
        if (!traverse(node->left, min, node->val))
            return false;
        if (!traverse(node->right, node->val, max))
            return false;
        
        return true;
    }
};
