//
//  128最长连续序列.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/29.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "set"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for (int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }
        
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            if (!s.count(nums[i]-1)) {
                int n = nums[i];
                int cnt = 0;
                while (s.count(n)) {
                    cnt++;
                    n++;
                }
                
                res = max(res, cnt);
            }
        }
        
        return res;
    }
};

/*

 给定一个未排序的整数数组，找出最长连续序列的长度。

 要求算法的时间复杂度为 O(n)。

 示例:

 输入: [100, 4, 200, 1, 3, 2]
 输出: 4
 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 */
