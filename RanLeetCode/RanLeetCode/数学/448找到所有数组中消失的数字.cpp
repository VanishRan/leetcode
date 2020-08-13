//
//  448找到所有数组中消失的数字.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/18.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "math.h"
//数字和索引的关系
// [4,3,2,7,8,2,3,1]
// [-4,-3,-2,-7,8,2,-3,-1]
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            int t = fabs(nums[i]);
            if (nums[t-1] > 0) {
                nums[t-1] = nums[t-1] * -1;
            }
        }
        
        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i+1);
            }
        }
        
        return res;
    }
};

//int main() {
//    vector<int> t =  {4,3,2,7,8,2,3,1};
//    Solution s;
//    s.findDisappearedNumbers(t);
//}
/*
 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

 找到所有在 [1, n] 范围之间没有出现在数组中的数字。

 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

 示例:

 输入:
 [4,3,2,7,8,2,3,1]

 输出:
 [5,6]

 */
