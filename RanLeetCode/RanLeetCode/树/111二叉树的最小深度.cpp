//
//  111二叉树的最小深度.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/16.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        if (left == 0)
            return right+1;
        if (right == 0)
            return left+1;
        
        return min(left+1, right+1);
    }
};


/*
 给定一个二叉树，找出其最小深度。

 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

 说明: 叶子节点是指没有子节点的节点。

 示例:

 给定二叉树 [3,9,20,null,null,15,7],

     3
    / \
   9  20
     /  \
    15   7

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
