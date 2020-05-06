//
//  102二叉树的层序遍历.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/9.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"


//队列+循环
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        
        if (root != NULL) {
            q.push(root);
        }
        
        while (!q.empty()) {
            vector<int> v;
            int len = q.size();
            for (int i=0; i<len; i++) {
                TreeNode *t = q.front();
                v.push_back(t->val);
                q.pop();
                
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                
            }
            res.push_back(v);
        }
        return res;
    }
};

//递归
class Solution2 {
public:
    vector<vector<int>> res;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root != NULL)
            traverse(root, 0);
        return res;
    }
    
    void traverse(TreeNode *node, int level) {
        //巧妙
        if (res.size() == level) {
            vector<int> v;
            res.push_back(v);
        }
        
        res[level].push_back(node->val);
        
        if (node->left)
            traverse(node->left, level+1);
        
        if (node->right)
            traverse(node->right, level+1);
        
    }
};
