//
//  199二叉树的右视图.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/20.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<int> res;
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return res;
    }
    
    //从右到左层次遍历，第一个元素加入结果数组。
    void dfs(TreeNode *node, int level) {
        if (node == NULL)
            return;
        
        if (level >= res.size())
            res.push_back(node->val);
        
        dfs(node->right, level+1);
        dfs(node->left, level+1);
    }
};

/*

 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

 示例:

 输入: [1,2,3,null,5,null,4]
 输出: [1, 3, 4]
 解释:

    1            <---
  /   \
 2     3         <---
  \     \
   5     4       <---
 */
