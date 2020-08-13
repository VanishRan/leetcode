//
//  59螺旋矩阵 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/26.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n, vector<int>(n,0));
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        int ans = 1;
        while(1) {
            //右
            for (int j=left; j<=right; j++)
                res[top][j] = ans++;
            if (++top > bottom) break;
            
            //下
            for (int i=top; i<=bottom; i++)
                res[i][right] = ans++;
            if (--right < left) break;  //这里
            
            //左
            for (int j=right; j>=left; j--)
                res[bottom][j] = ans++;
            if (--bottom < top) break; //这里
            
            //上
            for (int i=bottom; i>=top; i--)
                res[i][left] = ans++;
            if (++left > right) break;
        }
        
        return res;
    }
};

//int main() {
//    Solution s;
//    s.generateMatrix(3);
//}
/*
 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

 示例:

 输入: 3
 输出:
 [
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
 ]

 */
