//
//  6归并排序.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/12/27.
//  Copyright © 2020 mahuanran. All rights reserved.
//


#include "common.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        mergeSort(0, len-1, nums);
        return nums;
    }
    
    void mergeSort(int left, int right, vector<int>& nums) {
        if (left == right)
            return;
        
        int mid = left + (right - left) / 2;
        //左边有序
        mergeSort(left, mid, nums);
        //右边有序
        mergeSort(mid+1, right, nums);
        //合并有序数组
        mergeTwoSorted(left, right, mid, nums);
    }
    
    //合并有序数组
    void mergeTwoSorted(int left, int right, int mid, vector<int>& nums) {
        //已经有序
        if (nums[mid] <= nums[mid+1]) {
            return;
        }
        
        int len = right - left + 1;
        int i = left;
        int j = mid+1;
        int k = 0;
        vector<int> tmp(len, 0);
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        
        while (i <= mid) tmp[k++] = nums[i++];
        while (j <= right) tmp[k++] = nums[j++];
        
        for (k=0; k<len; k++)
            nums[left+k] = tmp[k];
    }
};

//int main() {
//    Solution s;
//    vector<int> t = {5,1,1,2,0,0};
//    s.sortArray(t);
//}

/*
 输入：nums = [5,1,1,2,0,0]
 输出：[0,0,1,1,2,5]
 */
