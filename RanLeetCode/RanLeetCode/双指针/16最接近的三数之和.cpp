//
//  16最接近的三数之和.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/19.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "math.h"
//跟15题有啥区别呢 排序+双指针
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        int minDistance = INT_MAX;
        
        for (int i=0; i<nums.size()-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue; //去重
            }
            //-4 -1 1 2
            int left = i+1;
            int right = nums.size()-1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (fabs(sum - target) < minDistance) {
                    res = sum;
                    minDistance = fabs(sum - target);
                }
                
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    left++;
                    while (left < right && nums[left] == nums[left-1]) left++; //去重
                } else {
                    right--;
                    while (left < right && nums[right] == nums[right+1]) right--; //去重
                }
            }
        }
        
        return res;
    }
};

//int main() {
//    vector<int> t = {-1,2,1,-4};
//    Solution s;
//    s.threeSumClosest(t,1);
//}

/*
 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

  

 示例：

 输入：nums = [-1,2,1,-4], target = 1
 输出：2
 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
  

 提示：

 3 <= nums.length <= 10^3
 -10^3 <= nums[i] <= 10^3
 -10^4 <= target <= 10^4


 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/3sum-closest
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
