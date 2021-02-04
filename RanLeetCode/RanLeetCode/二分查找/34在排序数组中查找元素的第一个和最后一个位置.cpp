//
//  34在排序数组中查找元素的第一个和最后一个位置.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/13.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//记住模版呀
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(left_search(nums, target));
        res.push_back(right_search(nums, target));
        return res;
    }
    
    int left_search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) { //⚠️
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                right = mid - 1;//⚠️
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        
        if (left >= nums.size() || nums[left] != target) { //⚠️
            return -1;
        }
        
        return left;
    }
    
    int right_search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) { //⚠️
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                left = mid + 1; //⚠️
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        
        if (right < 0 || nums[right] != target) {//⚠️
            return -1;
        }
        
        return right;
    }
};

/*
 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

 你的算法时间复杂度必须是 O(log n) 级别。

 如果数组中不存在目标值，返回 [-1, -1]。

 示例 1:

 输入: nums = [5,7,7,8,8,10], target = 8
 输出: [3,4]
 示例 2:

 输入: nums = [5,7,7,8,8,10], target = 6
 输出: [-1,-1]


 */
