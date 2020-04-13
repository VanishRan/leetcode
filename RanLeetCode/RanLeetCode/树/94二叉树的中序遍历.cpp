//
//  94二叉树的中序遍历.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/8.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
 输入: [1,null,2,3]
    1
     \
      2
     /
    3

 输出: [1,3,2]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        
        return res;
    }
    
    void traverse(TreeNode *node) {
        if (node == NULL) {
            return;
        }
        
        traverse(node->left);
        res.push_back(node->val);
        traverse(node->right);
    }
};
