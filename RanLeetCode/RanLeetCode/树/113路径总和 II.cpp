//
//  113路径总和 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/16.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        dfs(root, sum, path, 0);
        return res;
    }
    
    void dfs(TreeNode *node, int sum, vector<int>path, int tmp) {
        if (node == NULL)
            return;
        
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL && tmp+node->val == sum)
            res.push_back(path);
        
        dfs(node->left, sum, path, tmp+node->val);
        dfs(node->right, sum, path, tmp+node->val);
    }
};

/*
 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

 说明: 叶子节点是指没有子节点的节点。

 示例:
 给定如下二叉树，以及目标和 sum = 22，

               5
              / \
             4   8
            /   / \
           11  13  4
          /  \    / \
         7    2  5   1
 返回:

 [
    [5,4,11,2],
    [5,8,4,5]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/path-sum-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
