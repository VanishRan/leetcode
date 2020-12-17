//
//  11盛最多水的容器.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/20.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "math.h"
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2)
            return 0;
        
        int left = 0;
        int right = height.size()-1;
        int res = INT_MIN;
        while (left < right) {
            int sum = min(height[right],height[left]) * (right-left);
            res = max(res, sum);
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};

/*
 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

 说明：你不能倾斜容器，且 n 的值至少为 2。

  



 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

  

 示例：

 输入：[1,8,6,2,5,4,8,3,7]
 输出：49

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/container-with-most-water
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
