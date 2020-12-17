//
//  103二叉树的锯齿形层次遍历.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/16.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//栈 或 双端队列
//思考递归
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        stack<TreeNode *> s1;
        
        if (root == NULL) {
            return res;
        }
        
        s1.push(root);
        int level = 0;
        while (!s1.empty()) {
            stack<TreeNode *> s2;
            vector<int> tmp;
            int len = s1.size();
            for (int i=0; i<len; i++) {
                TreeNode *node = s1.top();
                s1.pop();
                tmp.push_back(node->val);
                
                if (level%2 == 0) {
                    if (node->left) {
                        s2.push(node->left);
                    }
                    if (node->right) {
                        s2.push(node->right);
                    }
                } else {
                    if (node->right) {
                        s2.push(node->right);
                    }
                    if (node->left) {
                        s2.push(node->left);
                    }
                }
            }
            s1 = s2;
            res.push_back(tmp);
            level++;
        }
        return res;
    }
};


/*
 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

 例如：
 给定二叉树 [3,9,20,null,null,15,7],

     3
    / \
   9  20
     /  \
    15   7
 返回锯齿形层次遍历如下：

 [
   [3],
   [20,9],
   [15,7]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
