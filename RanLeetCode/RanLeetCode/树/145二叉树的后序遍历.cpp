//
//  145二叉树的后序遍历.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/17.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        
        map<TreeNode *, bool> mp;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *cur = s.top();
            bool leftVisited = true;
            bool rightVisited = true;
            
            if (cur->right && !mp[cur->right]) {
                s.push(cur->right);
                rightVisited = false;
            }
            
            if (cur->left && !mp[cur->left]) {
                s.push(cur->left);
                leftVisited = false;
            }
            
            if (leftVisited && rightVisited) {
                res.push_back(cur->val);
                mp[cur] = true;
                s.pop();
            }
        }
        
        return res;
    }
};

/*
 给定一个二叉树，返回它的 后序 遍历。

 示例:

 输入: [1,null,2,3]
    1
     \
      2
     /
    3

 输出: [3,2,1]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
