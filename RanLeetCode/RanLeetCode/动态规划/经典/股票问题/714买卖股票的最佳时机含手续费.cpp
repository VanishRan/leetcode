//
//  714买卖股票的最佳时机含手续费.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/4.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 0) {
            return 0;
        }
        
        //状态1:天数
        //状态2:持有状态
        //int dp[len][2];
        int pre_0;
        int pre_1;
        for (int i=0; i<prices.size(); i++) {
            if (i == 0) {
                //dp[i][0] = 0;
                //dp[i][1] = -prices[i];
                pre_0 = 0;
                pre_1 = (-prices[i]) - fee;
                continue;
            }
            
            //dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            //dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
            int tmp = pre_0;
            pre_0 = max(pre_0, pre_1+prices[i]);
            pre_1 = max(pre_1, tmp-prices[i]-fee); //买入才需要手续费
        }
        
        return pre_0;
    }
};
