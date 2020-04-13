//
//  169多数元素.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/25.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int res = 0;//出现最多次的数
        int max = INT_MIN;//出现的最大次数
        for (int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
            
            if (mp[nums[i]] > max) {
                res = nums[i];
                max = mp[nums[i]];
            }
        }

        return res;
    }
};

//int main(int argc, const char * argv[]) {
//    vector<int> tmp(3,0);
//    tmp[0] = 3;
//    tmp[1] = 2;
//    tmp[2] = 3;
////    tmp[3] = 3;
////    tmp[4] = 6;
////    tmp[5] = 4;
//    Solution s;
//
//    cout<<s.majorityElement(tmp)<<endl;
//
//    return 0;
//}
