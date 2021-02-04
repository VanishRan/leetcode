//
//  73矩阵置零.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/1.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//方法1: 两个数组： row 和 col， 两次遍历
//方法2: 如果cell[i][j] == 0, 吧同行和同列不等于0 的数设为 INT_MAX之类的， 两次遍历
/* 方法3:
 遍历整个矩阵，如果 cell[i][j] == 0 就将第 i 行和第 j 列的第一个元素标记。
 第一行和第一列的标记是相同的，都是 cell[0][0]，所以需要一个额外的变量告知第一列是否被标记，同时用 cell[0][0] 继续表示第一行的标记。
 然后，从第二行第二列的元素开始遍历，如果第 r 行或者第 c 列被标记了，那么就将 cell[r][c] 设为 0。这里第一行和第一列的作用就相当于方法一中的 row_set 和 column_set 。
 然后我们检查是否 cell[0][0] == 0 ，如果是则赋值第一行的元素为零。
 然后检查第一列是否被标记，如果是则赋值第一列的元素为零。

 */

//again 细节处理
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        //第一列的标记
        bool isCol = false;
        for (int i=0; i<m; i++) {
            if (matrix[i][0] == 0)
                isCol = true;
            
            for (int j=1; j<n; j++) {  //⚠️ 从1开始 [[1,1,1],[0,1,2]]
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        //处理第一行
        if (matrix[0][0] == 0) {
            for (int j=1; j<n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        //处理第一列
        if (isCol) {
            for (int i=0; i<m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

/*
 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

 示例 1:

 输入:
 [
   [1,1,1],
   [1,0,1],
   [1,1,1]
 ]
 输出:
 [
   [1,0,1],
   [0,0,0],
   [1,0,1]
 ]
 示例 2:

 输入:
 [
   [0,1,2,0],
   [3,4,5,2],
   [1,3,1,5]
 ]
 输出:
 [
   [0,0,0,0],
   [0,4,5,0],
   [0,3,1,0]
 ]
 进阶:

 一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 你能想出一个常数空间的解决方案吗？

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/set-matrix-zeroes
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
