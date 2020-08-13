//
//  279完全平方数.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/23.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++) {
            for (int j=1; j<=i; j++) {
                if (j * j > i) {
                    break;
                }
                
                dp[i] = min(dp[i-j*j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};

/*
 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

 示例 1:

 输入: n = 12
 输出: 3
 解释: 12 = 4 + 4 + 4.
 示例 2:

 输入: n = 13
 输出: 2
 解释: 13 = 4 + 9.

 */
