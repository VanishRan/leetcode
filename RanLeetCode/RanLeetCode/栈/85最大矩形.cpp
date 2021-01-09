//
//  85最大矩形.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/6/21.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/*
 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
      1
    1 1
    1 1
    1 1   1
1   1 1 1 1
1 1 1 1 1 1

 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

 右单调栈，求右边第一个比自己小的数
 左单调栈，求左边第一个比自己小的数
 maxArea = max(maxArea, (r[i] - l[i] -1) * height[i])
 
     2      1       5       6       2       3
 --------------------------------------------------
 r   1      6       4       4       6       6
 --------------------------------------------------
 rs  2      1       5       6       2       3
                    2       2
 --------------------------------------------------
 l   -1     -1      1       2       1       4
 --------------------------------------------------
 ls  2      1       5       6       2       3
                    1       5       1       2
                            1               1
                        
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        //遍历每一行，调用84题求柱状图中的最大矩形
        int res = 0;
        vector<int> height(col, 0);   //不要放在第一层循环里面
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            
            res = max(res, maxFunc(height));
        }
        
        return res;
    }
    
    int maxFunc(vector<int> heights) {
        int len = heights.size();
        stack<int> rStack;
        stack<int> lStack;
        vector<int> r(len, 0);
        vector<int> l(len, 0);
        
        //求右单调栈, 单调递减
        for (int i=len-1; i>=0; i--) {
            while (!rStack.empty() && heights[rStack.top()] >= heights[i]) {
                rStack.pop();
            }
            
            r[i] = rStack.empty() ? len : rStack.top();
            rStack.push(i);
        }
        
        //求左单调栈，单调递减
        for (int i=0; i<len; i++) {
            while (!lStack.empty() && heights[lStack.top()] >= heights[i]) {
                lStack.pop();
            }
            
            l[i] = lStack.empty() ? -1 : lStack.top();
            lStack.push(i);
        }
        
        //求最大矩形
        int res = 0;
        for (int i=0; i<len; i++) {
            res = max(res, (r[i] - l[i] - 1) * heights[i]);
        }
        
        return res;
    }
};


/*
 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

 示例:

 输入:
 [
   ["1","0","1","0","0"],
   ["1","0","1","1","1"],
   ["1","1","1","1","1"],
   ["1","0","0","1","0"]
 ]
 输出: 6
 */
