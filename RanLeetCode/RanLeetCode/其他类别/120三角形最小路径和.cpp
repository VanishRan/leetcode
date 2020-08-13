//
//  120三角形最小路径和.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//方法1:回溯法 超时
//class Solution {
//public:
//    int res;
//public:
//    int minimumTotal(vector<vector<int>>& triangle) {
//        res = INT_MAX;
//        backTrack(triangle, 0, 0, 0);
//        return res;
//    }
//
//    void backTrack(vector<vector<int>>& triangle, int row, int sum, int idx) {
//        if (row >= triangle.size()) {
//            res = min(res, sum);
//            return;
//        }
//
//        for (int i=idx; i<=idx+1 && i<triangle[row].size(); i++) {
//            backTrack(triangle, row+1, sum+triangle[row][i], i);
//        }
//    }
//};


/*解法2：动态规划
定义二维 dp 数组，将解法二中「自顶向下的递归」改为「自底向上的递推」。

1、状态定义：
dp[i][j]dp[i][j] 表示从点 (i, j)(i,j) 到底边的最小路径和。

2、状态转移：
dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j] */


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        for (int i=row-2; i>=0; i--) {
            for (int j=0; j<triangle[i].size(); j++) {
                triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};


/*
 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

  

 例如，给定三角形：

 [
      [2],
     [3,4],
    [6,5,7],
   [4,1,8,3]
 ]
 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/triangle
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
