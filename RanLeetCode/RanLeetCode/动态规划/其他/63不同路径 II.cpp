//
//  63不同路径 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/1.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/* 官方答案
 class Solution {
 public:
     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
         vector <int> f(m);

         f[0] = (obstacleGrid[0][0] == 0);
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < m; ++j) {
                 if (obstacleGrid[i][j] == 1) {
                     f[j] = 0;
                     continue;
                 }
                 if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                     f[j] += f[j - 1];
                 }
             }
         }

         return f.back();
     }
 };
 
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> path(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++) {
            if (obstacleGrid[i][0] == 1)
                break;
            path[i][0] = 1;
        }
        
        for(int j=0; j<n; j++) {
            if (obstacleGrid[0][j] == 1)
                break;
            path[0][j] = 1;
        }
        
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if (obstacleGrid[i][j] == 1)
                    continue;
                
                int sum = 0;
                if (obstacleGrid[i-1][j] == 0)
                    sum += path[i-1][j];
                if (obstacleGrid[i][j-1] == 0)
                    sum += path[i][j-1];
                path[i][j] = sum;
            }
        }
        
        return path[m-1][n-1];
    }
};

/*
 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



 网格中的障碍物和空位置分别用 1 和 0 来表示。

 说明：m 和 n 的值均不超过 100。

 示例 1:

 输入:
 [
   [0,0,0],
   [0,1,0],
   [0,0,0]
 ]
 输出: 2
 解释:
 3x3 网格的正中间有一个障碍物。
 从左上角到右下角一共有 2 条不同的路径：
 1. 向右 -> 向右 -> 向下 -> 向下
 2. 向下 -> 向下 -> 向右 -> 向右

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/unique-paths-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
