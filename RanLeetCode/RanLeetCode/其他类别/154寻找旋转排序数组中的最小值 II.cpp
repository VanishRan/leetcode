//
//  154寻找旋转排序数组中的最小值 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/8.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        
        //没有旋转
        if (len == 1 || nums[0] < nums[len-1]) {
            return nums[0];
        }
        
        int left = 0;
        int right = len-1;
        int mid = 0;
        while (left <= right) {
            while (left+1<=right && nums[left] == nums[left+1]) {
                left++;
            }
            
            while (right-1>=left && nums[right] == nums[right-1]) {
                right--;
            }
            
            mid = (left + right) / 2;
            
            if (mid > 0 && nums[mid] < nums[mid-1]) {
                break;
            }
            
            if (nums[mid] >= nums[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            
        }
        
        return nums[mid];
    }
};

/*
 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

 ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

 请找出其中最小的元素。

 注意数组中可能存在重复的元素。

 示例 1：

 输入: [1,3,5]
 输出: 1
 示例 2：

 输入: [2,2,2,0,1]
 输出: 0
 说明：

 这道题是 寻找旋转排序数组中的最小值 的延伸题目。
 允许重复会影响算法的时间复杂度吗？会如何影响，为什么？

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
