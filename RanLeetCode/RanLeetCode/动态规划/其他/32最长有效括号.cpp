//
//  32最长有效括号.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/9/12.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
   ())((())
    
 dp[i]定义：以i结尾的最长有效括号长度
 
 1.如果 s[i-1] == '('
 dp[i] = dp[i-2] + 2
 
 2.如果 s[i-1] == ')' && s[i - dp[i-1] - 1] == '('
 dp[i] = dp[i-dp[i-1]-2] + dp[i-1] + 2
 
 
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> dp(s.length(), 0);
        for (int i=1; i<s.length(); i++) {
            if (s[i] == '(') {
                continue;
            }
            
            if (s[i-1] == '(') {
                dp[i] = (i == 1) ? 2 : (dp[i-2] + 2);
            }
            
            if (s[i-1] == ')' && i-dp[i-1]-1>=0 && s[i-dp[i-1]-1] == '(') {
                dp[i] = (i-dp[i-1]-2 >= 0) ? (dp[i-dp[i-1]-2] + dp[i-1] + 2) : (dp[i-1] + 2) ;
            }
            
            res = max(res, dp[i]);
        }
        return res;
    }
};

/*
 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

 示例 1:

 输入: "(()"
 输出: 2
 解释: 最长有效括号子串为 "()"
 示例 2:

 输入: ")()())"
 输出: 4
 解释: 最长有效括号子串为 "()()"

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-valid-parentheses
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
