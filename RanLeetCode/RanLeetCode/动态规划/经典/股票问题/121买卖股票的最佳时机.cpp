//
//  121买卖股票的最佳时机.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/4.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/*
 
 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。

 注意：你不能在买入股票前卖出股票。

 输入: [7,1,5,3,6,4]
 输出: 5
 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
 示例 2:

 输入: [7,6,4,3,1]
 输出: 0
 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 
 */
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        if (prices.size() == 0) {
//            return 0;
//        }
//
//        int minPrice = prices[0];
//        int maxProfit = 0;
//
//        for (int i=1; i<prices.size(); i++) {
//            maxProfit = max(prices[i] - minPrice, maxProfit);
//            minPrice = min(prices[i], minPrice);
//        }
//
//        return maxProfit;
//    }
//};

//状态转移方程：
/*
 dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
 dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i])
             = max(dp[i-1][1][1], -prices[i])
 解释：k = 0 的 base case，所以 dp[i-1][0][0] = 0。

 现在发现 k 都是 1，不会改变，即 k 对状态转移已经没有影响了。
 可以进行进一步化简去掉所有 k：
 dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 dp[i][1] = max(dp[i-1][1], -prices[i])
 */

//状态转移方程
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        //状态1:天数
        //状态2:持有状态
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0));
        for (int i=0; i<len; i++) {
            //处理base case
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
            } else {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
                dp[i][1] = max(dp[i-1][1], -prices[i]); //⚠️为什么不是 dp[i-1][0]-prices[i])
            }
        }
        
        return dp[len-1][0];
    }
};


class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int res = 0;
        for (int i=1;i<prices.size();i++) {
            res = max(res, prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return res;
    }
};
