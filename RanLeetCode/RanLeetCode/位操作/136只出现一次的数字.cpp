//
//  136只出现一次的数字.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/18.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/*
 任何数和0做异或运算，结果仍然是原来的数
 任何数和其自身做异或运算
 异或运算满足交换律和结合律
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            res = res ^ nums[i];
        }
        return res;
    }
};

/*
 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

 说明：

 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

 示例 1:

 输入: [2,2,1]
 输出: 1
 示例 2:

 输入: [4,1,2,1,2]
 输出: 4

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/single-number
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
