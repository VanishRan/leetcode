//
//  162寻找峰值.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/8.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
 首先要注意题目条件，在题目描述中出现了 nums[-1] = nums[n] = -∞，这就代表着 只要数组中存在一个元素比相邻元素大，那么沿着它一定可以找到一个峰值
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (mid+1 < len && nums[mid] <= nums[mid+1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

        }
        
        return left;
    }
};

/*
 峰值元素是指其值大于左右相邻值的元素。

 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

 你可以假设 nums[-1] = nums[n] = -∞。

 示例 1:

 输入: nums = [1,2,3,1]
 输出: 2
 解释: 3 是峰值元素，你的函数应该返回其索引 2。
 示例 2:

 输入: nums = [1,2,1,3,5,6,4]
 输出: 1 或 5
 解释: 你的函数可以返回索引 1，其峰值元素为 2；
      或者返回索引 5， 其峰值元素为 6。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/find-peak-element
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
