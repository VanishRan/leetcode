//
//  105从前序与中序遍历序列构造二叉树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/15.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *t;
        if (preorder.size() > 0) {
            t = traverse(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
        }
        return t;
    }
    
    TreeNode* traverse(vector<int>& preorder, vector<int>& inorder, long preLeft, long preRight, long inLeft, long inRight) {
        long idx = 0;
        for (; inLeft+idx<=inRight; idx++) {
            if (preorder[preLeft] == inorder[inLeft+idx]) {
                break;
            }
        }
        
        TreeNode *t = new TreeNode(preorder[preLeft]);
        long preIdx = preLeft + idx;
        long inIdx = inLeft + idx;
        if (preLeft < preIdx && inLeft < inIdx) {
            t->left = traverse(preorder, inorder, preLeft+1, preIdx, inLeft, inIdx-1);
        }
        
        if (preRight > preIdx && inRight > inIdx) {
            t->right = traverse(preorder, inorder, preIdx+1, preRight, inIdx+1, inRight);
        }
        
        return t;
    }
};

//int main(int argc, const char * argv[]) {
//
//    vector<int> preorder = {1,2,3};
//    vector<int> inorder = {3,2,1};
//
//    Solution s;
//    s.buildTree(preorder, inorder);
//    
//    return 0;
//}
