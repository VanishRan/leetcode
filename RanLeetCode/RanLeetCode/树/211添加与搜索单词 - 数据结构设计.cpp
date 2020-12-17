//
//  211添加与搜索单词 - 数据结构设计.cpp
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
        childrens = vector<TrieNode*>(26,NULL);
    }
};

class WordDictionary {
public:
    TrieNode *root;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *cur = root;
        int i = 0;
        while (i<word.length()) {
            int idx = word[i++]-'a';
            if (cur->childrens[idx] == NULL) {
                cur->childrens[idx] = new TrieNode();
            }
            cur = cur->childrens[idx];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return backTrack(root, word, 0);
    }
    
    bool backTrack(TrieNode *node, string word, int begin) {
        if (node == NULL)
            return false;
        
        if (begin >= word.length())
            return node->isEnd;           //⚠️这里写错了
        
        char ch = word[begin];
        if (ch != '.') {
           return backTrack(node->childrens[ch-'a'], word, begin+1);
        }
        
        for (int i=0; i<26; i++) {
            if (node->childrens[i] == NULL)
                continue;
            
            if (backTrack(node->childrens[i], word, begin+1))
                return true;
        }
        
        return false;
    }
};

/*
 如果数据结构中有任何与word匹配的字符串，则bool search（word）返回true，否则返回false。 单词可能包含点“。” 点可以与任何字母匹配的地方。

 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

 实现词典类 WordDictionary ：

 WordDictionary() 初始化词典对象
 void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
 bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。
  

 示例：

 输入：
 ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 输出：
 [null,null,null,null,false,true,true,true]

 解释：
 WordDictionary wordDictionary = new WordDictionary();
 wordDictionary.addWord("bad");
 wordDictionary.addWord("dad");
 wordDictionary.addWord("mad");
 wordDictionary.search("pad"); // return False
 wordDictionary.search("bad"); // return True
 wordDictionary.search(".ad"); // return True
 wordDictionary.search("b.."); // return True
  

 提示：

 1 <= word.length <= 500
 addWord 中的 word 由小写英文字母组成
 search 中的 word 由 '.' 或小写英文字母组成
 最调用多 50000 次 addWord 和 search

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/design-add-and-search-words-data-structure
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
