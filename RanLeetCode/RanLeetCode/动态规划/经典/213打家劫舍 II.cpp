//
//  213打家劫舍 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/4.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

 输入: [2,3,2]
 输出: 3
 解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

 输入: [1,2,3,1]
 输出: 4
 解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
      偷窃到的最高金额 = 1 + 3 = 4 。
 */

//拆成两段dp
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        vector<int> dp1(nums.size(),0);
        vector<int> dp2(nums.size(),0);
        dp1[1] = nums[0];
        dp2[1] = nums[1];
        
        //最后一个房子不打劫
        for (int i=1; i<nums.size()-1; i++) {
            dp1[i+1] = max(dp1[i-1]+nums[i], dp1[i]);
        }
        
        //第一个房子不打劫
        for (int i=2; i<nums.size(); i++) {
            dp2[i] = max(dp2[i-2]+nums[i], dp2[i-1]);
        }
        
        return max(dp1[nums.size()-1], dp2[nums.size()-1]);
    }
};

//int main() {
//    vector<int> v = {1,2,3,1};
//    Solution s;
//    cout<<s.rob(v);
//}
