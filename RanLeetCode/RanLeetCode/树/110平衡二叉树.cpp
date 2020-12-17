//
//  110平衡二叉树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/16.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "math.h"
//again
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        
        int res = dfs(root);
        return  res != -1;
    }
    
    int dfs(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        if (left < 0 ||  right < 0)
            return -1;
        
        if (fabs(left-right) > 1)
            return -1;
        
        return max(left+1, right+1);
    }
};


/*
 给定一个二叉树，判断它是否是高度平衡的二叉树。

 本题中，一棵高度平衡二叉树定义为：

 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

 示例 1:

 给定二叉树 [3,9,20,null,null,15,7]

     3
    / \
   9  20
     /  \
    15   7
 返回 true 。

 示例 2:

 给定二叉树 [1,2,2,3,3,null,null,4,4]

        1
       / \
      2   2
     / \
    3   3
   / \
  4   4

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/balanced-binary-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
