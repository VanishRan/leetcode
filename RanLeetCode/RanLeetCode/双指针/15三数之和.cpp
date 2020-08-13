//
//  15三数之和.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/18.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//排序 + 双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        
        //排序 + 双指针
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++) {
            if (nums[i] > 0)
                break;
            
            if (i > 0 && nums[i] == nums[i-1])
                continue; //⚠️去重
            
            int left = i+1;
            int right = nums.size()-1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> tmp = {nums[i], nums[left], nums[right]};
                    res.push_back(tmp);
                    while (left < right && nums[left] == nums[left+1]) { //⚠️去重
                        left++;
                    }
                    while (left < right && nums[right] == nums[right-1]) { //⚠️去重
                        right--;
                    }
                    left++;
                    right--;
                } else if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                }
            }
        }

        return res;
    }
};

//int main() {
//    vector<int> t = {0,0,0,0};
//   
//    Solution s;
//    s.threeSum(t);
//}

/*
 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

 注意：答案中不可以包含重复的三元组。

  

 示例：

 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

 满足要求的三元组集合为：
 [
   [-1, 0, 1],
   [-1, -1, 2]
 ]

 */
