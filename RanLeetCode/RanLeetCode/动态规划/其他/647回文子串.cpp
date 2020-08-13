//
//  647回文子串.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/23.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i=0; i<s.length(); i++) {
            int t1 = func(s, i, i);
            int t2 = func(s, i, i+1);
            
            res = res + t1 + t2;
        }
        
        return res;
    }
    
    int func(string s, int left, int right) {
        int res = 0;
        while (left >=0 && right < s.length() && s[left] == s[right]) {
            res++;
            left--;
            right++;
        }
        
        return res;
    }
};

/*
 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

 示例 1:

 输入: "abc"
 输出: 3
 解释: 三个回文子串: "a", "b", "c".
 示例 2:

 输入: "aaa"
 输出: 6
 说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".

 */
