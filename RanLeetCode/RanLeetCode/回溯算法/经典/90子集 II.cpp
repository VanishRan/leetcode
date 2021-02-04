//
//  90子集 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/1.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        backTrack(path, nums, 0);
        return res;
    }
    
    void backTrack(vector<int>path, vector<int>& nums, int begin) {
        res.push_back(path);
        
        if (path.size() == nums.size()) {
            return;
        }
        
        for (int i=begin; i<nums.size(); i++) {
            if (i>begin && nums[i] == nums[i-1]) {
                continue; //跳过
            }
            
            path.push_back(nums[i]);
            backTrack(path, nums, i+1);
            path.pop_back();
        }
    }
};


/*
 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

 说明：解集不能包含重复的子集。

 示例:

 输入: [1,2,2]
 输出:
 [
   [2],
   [1],
   [1,2,2],
   [2,2],
   [1,2],
   []
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/subsets-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
