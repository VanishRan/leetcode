//
//  75颜色分类.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/18.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

// 输入: [2,0,2,1,1,0]
// 输出: [0,0,1,1,2,2]

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p2 = nums.size()-1;
        int cur = 0;
        while (cur <= p2) {
            if (nums[cur] == 0) {
                swap(nums[p0++], nums[cur++]);
            } else if (nums[cur] == 2) {
                swap(nums[p2--], nums[cur]); //⚠️不要++
            } else {
                cur++;
            }
        }
    }
};

//因为curr左边的值已经扫描过了，所以cur++，而与p2交换的值，curr未扫描，要停下来扫描一下，所以curr不用++。

/*
 定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

 注意:
 不能使用代码库中的排序函数来解决这道题。

 示例:

 输入: [2,0,2,1,1,0]
 输出: [0,0,1,1,2,2]
 进阶：

 一个直观的解决方案是使用计数排序的两趟扫描算法。
 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 你能想出一个仅使用常数空间的一趟扫描算法吗？

 */
