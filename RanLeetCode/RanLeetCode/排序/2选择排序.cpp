//
//  2.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/6/14.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//选择排序：每一轮选择最小元素交换到未排定部分的开头
//时间复杂度 n^2

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i=0; i<nums.size()-1; i++) {
            int minIdx = i;
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[j] < nums[minIdx]) {
                    minIdx = j;
                }
            }
            
            int t = nums[i];
            nums[i] = nums[minIdx];
            nums[minIdx] = t;
        }
        
        return nums;
    }
};
