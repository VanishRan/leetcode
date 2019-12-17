
//
//  198打家劫舍1.cpp
//  leetcode
//
//  Created by ran on 2019/12/16.
//  Copyright © 2019 mahuanran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// [2,7,9,3,1]  前面放个0辅助一波
// dp[i] = max(dp[i-1],dp[i-2]+nums[i])
//  3 1 1 3
//0 3 3 4 6
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        
        vector<int> dp(nums.size()+1);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        int i = 2;
        for (; i<nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        
        return dp[i-1];
    }
};

//int main(int argc, const char * argv[]) {
//    vector<int> nums;
//    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(3);
//    nums.push_back(1);
//    Solution s;
//    cout<<s.rob(nums)<<endl;
//
//    return 0;
//}
