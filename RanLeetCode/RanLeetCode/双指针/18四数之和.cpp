//
//  18四数之和.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/19.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "math.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() <= 3)
            return res;
        
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size()-3; i++) {
            if (i>0 && nums[i] == nums[i-1]) {
                continue; //跳过
            }
            
            for (int j=i+1; j<nums.size()-2; j++) {
                if (j>i+1 && nums[j] == nums[j-1]) {
                    continue; //跳过
                }
                
                int left = j+1;
                int right = nums.size()-1;
                
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> v = {nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(v);
                        
                        while (left < right && nums[left] == nums[left+1]) left++;    //跳过
                        while (left < right && nums[right] == nums[right-1]) right--; //跳过
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
                
            }
        }
        
        return res;
    }
};

//int main() {
//    vector<int> t = {0,0,0,0};
//
//    Solution s;
//    s.fourSum(t,0);
//}

/*
 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

 注意：

 答案中不可以包含重复的四元组。

 示例：

 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

 满足要求的四元组集合为：
 [
   [-1,  0, 0, 1],
   [-2, -1, 1, 2],
   [-2,  0, 0, 2]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/4sum
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
