//
//  153寻找旋转排序数组中的最小值.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/8.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        //如果没旋转
        if (nums.size() == 1 || nums[0] < nums[nums.size()-1]) {
            return nums[0];
        }
        
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            
            if (mid > 0 && nums[mid] < nums[mid-1]) {
                return nums[mid];
            }
            
            if (nums[mid] >= nums[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return 0;
    }
};
