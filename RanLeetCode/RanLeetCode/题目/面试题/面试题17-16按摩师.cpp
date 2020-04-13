//
//  面试题17-16按摩师.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/31.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//这道题在搞搞。再好好理解一下状态转移方程
class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (i == 1) {
                dp[i] = max(nums[0],nums[1]);
            } else {
                dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
            }
        }
        
        return dp[nums.size()-1];
    }
};


//int main(int argc, const char * argv[]) {
//    vector<int> a = {2,1,4,5,3,1,1,3};
//    Solution s;
//
//    cout<<s.massage(a)<<endl;
//
//    return 0;
//}
