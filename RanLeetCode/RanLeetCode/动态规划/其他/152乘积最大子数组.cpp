//
//  152乘积最大子数组.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/23.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
      2  3  -2  4
imax  2  6  -2  4
imin  2  3  -6  -24
max   2  6  6   6
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        }
        
        int imax = nums[0];
        int imin = nums[0];
        int res = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] < 0) {
                int t = imax;
                imax = imin;
                imin = t;
            }
            
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            res = max(res, imax);
        }
        return res;
    }
};

/*
 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

 示例 1:

 输入: [2,3,-2,4]
 输出: 6
 解释: 子数组 [2,3] 有最大乘积 6。
 示例 2:

 输入: [-2,0,-1]
 输出: 0
 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

 */
