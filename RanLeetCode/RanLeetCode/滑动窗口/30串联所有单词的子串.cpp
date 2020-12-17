//
//  30串联所有单词的子串.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/9/12.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//思路：两个map
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.length() <= 0 || words.size() <= 0)
            return res;
        
        int word_num = words.size();
        int word_len = words[0].size();
        int window_len = word_num * word_len;
        
        map<string,int> mp;
        for (int i=0; i<word_num; i++) {
            mp[words[i]]++;
        }
        
        //滑动窗口
        for (int i=0; i+window_len-1<s.length(); i++) {
            map<string,int> tmp;
            int left = i;
            int right = i+window_len-1;
            
            while (left <= right) {
                string str = s.substr(left, word_len);
                
                //没有这个单词
                if (!mp.count(str)) {
                    break;
                }
                
                tmp[str]++;
                
                //单词出现的次数 超过词典中该单词出现的次数
                if (tmp[str] > mp[str]) {
                    break;
                }
                
                left += word_len;
            }
            
            if (left > right) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};

/*
 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

  

 示例 1：

 输入：
   s = "barfoothefoobarman",
   words = ["foo","bar"]
 输出：[0,9]
 解释：
 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 输出的顺序不重要, [9,0] 也是有效答案。
 示例 2：

 输入：
   s = "wordgoodgoodgoodbestword",
   words = ["word","good","best","word"]
 输出：[]


 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
