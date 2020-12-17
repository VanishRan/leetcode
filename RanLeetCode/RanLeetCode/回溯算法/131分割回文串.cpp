//
//  131分割回文串.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/22.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"


class Solution {
public:
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        backTrack(s, 0, path);
        return res;
    }
    
    void backTrack(string s, int begin, vector<string>path) {
        if (begin >= s.length()) {
            res.push_back(path);
            return;
        }
        
        for (int i=begin; i<s.length(); i++) {
            string tmp = s.substr(begin, i-begin+1);
            if (isValid(tmp)) {
                path.push_back(tmp);
                backTrack(s, i+1, path);
                path.pop_back();
            }
        }
    }
    
    bool isValid(string s) {
        int left = 0;
        int right = s.length()-1;
        while (left <= right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }
};

/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
