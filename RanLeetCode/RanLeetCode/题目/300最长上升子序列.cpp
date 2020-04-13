//
//  300最长上升子序列.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/25.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

//方法1:动态规划   方法2：动态规划+二分查找 下次研究一下
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        vector<int> dp(nums.size(),1);
        int res = 1;
        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i;j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j]+1, dp[i]);
                    res = max(dp[i], res);
                }
            }
        }
        
        return res;
    }
};

//输入: [10,9,2,5,3,7,101,18]
//输出: 4
//int main(int argc, const char * argv[]) {
//    vector<int> tmp(8,0);
//    tmp[0] = 10;
//    tmp[1] = 9;
//    tmp[2] = 2;
//    tmp[3] = 5;
//    tmp[4] = 3;
//    tmp[5] = 7;
//    tmp[6] = 101;
//    tmp[7] = 18;
//    //tmp[8] = 6;
//    Solution s;
//
//    cout<<s.lengthOfLIS(tmp)<<endl;
//
//    return 0;
//}
