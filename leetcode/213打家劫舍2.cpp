//
//  213打家劫舍2.cpp
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
//拆成2条 dp
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
        
        vector<int> dp1(nums.size());
        vector<int> dp2(nums.size());
        
        dp1[0] = nums[0];
        dp1[1] = max(nums[1], nums[0]);
        int i = 2;
        for (; i<nums.size()-1; i++) {
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i]);
        }
        
        dp2[1] = nums[1];
        dp2[2] = max(nums[2], nums[1]);
        i = 3;
        for (; i<nums.size(); i++) {
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i]);
        }
        
        return max(dp2[i-1], dp1[i-2]);
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
