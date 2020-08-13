//
//  221最大正方形.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/6/14.
//  Copyright © 2020 mahuanran. All rights reserved.
//

/*
 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

 示例:

 输入:

 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0

 输出: 4

 */

#include "common.h"
#include "math.h"

//dp(i,j)=min(dp(i−1,j),dp(i−1,j−1),dp(i,j−1))+1

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        
        vector<vector<int>> dp (matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxSquare = 0;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    }
                    
                    if (dp[i][j] > maxSquare) {
                        maxSquare = dp[i][j];
                    }
                }
            }
        }
        
        return maxSquare * maxSquare;
    }
};


