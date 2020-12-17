//
//  144二叉树的前序遍历.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/17.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *t = s.top();
            s.pop();
            res.push_back(t->val);
            
            if (t->right)
                s.push(t->right);
            
            if (t->left)
                s.push(t->left);
        }
        return res;
    }
};


/*
 给定一个二叉树，返回它的 前序 遍历。

  示例:

 输入: [1,null,2,3]
    1
     \
      2
     /
    3

 输出: [1,2,3]
 进阶: 递归算法很简单，你可以通过迭代算法完成吗？

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
