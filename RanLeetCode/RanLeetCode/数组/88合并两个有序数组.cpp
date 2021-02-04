//
//  88合并两个有序数组.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/26.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//从后往前
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t1 = m-1;
        int t2 = n-1;
        for (int i=m+n-1; i>=0; i--) {
            if (t1 >= 0 && t2 >= 0) {
                nums1[i] = nums1[t1] >= nums2[t2] ? nums1[t1--] : nums2[t2--];
            } else if (t1 >= 0) {
                nums1[i] = nums1[t1--];
            } else {
                nums1[i] = nums2[t2--];
            }
        }
    }
};

/*
 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

  

 说明:

 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
  

 示例:

 输入:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3

 输出: [1,2,2,3,5,6]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/merge-sorted-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
