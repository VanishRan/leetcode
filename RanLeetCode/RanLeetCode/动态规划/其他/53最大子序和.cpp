//
//  53最大子序和.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/3.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 输入: [-2,1,-3,4,-1,2,1,-5,4],
 输出: 6
 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        }
        
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxSum = nums[0];
        for (int i=1; i<nums.size(); i++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            maxSum = max(dp[i], maxSum);
        }
        
        return maxSum;
    }
};
