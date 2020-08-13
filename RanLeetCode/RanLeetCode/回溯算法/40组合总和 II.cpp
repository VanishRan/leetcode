//
//  40组合总和 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/25.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<vector<int>> res;
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, target, 0, 0, path);
        return res;
    }
    
    void backTrack(vector<int>& candidates, int target, int begin, int sum, vector<int>path) {
        if (sum == target)
            res.push_back(path);
        
        if (sum > target)
            return;
        
        if (begin >= candidates.size())
            return;
        
        for (int i=begin; i<candidates.size(); i++) {
            if (i>begin && candidates[i] == candidates[i-1]) {
                continue;
            }
            path.push_back(candidates[i]);
            backTrack(candidates, target, i+1, sum+candidates[i], path);
            path.pop_back();
        }
    }
};


/*
 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

 candidates 中的每个数字在每个组合中只能使用一次。

 说明：

 所有数字（包括目标数）都是正整数。
 解集不能包含重复的组合。
 示例 1:

 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 所求解集为:
 [
   [1, 7],
   [1, 2, 5],
   [2, 6],
   [1, 1, 6]
 ]
 示例 2:

 输入: candidates = [2,5,2,1,2], target = 5,
 所求解集为:
 [
   [1,2,2],
   [5]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/combination-sum-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
