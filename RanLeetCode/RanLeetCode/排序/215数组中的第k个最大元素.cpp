//
//  215数组中的第k个最大元素.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2021/2/23.
//  Copyright © 2021 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        quickSort(nums, 0, len-1, len-k);
        return nums[len-k];
    }

    void quickSort(vector<int>& nums, int l, int r, int idx) {
        if (l > r)
            return;

        int mid = (l + r) / 2;
        swap(nums[mid], nums[r]);

        int pos = partition(nums, l, r);
        if (pos == idx) {
            return;
        } else if (pos < idx) {
            quickSort(nums, pos+1, r, idx);
        } else {
            quickSort(nums, l, pos-1, idx);
        }
    }

    int partition(vector<int>& nums, int l, int r) {
        int idx = l;
        for(int i=l; i<r; i++) {
            if (nums[i] < nums[r]) {
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
        swap(nums[idx], nums[r]);
        return idx;
    }
};
