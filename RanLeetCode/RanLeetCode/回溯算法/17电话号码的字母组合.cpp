//
//  17电话号码的字母组合.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/13.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        if (digits.length() > 0) {
            backTrack(digits, mp, "", 0);
        }
        
        return res;
    }
    
    void backTrack(string digits, map<char,string>mp, string path, int begin) {
        if (path.length() == digits.length()) {
            res.push_back(path);
            return;
        }
        
        string str = mp[digits[begin]];
        for (int i=0; i<str.length(); i++) {
            string tmp = path + str[i];
            backTrack(digits, mp, tmp, begin+1);
        }
    }
};

/*
 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



 示例:

 输入："23"
 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

 */
