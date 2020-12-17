//
//  216组合总和 III.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/29.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        backTrack(k, n, 1, 0, path);
        return res;
    }
    
    void backTrack(int k, int n, int begin, int sum, vector<int> path) {
        if (sum > n)
            return;
        
        if (path.size() == k) {
            if (sum == n) {
                res.push_back(path);
            }
            return;
        }
        
        if (begin >= 10)
            return;
        
        for (int i=begin; i<=9; i++) {
            path.push_back(i);
            backTrack(k, n, i+1, sum+i, path);
            path.pop_back();
        }
    }
};

/*
 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

 说明：

 所有数字都是正整数。
 解集不能包含重复的组合。
 示例 1:

 输入: k = 3, n = 7
 输出: [[1,2,4]]
 示例 2:

 输入: k = 3, n = 9
 输出: [[1,2,6], [1,3,5], [2,3,4]]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/combination-sum-iii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
