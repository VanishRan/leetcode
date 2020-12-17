//
//  132分割回文串 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/22.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int res;
public:
    int minCut(string s) {
        res = s.length()-1;
        backTrack(s, 0, 0);
        return res;
    }
    
    void backTrack(string s, int begin, int cnt) {
        if (begin >= s.length()) {
            res = min(res, cnt-1);
            return;
        }
        
        for (int i=begin; i<s.length(); i++) {
            string t = s.substr(begin, i-begin+1);
            if (isValid(t)) {
                backTrack(s, i+1, cnt+1);
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

 返回符合要求的最少分割次数。

 示例:

 输入: "aab"
 输出: 1
 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/palindrome-partitioning-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
