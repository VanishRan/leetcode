//
//  198打家劫舍.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/4.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/*
 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。v
 输入: [1,2,3,1]
 输出: 4
 输入: [2,7,9,3,1]
 输出: 12
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        vector<int> dp(nums.size()+1, 0);
        dp[1] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            dp[i+1] = max(dp[i-1]+nums[i], dp[i]);
        }
        
        return dp[nums.size()];
    }
};
