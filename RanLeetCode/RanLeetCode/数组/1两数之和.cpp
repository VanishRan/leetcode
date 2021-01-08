//
//  1两数之和.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/12/30.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            if (mp.find(target-nums[i]) != mp.end()) {
                res.push_back(mp[target-nums[i]]);
                res.push_back(i);
                return res;
            } else {
                mp[nums[i]] = i;
            }
        }

        return res;
    }
};
