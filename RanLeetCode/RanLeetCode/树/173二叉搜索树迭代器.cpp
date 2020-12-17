//
//  173二叉搜索树迭代器.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/20.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//需要优化
class BSTIterator2 {
public:
    queue<int> q;
public:
    BSTIterator2(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }

            TreeNode *t = s.top();
            s.pop();
            q.push(t->val);

            if (t)
                cur = t->right;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int t = q.front();
        q.pop();
        return t;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }
};

//方法二：受控递归

/*
 1 初始化一个空栈S，用于模拟二叉搜索树的中序遍历。中序遍历我们采用与之前相同的方法，只是我们现在使用的是自己的栈而不是系统的堆栈。由于我们使用自定义的数据结构，因此可以随时暂停和恢复递归。
 2 我们还要实现一个帮助函数，在实现中将一次又一次的调用它。这个函数叫 _inorder_left，它将给定节点中的所有左子节点添加到栈中，直到节点没有左子节点为止。如下：

 def inorder_left(root):
    while (root):
      S.append(root)
      root = root.left
 
 3 第一次调用 next() 函数时，必须返回二叉搜索树的最小元素，然后我们模拟递归必须向前移动一步，即移动到二叉搜索树的下一个最小元素上。栈的顶部始终包含 next() 函数返回的元素。hasNext() 很容易实现，因为我们只需要检查栈是否为空。
 
 4 首先，给定二叉搜索树的根节点，我们调用函数 _inorder_left，这确保了栈顶部始终包含了 next() 函数返回的元素。
    假设我们调用 next()，我们需要返回二叉搜索树中的下一个最小元素，即栈的顶部元素。有两种可能性：
    一个是栈顶部的节点是一个叶节点。这是最好的情况，因为我们什么都不用做，只需将节点从栈中弹出并返回其值。所以这是个常数时间的操作。
    另一个情况是栈顶部的节点拥有右节点。我们不需要检查左节点，因为左节点已经添加到栈中了。栈顶元素要么没有左节点，要么左节点已经被处理了。如果栈顶部拥有右节点，那么我们需要对右节点上调用帮助函数。该时间复杂度取决于树的结构。
 
 5 next() 函数调用中，获取下一个最小的元素不需要花太多时间，但是要保证栈顶元素是 next() 函数返回的元素方面花费了一些时间。
 */

class BSTIterator {
public:
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode* root) {
        if (root)
            pushAllLeft(root);
    }
    
    void pushAllLeft(TreeNode *node) {
        while (node) {
            s.push(node);
            node = node->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *t = s.top();
        s.pop();
        pushAllLeft(t->right);
        return t->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};
