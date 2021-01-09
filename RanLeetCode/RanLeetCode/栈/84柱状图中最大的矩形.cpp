//
//  84柱状图中最大的矩形.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/12.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "stack"

/*
    
单调栈 找右边第一个比自己小的数
单调栈 找左边第一个比自己小的数
以第i根柱子为最矮柱子所能延伸的最大面积 area[i] = (right[i] - left[i] -1) * heights[i]
 
             2               1             5            6              2               3
 rStack      [2]            [1]            [2,5]        [2,6]          [2]             [3]
 r            1              6             4            4              6               6
 lStack      [2]            [1]            [1,5]        [1,5,6]        [1,2]           [1,2,3]
 l            -1             -1             1           2              1               4
 
 res          2              6              10          6              8               3
 
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> r (n,0);
        vector<int> l (n,0);
        stack<int>  rStack;
        stack<int>  lStack;
        
        for (int i=n-1; i>=0; i--) {
            while (!rStack.empty() && heights[rStack.top()] >= heights[i]) {
                rStack.pop();
            }
            r[i] = rStack.empty() ? n : rStack.top();
            rStack.push(i);
        }
        
        
        for (int i=0; i<n; i++) {
            while (!lStack.empty() && heights[lStack.top()] >= heights[i]) {
                lStack.pop();
            }
            l[i] = lStack.empty() ? -1 : lStack.top();
            lStack.push(i);
        }
        
        int res = 0;
        for (int i=0; i<n; i++) {
            res = max(res, (r[i] - l[i] -1) * heights[i]);
        }
        
        return res;
     }
};

//int main() {
//    vector<int> t = {2,1,5,6,2,3};
//    Solution s;
//    s.largestRectangleArea(t);
//}


/*
 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

 求在该柱状图中，能够勾勒出来的矩形的最大面积。


 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
      1
    1 1
    1 1
    1 1   1
1   1 1 1 1
1 1 1 1 1 1

 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。



 */
