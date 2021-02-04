//
//  169多数元素.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2021/1/17.
//  Copyright © 2021 mahuanran. All rights reserved.
//

#include "common.h"
//投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int vote = 1;
        for (int i=1;i<nums.size();i++) {
            if (vote == 0)
                res = nums[i];

            if (nums[i] != res) {
                vote--;
            } else {
                vote++;
            }
        }
        return res;
    }
};

/*
 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

  

 示例 1：

 输入：[3,2,3]
 输出：3
 示例 2：

 输入：[2,2,1,1,1,2,2]
 输出：2
  

 进阶：

 尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/majority-element
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
