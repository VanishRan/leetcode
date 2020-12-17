//
//  116填充每个节点的下一个右侧节点指针.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/16.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
//方法一：层次遍历
class Solution2 {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            Node *pre = NULL;
            for (int i=0; i<len; i++) {
                Node *cur = q.front();
                q.pop();
                if (pre) {
                    pre->next = cur;
                }
                pre = cur;
                
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        
        return root;
    }
};

//方法2:使用已建立的next指针
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        Node *head = root;
        while (head) {
            if (head->left) {
                head->left->next = head->right;
            }
            
            if (head->right && head->next) {
                head->right->next = head->next->left;
            }
            
            head = head->next;
        }
        
        connect(root->left);
        
        return root;
    }
};

//方法2:优化
class Solution3 {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        Node *levelHead = root;
        while (levelHead->left) {
            Node *head = levelHead;
            
            while (head) {
                head->left->next = head->right;
        
                if (head->next) {
                    head->right->next = head->next->left;
                }
                
                head = head->next;
            }
            
            levelHead = levelHead->left;
        }
        
        return root;
    }
};
