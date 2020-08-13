//
//  64最小路径和.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/23.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        
        dp[0][0] = grid[0][0];
        
        //计算第一列
        for (int i=1; i<grid.size(); i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        //计算第一行
        for (int j=1; j<grid[0].size(); j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        for (int i=1; i<grid.size(); i++) {
            for (int j=1;j<grid[0].size(); j++) {
                int t = grid[i][j];
                dp[i][j] = min(dp[i][j-1]+t, dp[i-1][j]+t);
            }
        }
        
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

/*
 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

 说明：每次只能向下或者向右移动一步。

 示例:

 输入:
 [
   [1,3,1],
   [1,5,1],
   [4,2,1]
 ]
 输出: 7
 解释: 因为路径 1→3→1→1→1 的总和最小。

 */
