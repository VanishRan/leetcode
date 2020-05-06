//
//  5最长回文子串.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/5.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        for (int i=0; i<s.length(); i++) {
            string t1 = palindrome(s, i, i);
            string t2 = palindrome(s, i, i+1);
            res = t1.length() > res.length() ? t1 : res;
            res = t2.length() > res.length() ? t2 : res;
        }
        return res;
    }
    
    string palindrome(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        string res = s.substr(left+1, right-left-1);
        
        return res;
    }
};

/*
 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

 示例 1：

 输入: "babad"
 输出: "bab"
 注意: "aba" 也是一个有效答案。
 示例 2：

 输入: "cbbd"
 输出: "bb"
 */
