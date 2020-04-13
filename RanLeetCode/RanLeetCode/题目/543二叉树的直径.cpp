//
//  543二叉树的直径.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/26.
//  Copyright © 2020 mahuanran. All rights reserved.
//

/*
             1
            / \
           2   3
          / \
         4   5
 
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//class Solution {
//public:
//    int diameterOfBinaryTree(TreeNode* root) {
//        
//        return 0;
//    }
//    
//    TreeNode *deepTraval(TreeNode *node, int &n) {
//        if (!node) {
//            return NULL;
//        }
//        
//        if (node->left) {
//            //node->left = deepTraval(node->left);
//        }
//        
//        if (node->right) {
//            //node->right = deepTraval(node->right);
//        }
//        
//    }
//};
