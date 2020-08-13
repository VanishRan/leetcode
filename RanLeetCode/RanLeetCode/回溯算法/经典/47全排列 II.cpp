//
//  47全排列 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/25.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backTrack(nums, path, used);
        return res;
    }
    
    void backTrack(vector<int>& nums, vector<int> path, vector<bool> used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        //⚠️精髓啊
        //1 nums[i-1] 没用过 说明回溯到了同一层 此时接着用num[i] 则会与 同层用num[i-1] 重复
        //2 nums[i-1] 用过了 说明此时在num[i-1]的下一层 相等不会重复
        for (int i=0; i<nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
                continue;//跳过
            }
                        
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                backTrack(nums, path, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    
};

//int main() {
//    Solution s;
//    vector<int> t = {1,1,2};
//    s.permuteUnique(t);
//}


/*
 
 给定一个可包含重复数字的序列，返回所有不重复的全排列。

 示例:

 输入: [1,1,2]
 输出:
 [
   [1,1,2],
   [1,2,1],
   [2,1,1]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/permutations-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */
