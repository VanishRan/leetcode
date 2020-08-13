//
//  78子集.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/12.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/*
              []
        /      |       \
      [1]     [2]      [3]
      /\       |
 [1,2]  [1,3] [2,3]
   |
 [1,2,3]
 
 */

//https://mp.weixin.qq.com/s/qT6WgR6Qwn7ayZkI3AineA
//排列 组合 子集

class Solution {
public:
    vector<vector<int>> res;
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtrack(nums, path, 0);
        return res;
    }
    
    void backtrack(vector<int> nums, vector<int>path, int begin) {
        res.push_back(path);
        
        for (int i=begin; i<nums.size(); i++) {
            path.push_back(nums[i]);
            
            backtrack(nums, path, i+1);
            
            path.pop_back();
        }
    }
};


/*
 输入: nums = [1,2,3]
 输出:
 [
   [3],
   [1],
   [2],
   [1,2,3],
   [1,3],
   [2,3],
   [1,2],
   []
 ]

 */
