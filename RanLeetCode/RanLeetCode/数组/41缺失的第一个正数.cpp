//
//  41缺失的第一个正数.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/9/12.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
剑指 Offer 03. 数组中重复的数字
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

 示例 1：

 输入：
 [2, 3, 1, 0, 2, 5, 3]
 输出：2 或 3
 */

/*
 将数组视为哈希表
 
 输入: [3,4,-1,1]
 [3,4,-1,1]
 [-1,4,3,1];
 [-1,1,3,4];
 [1,-1,3,4];
     ^
 
 //                int t = nums[i];
 //                nums[i] = nums[nums[i]-1]; 写错啦 nums[i] 变了 晕
 //                nums[nums[i]-1] = t;
 
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            while (nums[i] >= 1 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != i+1)
                return i+1;
        }
        
        return nums.size()+1;
    }
};

//int main () {
//    Solution s;
//    vector<int> t = {3,4,-1,1};
//    s.firstMissingPositive(t);
//}
/*
 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

  

 示例 1:

 输入: [1,2,0]
 输出: 3
 示例 2:

 输入: [3,4,-1,1]
 输出: 2
 示例 3:

 输入: [7,8,9,11,12]
 输出: 1

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/first-missing-positive
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
