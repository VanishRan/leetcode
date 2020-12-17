//
//  146LRU缓存机制.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/23.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
// LFU 460

//哈希+双向链表
struct DListNode {
    int key;
    int val;
    DListNode *pre;
    DListNode *next;
    DListNode(int k, int v) {
        key = k;
        val = v;
        pre = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    int size;
    int capacity;
    DListNode *head;
    DListNode *tail;
    map<int,DListNode*> mp;
public:
    LRUCache(int cap) {
        size = 0;
        capacity = cap;
        head = new DListNode(0,0);
        tail = new DListNode(0,0);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (mp.count(key)) {
            DListNode *t = mp[key];
            moveToHead(t);
            return t->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //如果key已经存在,则移到队前
        if (mp.count(key)) {
            DListNode *t = mp[key];
            t->val = value;            //⚠️记得修改value
            moveToHead(t);
        } else {
            if (size == capacity) {
                //移除掉最后的
                DListNode *last = removeLast();
                mp.erase(last->key);   //⚠️这就是为啥节点要有个key
                size--;
            }
            
            //插在前面
            DListNode *t = new DListNode(key,value);
            mp[key] = t;
            size++;
            addToHead(t);
        }
    }
    
    void addToHead(DListNode *t) {
        t->next = head->next;
        t->next->pre = t;
        head->next = t;
        t->pre = head;
    }
    
    void moveToHead(DListNode *t) {
        t->pre->next = t->next;
        t->next->pre = t->pre;
        addToHead(t);
    }
    
    DListNode* removeLast() {
        DListNode *last = tail->pre;
        last->pre->next = tail;
        tail->pre = last->pre;
        return last;
    }
};

//int main() {
//    LRUCache* obj = new LRUCache(2);
//    obj->put(1,1);
//    obj->put(2,2);
//    obj->get(1);
//    obj->put(3,3);
//}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

 获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
 写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

  

 进阶:

 你是否可以在 O(1) 时间复杂度内完成这两种操作？

  

 示例:

 LRUCache cache = new LRUCache( 2 // 缓存容量  );

 cache.put(1, 1);
 cache.put(2, 2);
 cache.get(1);       // 返回  1
 cache.put(3, 3);    // 该操作会使得关键字 2 作废
 cache.get(2);       // 返回 -1 (未找到)
 cache.put(4, 4);    // 该操作会使得关键字 1 作废
 cache.get(1);       // 返回 -1 (未找到)
 cache.get(3);       // 返回  3
 cache.get(4);       // 返回  4

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/lru-cache
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
