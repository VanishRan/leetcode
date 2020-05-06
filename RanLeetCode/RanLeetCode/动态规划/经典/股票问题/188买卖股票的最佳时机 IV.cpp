//
//  188买卖股票的最佳时机 IV.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/4.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        //一次交易由买入和卖出构成，至少需要两天。所以说有效的限制 k 应该不超过 n/2，如果超过，就没有约束作用了，相当于 k = +infinity
        int max_k = prices.size() / 2;
        if (k > max_k) {
            return maxProfit_k(prices);
        }
        
        //状态1:天数
        //状态2:交易次数
        //状态3:持有状态
        int dp[prices.size()][k+1][2];
        for (int i=0; i<prices.size(); i++) {
            for (int j=0; j<=k; j++) {
                //处理base case
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;
                }
                
                if (j == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = INT_MIN;
                    continue;
                }
                
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);
            }
        }
            
        return dp[prices.size()-1][k][0];
    }
    
    //k无限大
    int maxProfit_k(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        //状态1:天数
        //状态2:持有状态
        int pre_0;
        int pre_1;
        for (int i=0; i<prices.size(); i++) {
            if (i == 0) {
                pre_0 = 0;
                pre_1 = -prices[i];
                continue;
            }
            int tmp = pre_0;
            pre_0 = max(pre_0, pre_1+prices[i]);
            pre_1 = max(pre_1, tmp-prices[i]);
        }
        
        return pre_0;
    }
};
