//
//  322零钱兑换.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/4.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 
 输入: coins = [1, 2, 5], amount = 11
 输出: 3
 解释: 11 = 5 + 5 + 1
 示例 2:

 输入: coins = [2], amount = 3
 输出: -1
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0) {
            return -1;
        }
        
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i=1; i<=amount; i++) {
            for (int j=0; j<coins.size(); j++) {
                if (i-coins[j] < 0) {
                    continue;
                }
                
                dp[i] = min(dp[i-coins[j]]+1, dp[i]);
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
