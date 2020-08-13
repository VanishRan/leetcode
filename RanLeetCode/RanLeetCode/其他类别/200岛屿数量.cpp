//
//  200岛屿数量.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/9.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//深度优先遍历
//下次打一个广度优先遍历
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        int res = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col) {
        //该位置已经遍历
        grid[row][col] = '0';
        
        //上下左右
        vector<int> stepX = {-1, 1, 0, 0};
        vector<int> stepY = {0, 0, 1, -1};
        for (int i=0; i<4; i++) {
            int x = row + stepX[i];
            int y = col + stepY[i];
            if (x >= 0 && x < grid.size() &&
                y >= 0 && y < grid[0].size() &&
                grid[x][y] == '1') {
                dfs(grid, x, y);
            }
        }
    }
};

/*

 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

 此外，你可以假设该网格的四条边均被水包围。

  

 示例 1:

 输入:
 [
 ['1','1','1','1','0'],
 ['1','1','0','1','0'],
 ['1','1','0','0','0'],
 ['0','0','0','0','0']
 ]
 输出: 1
 示例 2:

 输入:
 [
 ['1','1','0','0','0'],
 ['1','1','0','0','0'],
 ['0','0','1','0','0'],
 ['0','0','0','1','1']
 ]
 输出: 3
 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
 */
