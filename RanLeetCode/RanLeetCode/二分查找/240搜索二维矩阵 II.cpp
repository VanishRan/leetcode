//
//  4寻找两个正序数组的中位数.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/15.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//时间复杂度 m+n
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //左下角开始 牛牛牛
        
        int i = matrix.size()-1;
        int j = 0;
        
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] == target)
                return true;
            
            if (matrix[i][j] < target) {
                j++;
            } else if (matrix[i][j] > target) {
                i--;
            }
        }
        
        return false;
    }
};

/*
 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

 每行的元素从左到右升序排列。
 每列的元素从上到下升序排列。
 示例:

 现有矩阵 matrix 如下：

 [
   [1,   4,  7, 11, 15],
   [2,   5,  8, 12, 19],
   [3,   6,  9, 16, 22],
   [10, 13, 14, 17, 24],
   [18, 21, 23, 26, 30]
 ]


 */
