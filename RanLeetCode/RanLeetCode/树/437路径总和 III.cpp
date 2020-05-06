//
//  437路径总和 III.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/22.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"


class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        vector<int> path;
        return traverse(root, sum, path);
    }
    
    int traverse(TreeNode *t, int sum, vector<int>path) {
        if (t == NULL) {
            return 0;
        }
        
        int s1 = 0;
        int tmp = 0;
        path.push_back(t->val);
        for (int i=path.size()-1; i>=0; i--) {
            tmp += path[i];
            if (tmp == sum) {
                s1++;
            }
        }
        
        int s2 = traverse(t->left, sum, path);
        int s3 = traverse(t->right, sum, path);
        
        return s1 + s2 +s3;
    }
};

//int main(int argc, const char * argv[]) {
//
//    TreeNode *t1 = new TreeNode(1);
//    TreeNode *t2 = new TreeNode(2);
//    TreeNode *t3 = new TreeNode(3);
//    TreeNode *t4 = new TreeNode(4);
//    TreeNode *t5 = new TreeNode(5);
//    TreeNode *t6 = new TreeNode(6);
//    TreeNode *t7 = new TreeNode(7);
//
//    t1->left = t2;
//    t1->right = t3;
//
//    t2->left = t4;
//    t2->right = t5;
//
//    t3->left = t6;
//    t3->right = t7;
//
//    Solution s;
//    s.invertTree(t1);
//
//    return 0;
//}
