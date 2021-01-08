//
//  5堆排序.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/12/27.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
    
    void heapSort(vector<int>& nums) {
        //构建最大堆,从最后一个非叶子节点开始从上往下调整
        for (int i=nums.size()/2; i>=0; i--) {  //⚠️nums.size()/2
            adjust(nums, i, nums.size());
        }
        
        for (int i=nums.size()-1; i>=0; i--) {
            swap(nums[i], nums[0]);
            adjust(nums, 0, i);
        }
    }

    //从上往下调整
    void adjust(vector<int>& nums, int i, int len) {
        while (2 * i + 1 < len) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int tmp = (r < len && nums[r] > nums[l]) ? r : l;
            if (nums[tmp] > nums[i])
                swap(nums[i], nums[tmp]);
            else
                break;
            
            i = tmp;
        }
    }
};
