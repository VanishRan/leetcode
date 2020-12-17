//
//  3插入排序.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/6/14.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//时间复杂度 n^2
//每次将一个数字插入一个有序的数组里，成为一个长度更长的有序数组，有限次操作以后，数组整体有序。

//输入：nums = [5,2,3,1]
//输出：[1,2,3,5]
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        for (int i=1; i<nums.size(); i++) {
            int tmp = nums[i];
            int j = i-1;
            while (j >= 0 && nums[j] > tmp) {
                nums[j+1] = nums[j];
                j--;
            }
            
            nums[j+1] = tmp;
        }
        
        return nums;
    }
};
