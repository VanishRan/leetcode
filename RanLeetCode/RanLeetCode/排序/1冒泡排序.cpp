//
//  1冒泡排序.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/6/14.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

// 4,3,2,1,6,6,6,6,6
//力扣912
//时间复杂度 n^2

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int k = nums.size() - 1;
        int pos = 0;
        for (int i=nums.size()-1; i>0; i--) {
            bool hasSwap; //优化1:整体有序
            
            for (int j=0; j<k; j++) {
                if (nums[j] > nums[j+1]) {
                    hasSwap = true;
                    //交换
                    int t = nums[j+1];
                    nums[j+1] = nums[j];
                    nums[j] = t;
                    
                    //最后一次交换的位置
                    pos = j; //优化2:局部有序
                }
            }
            
            if (!hasSwap) {
                break;
            }
            
            k = pos;
        }
        
        return nums;
    }
};
