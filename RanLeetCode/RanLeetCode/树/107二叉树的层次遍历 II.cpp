//
//  107二叉树的层次遍历 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/16.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//反转一下结果？晕
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *>q;
        vector<vector<int>> res;
        
        if (root == NULL) {
            return res;
        }
        
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            vector<int> v;
            for (int i=0; i<len; i++) {
                TreeNode *t = q.front();
                q.pop();
                v.push_back(t->val);
                
                if (t->left)
                    q.push(t->left);
                
                if (t->right)
                    q.push(t->right);
            }
            
            res.push_back(v);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

/*
 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

 例如：
 给定二叉树 [3,9,20,null,null,15,7],

     3
    / \
   9  20
     /  \
    15   7
 返回其自底向上的层次遍历为：

 [
   [15,7],
   [9,20],
   [3]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
