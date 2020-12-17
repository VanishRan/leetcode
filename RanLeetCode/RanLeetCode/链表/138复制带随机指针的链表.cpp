//
//  138复制带随机指针的链表.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/21.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//回溯法
class Solution {
public:
    map<Node*,Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        return backTrack(head);
    }
    
    Node* backTrack(Node* t) {
        if (t == NULL)
            return NULL;
        
        if (mp[t])
            return mp[t];
        
        Node *cp = new Node(t->val);
        mp[t] = cp;
        cp->next = backTrack(t->next);
        cp->random = backTrack(t->random);
        return cp;
    }
};

//方法2: O(1) 空间的迭代
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        
        //1.每个节点拷贝放在旁边
        //A->B->C   A->a->B->b->C->c
        Node *cur = head;
        while (cur) {
            Node *cp = new Node(cur->val);
            cp->next = cur->next;
            cur->next = cp;
            cur = cp->next;
        }
        
        //2.处理random指针
        Node *t1 = head;
        Node *t2 = head->next;
        while (t1 && t2) {
            t2->random = t1->random ? t1->random->next : NULL;
            t1 = t2->next;
            t2 = t1 ? t1->next : NULL;
        }
        
        //3.分开两个链表
        t1 = head;
        t2 = head->next;
        Node *head2 = t2;
        while (t1 && t2) {
            t1->next = t2->next;
            t1 = t2;
            t2 = t2->next;
        }
        
        return head2;
    }
};

//自己写的一般般
class Solution4 {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        
        vector<Node *> v;
        map<Node*,int> mp;
        
        Node *pre = NULL;
        Node *cur = head;
        int i = 0;
        while (cur) {
            Node *cp = new Node(cur->val);
            v.push_back(cp);
            mp[cur] = i++;
            
            if (pre)
                pre->next = cp;
            pre = cp;
            
            cur = cur->next;
        }
        
        cur = head;
        i = 0;
        while (cur) {
            Node *random = cur->random;
            if (random)
                v[i]->random = v[mp[random]];
            i++;
            cur = cur->next;
        }
        
        return v[0];
    }
};
