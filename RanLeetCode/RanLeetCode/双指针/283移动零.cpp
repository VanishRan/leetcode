//
//  283移动零.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/6/21.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/*
 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

 示例:

 输入: [0,1,0,3,12]
 输出: [1,3,12,0,0]
 说明:

 必须在原数组上操作，不能拷贝额外的数组。
 尽量减少操作次数。
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                nums[left++] = nums[i];  //好像直接交换就可以
            }
        }
        
        for (int i=left; i<nums.size(); i++) {
            nums[i] = 0;
        }
       
    }
};
