//
//  74搜索二维矩阵.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/1.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//方法1:二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int row = matrix.size();
       if (row == 0)
           return false;
       int col = matrix[0].size();
       if (col == 0)
           return false;
        
        int left = 0;
        int right = row * col - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int x = mid / col;
            int y = mid % col;
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

//方法2: 从左下角开始呀 有相似的题？
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0)
            return false;
        int col = matrix[0].size();
        if (col == 0)
            return false;
        
        
        int i = row-1;
        int j = 0;
        
        while (i >= 0 && j < col) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target) {
                j++;
            } else {
                i--;
            }
        }
        return false;
    }
};

/*
 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

 每行中的整数从左到右按升序排列。
 每行的第一个整数大于前一行的最后一个整数。
 示例 1:

 输入:
 matrix = [
   [1,   3,  5,  7],
   [10, 11, 16, 20],
   [23, 30, 34, 50]
 ]
 target = 3
 输出: true
 示例 2:

 输入:
 matrix = [
   [1,   3,  5,  7],
   [10, 11, 16, 20],
   [23, 30, 34, 50]
 ]
 target = 13
 输出: false

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/search-a-2d-matrix
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
