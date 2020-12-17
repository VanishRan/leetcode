//
//  117填充每个节点的下一个右侧节点指针 II.cpp
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

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        Node *levelHead = root;
        while (levelHead) {
            Node *cur = levelHead;
            Node *nextLevelHead = NULL;
            Node *pre = NULL;
            while (cur) {
                if (cur->left) {
                    if (pre) {
                        pre->next = cur->left;
                        pre = pre->next;
                    } else {
                        pre = cur->left;
                    }
                    
                    if (!nextLevelHead) {
                        nextLevelHead = cur->left;
                    }
                }
                
                if (cur->right) {
                    if (pre) {
                        pre->next = cur->right;
                        pre = pre->next;
                    } else {
                        pre = cur->right;
                    }
                    
                    if (!nextLevelHead) {
                        nextLevelHead = cur->right;
                    }
                }
                
                cur = cur->next;
            }
            
            levelHead = nextLevelHead;
        }
        return root;
    }
};

//代码优化
class Solution2 {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        Node *curLevel = root;
        while (curLevel) {
            Node *cur = curLevel;
            Node *nextLevel = new Node(0);
            Node *pre = nextLevel;
            while (cur) {
                if (cur->left) {
                    pre->next = cur->left;
                    pre = pre->next;
                
                }
                
                if (cur->right) {
                    pre->next = cur->right;
                    pre = pre->next;
                
                }
                
                cur = cur->next;
            }
            
            if (nextLevel->next == NULL ) {
                break;
            }
            
            curLevel = nextLevel;
        }
        return root;
    }
};
