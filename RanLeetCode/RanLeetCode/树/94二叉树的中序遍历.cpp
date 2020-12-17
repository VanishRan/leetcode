//
//  94二叉树的中序遍历.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/8.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
 输入: [1,null,2,3]
    1
     \
      2
     /
    3

 输出: [1,3,2]
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        
        stack<TreeNode *> s;
        TreeNode *cur = root;         //这里不要push
        while (cur || !s.empty()) {
            while (cur) {             //cur==NULL 代表栈顶节点的左子树都遍历完了
                s.push(cur);
                cur = cur->left;
            }
            
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            
            cur = cur->right;
        }
        
        return res;
    }
};

 
//我自己写的 比较垃圾
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        
        stack<TreeNode *> s;
        map<TreeNode *, bool> visited;
        s.push(root);
        while (!s.empty()) {
            TreeNode *t1 = s.top();
            while (t1->left && !visited[t1->left]) { //如何优化这里
                t1 = t1->left;
                s.push(t1);
            }
            
            TreeNode *t2 = s.top();
            s.pop();
            res.push_back(t2->val);
            visited[t2] = true;
            
            if (t2->right) {
                s.push(t2->right);
            }
        }
        
        return res;
    }
};

//int main() {
//    TreeNode *t1 = new TreeNode(1);
//    TreeNode *t2 = new TreeNode(2);
//    TreeNode *t3 = new TreeNode(3);
//    
//    t1->right = t2;
//    t2->left = t3;
//    Solution s;
//    s.inorderTraversal(t1);
//}
