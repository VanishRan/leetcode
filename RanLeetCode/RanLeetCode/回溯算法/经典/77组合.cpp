//
//  77组合.cpp
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
   |⚠️子集的这段不要
 [1,2,3]
 
 */

//https://mp.weixin.qq.com/s/qT6WgR6Qwn7ayZkI3AineA
//排列 组合 子集


class Solution {
public:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        backTrack(n, k, 1, path);
        return res;
    }
    
    void backTrack(int n, int k, int begin, vector<int>path) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        
        for (int i=begin; i<=n; i++) {
            path.push_back(i);
            backTrack(n, k, i+1, path);
            path.pop_back();
        }
    }
};

//int main() {
//    Solution s;
//    s.combine(3, 2);
//}

/*
 输入: n = 4, k = 2
 输出:
 [
   [2,4],
   [3,4],
   [2,3],
   [1,2],
   [1,3],
   [1,4],
 ]
 */
