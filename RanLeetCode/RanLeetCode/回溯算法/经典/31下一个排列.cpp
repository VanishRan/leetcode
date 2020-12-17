//
//  31下一个排列.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/21.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
 12385764
 
            8
                    7
                        6
                5
                            4
        3
     2
  1
 
 1.先找到最后一处升序对（i,j）
 2.[j,end]  从后往前找到第一个比i大的数， 交换
 3.[j,end]  反转成升序

 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 0)
            return;
        
        int i = nums.size()-2;
        while (i >= 0) {
            if (nums[i] < nums[i+1])
                break;
            i--;
        }
        
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j = nums.size()-1;
        while (j > i) {
            //如果比nums[i]大 则交换
            if (nums[j] > nums[i]) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                break;
            }
            j--;
        }
        
        reverse(nums.begin()+i+1, nums.end());
    }
};

/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
