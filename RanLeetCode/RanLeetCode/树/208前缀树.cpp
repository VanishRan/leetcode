//
//  208前缀树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/29.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class TrieNode {
public:
    bool isEnd;
    vector<TrieNode *> childrens;
public:
    TrieNode() {
        isEnd = false;
        childrens = vector<TrieNode *>(26, NULL);
    }
};

class Trie {
public:
    TrieNode *root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int i = 0;
        TrieNode *cur = root;
        while (i<word.length()) {
            int idx = word[i++]-'a';
            if (cur->childrens[idx] == NULL) {
                cur->childrens[idx] = new TrieNode();
            }
            cur = cur->childrens[idx];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int i = 0;
        TrieNode *cur = root;
        while (i<word.length()) {
            int idx = word[i++]-'a';
            if (cur->childrens[idx]) {
                cur = cur->childrens[idx];
            } else {
                return false;
            }
        }
        
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int i = 0;
        TrieNode *cur = root;
        while (i<prefix.length()) {
            int idx = prefix[i++]-'a';
            if (cur->childrens[idx]) {
                cur = cur->childrens[idx];
            } else {
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

/*
 208. 实现 Trie (前缀树)
 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

 示例:

 Trie trie = new Trie();

 trie.insert("apple");
 trie.search("apple");   // 返回 true
 trie.search("app");     // 返回 false
 trie.startsWith("app"); // 返回 true
 trie.insert("app");
 trie.search("app");     // 返回 true
 说明:

 你可以假设所有的输入都是由小写字母 a-z 构成的。
 保证所有输入均为非空字符串。
 */
