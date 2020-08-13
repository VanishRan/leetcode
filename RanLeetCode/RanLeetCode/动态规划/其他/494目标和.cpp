//
//  494目标和.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/7.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int res;
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        res = 0;
        traverse(nums, S, 0, 0);
        return res;
    }
    
    void traverse(vector<int>& nums, int S, int idx, int sum) {
        if (idx == nums.size()) {
            if (sum == S) {
                res ++;
            }
            return;
        }
        
        int sum1 = sum + nums[idx];
        int sum2 = sum - nums[idx];
        
        traverse(nums, S, idx+1, sum1);
        traverse(nums, S, idx+1, sum2);
    }
};

//动态规划怎么写啊 我去 ⚠️

/*
 
 
 
 */


/*
 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

 示例 1:

 输入: nums: [1, 1, 1, 1, 1], S: 3
 输出: 5
 解释:

 -1+1+1+1+1 = 3
 +1-1+1+1+1 = 3
 +1+1-1+1+1 = 3
 +1+1+1-1+1 = 3
 +1+1+1+1-1 = 3

 一共有5种方法让最终目标和为3。

 */
