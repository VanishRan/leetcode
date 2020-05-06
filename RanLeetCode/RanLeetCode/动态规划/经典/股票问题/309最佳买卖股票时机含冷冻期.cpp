//
//  309最佳买卖股票时机含冷冻期.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/4.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        //状态1:天数
        //状态2:持有状态
        int dp[prices.size()][2];
        //int pre_0;
        //int pre_1;
        for (int i=0; i<prices.size(); i++) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                //pre_0 = 0;
                //pre_1 = -prices[i];
                continue;
            }
            
            if (i == 1) {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);;
                dp[i][1] = max(dp[i-1][1], -prices[i]);
                continue;
            }
            
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i]); //i-2
            //int tmp = pre_0;
            //pre_0 = max(pre_0, pre_1+prices[i]);
            //pre_1 = max(pre_1, tmp-prices[i]);
        }
        
        return dp[prices.size()-1][0];
    }
};
