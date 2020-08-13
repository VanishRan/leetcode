//
//  46全排列.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/12.
//  Copyright © 2020 mahuanran. All rights reserved.
//


#include "common.h"
//时间复杂度：
//O(N^(N+1))
//https://mp.weixin.qq.com/s/qT6WgR6Qwn7ayZkI3AineA
//排列 组合 子集
class Solution {
public:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        backTrack(nums, path);
        return res;
    }
    
    void backTrack(vector<int> nums, vector<int> path) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (contains(path, nums[i])) {
                continue;
            }
            path.push_back(nums[i]);
            backTrack(nums, path);
            path.pop_back(); //⚠️ 这句别忘记 我去
        }
    }
    
    bool contains(vector<int>path, int num) {
        for (int i=0; i<path.size(); i++) {
            if (path[i] == num) {
                return true;
            }
        }
        return false;
    }
};

//int main() {
//    Solution s;
//    vector<int> t = {1,2,3};
//    s.permute(t);
//}

/*
 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

 示例:

 输入: [1,2,3]
 输出:
 [
   [1,2,3],
   [1,3,2],
   [2,1,3],
   [2,3,1],
   [3,1,2],
   [3,2,1]
 ]

 */
