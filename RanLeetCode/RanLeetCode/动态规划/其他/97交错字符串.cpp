//
//  97交错字符串.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/10/11.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 输出：true
 
            ''  d   b   b   c   a
        ‘’  T   F   F   F   F   F
        a   T   F   F   F   F   F
        a   T   T   T   T   T   F
        b   F   T   T   F   T   F
        c   F   F   T   T   T   T
        c   F   F   F   T   F   T
 
    dp[i][j] = (dp[i-1][j] && s3[i+j-1] == s1[i-1]) || (dp[i][j-1] && s3[i+j-1] == s2[j-1])
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int row = s1.size();
        int col = s2.size();
        if (row + col != s3.size()) {
            return false;
        }
        
        vector<vector<bool>> dp(row+1, vector<bool>(col+1, false));
        dp[0][0] = true;
        
        //第一行
        for (int i=1; i<=col; i++) {
            if (s2[i-1] == s3[i-1]) {
                dp[0][i] = true;
            } else {
                break;
            }
        }
        
        //第一列
        for (int i=1; i<=row; i++) {
            if (s1[i-1] == s3[i-1]) {
                dp[i][0] = true;
            } else {
                break;
            }
        }
        
        for (int i=1; i<=row; i++) {
            for (int j=1; j<=col; j++) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        
        return dp[row][col];
    }
};


/*
 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

  

 示例 1：

 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 输出：true
 示例 2：

 输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 输出：false

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/interleaving-string
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
