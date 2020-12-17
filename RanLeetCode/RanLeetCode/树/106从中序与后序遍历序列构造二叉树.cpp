//
//  106从中序与后序遍历序列构造二叉树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/16.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode *build(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight, int postLeft, int postRight) {
        if (inLeft > inRight || postLeft > postRight)
            return NULL;
        
        //先在中序中找到父节点
        int i = inLeft;
        while (i<=inRight) {
            if (inorder[i] == postorder[postRight])
                break;
            i++;
        }
        
        TreeNode *cur = new TreeNode(postorder[postRight]);
        cur->left = build(inorder, postorder, inLeft, i-1, postLeft, postLeft+i-inLeft-1 );
        cur->right = build(inorder, postorder, i+1, inRight, postLeft+i-inLeft, postRight-1);
        
        return cur;
    }
};


/*
 根据一棵树的中序遍历与后序遍历构造二叉树。

 注意:
 你可以假设树中没有重复的元素。

 例如，给出

 中序遍历 inorder = [9,3,15,20,7]
 后序遍历 postorder = [9,15,7,20,3]
 返回如下的二叉树：

     3
    / \
   9  20
     /  \
    15   7

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
