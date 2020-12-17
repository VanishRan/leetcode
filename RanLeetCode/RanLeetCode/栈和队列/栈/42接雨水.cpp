//
//  42接雨水.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/12.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "stack"

/*
 动态规划
 
 对于每一列 能接的水， 应该是其 min(左边比它高的最高的墙， 右边比它高的最高的墙)

                [0,1,0,2,1,0,1,3,2,1,2,1]
  
 max_left       [0,1,1,2,2,2,2,3,3,3,3,3]
 max_right      [3,3,3,3,3,3,3,3,2,2,2,0]
 tmp            [0,0,1,0,1,2,1,0,0,1,0,0]
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int len = height.size();
        if (len <= 2) {
            return 0;
        }
        
        vector<int> max_left(len, 0);
        vector<int> max_right(len, 0);
        
        for (int i=1; i<len; i++) {
            max_left[i] = max(max_left[i-1], height[i-1]);
        }
        
        for (int i=len-2; i>=0; i--) {
            max_right[i] = max(max_right[i+1], height[i+1]);
        }
        
        for (int i=1; i<len-1; i++) {
            if (max_left[i] > height[i] && max_right[i] > height[i]) {
                res += min(max_left[i], max_right[i]) - height[i];
            }
        }
        
        return res;
    }
};


/*
 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

 示例:

 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 输出: 6

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/trapping-rain-water
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
