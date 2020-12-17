//
//  212单词搜索 II.cpp
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
        childrens = vector<TrieNode *>(26,NULL);
    }
};

class Solution {
public:
    TrieNode *root;
    vector<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        
        //1.先建立前缀树
        for (int i=0; i<words.size(); i++) {
            TrieNode *cur = root;
            string s = words[i];
            for (int j=0; j<s.length(); j++) {
                int idx = s[j] - 'a';
                if (cur->childrens[idx] == NULL) {
                    cur->childrens[idx] = new TrieNode();
                }
                cur = cur->childrens[idx];
            }
            cur->isEnd = true;
        }
        
        //2.dfs回溯二维网格
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                dfs(board, i, j, root, "");
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode*node, string path) {
        char ch = board[i][j];
        int idx = ch-'a';
        if (ch == '.' || node == NULL || node->childrens[idx] == NULL)
            return;
        
        path = path + ch;
        node = node->childrens[idx];
        if (node->isEnd) {
            res.push_back(path);
            node->isEnd = false;     //⚠️精髓啊～
        }
        
        board[i][j] = '.';
        if (i-1 >= 0)              dfs(board, i-1, j, node, path);
        if (i+1 < board.size())    dfs(board, i+1, j, node, path);
        if (j-1 >= 0)              dfs(board, i, j-1, node, path);
        if (j+1 < board[0].size()) dfs(board, i, j+1, node, path);
        board[i][j] = ch;
    }
};

/*
 给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

 示例:

 输入:
 words = ["oath","pea","eat","rain"] and board =
 [
   ['o','a','a','n'],
   ['e','t','a','e'],
   ['i','h','k','r'],
   ['i','f','l','v']
 ]

 输出: ["eat","oath"]
 说明:
 你可以假设所有输入都由小写字母 a-z 组成。

 提示:

 你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
 如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/word-search-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
