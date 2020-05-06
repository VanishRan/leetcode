//
//  516最长回文子序列.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/5.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
 bbbab
 
    0  1  2  3  4
 0  1
 1  0  1
 2  0  0  1
 3  0  0  0  1
 4  0  0  0  0  1
 
 dp[i][j]: i~j之间回文串的最大长度
 */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp (s.length()+1, vector<int>(s.length(), 0));
        
        for (int i=0; i<s.length(); i++) {
            dp[i][i] = 1;
        }
        
        //从下往上遍历 从左上到右下也是可以的
        for (int i=s.length()-1;i>=0;i--) {
            for (int j=i+1;j<s.length();j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][s.length()-1];
    }
};

/*
 给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。

 示例 1:
 输入:

 "bbbab"
 输出:

 4
 一个可能的最长回文子序列为 "bbbb"。

 示例 2:
 输入:

 "cbbd"
 输出:

 2
 一个可能的最长回文子序列为 "bb"
 */
