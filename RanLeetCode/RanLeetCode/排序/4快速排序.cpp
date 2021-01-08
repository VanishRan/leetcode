//
//  4快速排序.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/12/27.
//  Copyright © 2020 mahuanran. All rights reserved.
//

//https://leetcode-cn.com/problems/sort-an-array/solution/fu-xi-ji-chu-pai-xu-suan-fa-java-by-liweiwei1419/
//https://leetcode-cn.com/problems/sort-an-array/solution/c-ge-chong-jie-fa-tong-pai-xu-zui-kuai-by-da-li-wa/
#include "common.h"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(0, nums.size()-1, nums);
        return nums;
    }
    
    void quickSort(int l, int r, vector<int>& nums) {
        if (l >= r)
            return;
        
        //取中间数当主元
        int m = (l + r) / 2;
        swap(nums[m], nums[r]);
        int t = partition(l, r, nums); //⚠️吧主元的位置返回
        
        quickSort(l, t-1, nums); //⚠️t-1
        quickSort(t+1, r, nums);
    }

    //把小于主元的放在左边,把大于主元的放在右边
    int partition(int l, int r, vector<int>& nums) {
        int t = l;
        for (int i=l; i<r; i++) {
            if (nums[i] < nums[r]) {
                swap(nums[t++], nums[i]);
            }
        }
        swap(nums[t], nums[r]);
        return t;
    }
};
//
//int main() {
//    Solution s;
//    vector<int> t = {5,1,1,2,0,0};
//    s.sortArray(t);
//}
