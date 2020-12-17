//
//  45跳跃游戏 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/9/12.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int end = 0;
        int k = 0;
        
        for(int i=0;i<nums.size()-1;i++) {  //-1
            k = max(nums[i]+i, k);
            if (i == end) {
                res++;
                end = k;
            }
        }
        
        return res;
    }
};

/*

 给定一个非负整数数组，你最初位于数组的第一个位置。

 数组中的每个元素代表你在该位置可以跳跃的最大长度。

 你的目标是使用最少的跳跃次数到达数组的最后一个位置。

 示例:

 输入: [2,3,1,1,4]
 输出: 2
 解释: 跳到最后一个位置的最小跳跃数是 2。
      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 说明:

 假设你总是可以到达数组的最后一个位置。
 */
