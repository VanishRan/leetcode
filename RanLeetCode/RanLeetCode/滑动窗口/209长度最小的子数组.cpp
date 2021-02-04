//
//  209长度最小的子数组.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/8.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int res = INT_MAX;
        int sum = 0;
        while (right < nums.size()) {
            int tmp = nums[right];
            right++;
            
            sum += tmp;
            
            while (left<right && sum >= s) {
                res = min(res, right-left);
                sum -= nums[left];
                left++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

//方法2 前缀和 + 二分查找

/*
 class Solution {
 public:
     int minSubArrayLen(int s, vector<int>& nums) {
         int n = nums.size();
         if (n == 0) {
             return 0;
         }
         int ans = INT_MAX;
         vector<int> sums(n + 1, 0);
         // 为了方便计算，令 size = n + 1
         // sums[0] = 0 意味着前 0 个元素的前缀和为 0
         // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
         // 以此类推
         for (int i = 1; i <= n; i++) {
             sums[i] = sums[i - 1] + nums[i - 1];
         }
         for (int i = 1; i <= n; i++) {
             int target = s + sums[i - 1];
             auto bound = lower_bound(sums.begin(), sums.end(), target);
             if (bound != sums.end()) {
                 ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
             }
         }
         return ans == INT_MAX ? 0 : ans;
     }
 };
 
 为了使用二分查找，需要额外创建一个数组 sums 用于存储数组 nums 的前缀和，其中sums[i] 表示从nums[0] ～ nums[i−1] 的元素和。得到前缀和之后，对于每个开始下标 i，可通过二分查找得到大于或等于 i 的最小下标 bound，使得 sums[bound]-sums[i-1]≥s，并更新子数组的最小长度 此时子数组的长度是 bound−(i−1)）。

 因为这道题保证了数组中每个元素都为正，所以前缀和一定是递增的，这一点保证了二分的正确性。如果题目没有说明数组中每个元素都为正，这里就不能使用二分来查找这个位置了。

 在很多语言中，都有现成的库和函数来为我们实现这里二分查找大于等于某个数的第一个位置的功能，比如 C++ 的 lower_bound
 */

/*
 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

  

 示例：

 输入：s = 7, nums = [2,3,1,2,4,3]
 输出：2
 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
  

 进阶：

 如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
