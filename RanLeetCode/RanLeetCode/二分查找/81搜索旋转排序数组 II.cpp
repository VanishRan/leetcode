//
//  81搜索旋转排序数组 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/1.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//again
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() <= 0)
            return false;
        
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] == target)
                return true;
            
            //10111   11101 分不清左边有序还是右边有序
            while (left < mid && nums[left] == nums[mid]) left++;
            
            if (nums[mid] >= nums[left]) {
                //左边有序
                if (nums[left] <= target && nums[mid] > target) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            } else {
                //右边有序
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return false;;
    }
};

/*
 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

 ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

 示例 1:

 输入: nums = [2,5,6,0,0,1,2], target = 0
 输出: true
 示例 2:

 输入: nums = [2,5,6,0,0,1,2], target = 3
 输出: false
 进阶:

 这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
