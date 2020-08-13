//
//  39组合总和.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/12.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backTrack(candidates, target, path, 0, 0);
        return res;
    }
    
    void backTrack(vector<int>& candidates, int target, vector<int>path, int sum, int begin)  {
        if (sum > target) {
            return;
        }
        
        if (sum == target) {
            res.push_back(path);
            return;
        }
        
        for (int i=begin; i<candidates.size(); i++) {
            path.push_back(candidates[i]);
            backTrack(candidates, target, path, sum+candidates[i], i);
            path.pop_back();
        }
    }
};

/*
 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

 candidates 中的数字可以无限制重复被选取。

 说明：

 所有数字（包括 target）都是正整数。
 解集不能包含重复的组合。
 示例 1:

 输入: candidates = [2,3,6,7], target = 7,
 所求解集为:
 [
   [7],
   [2,2,3]
 ]
 示例 2:

 输入: candidates = [2,3,5], target = 8,
 所求解集为:
 [
   [2,2,2,2],
   [2,3,3],
   [3,5]
 ]

 */
