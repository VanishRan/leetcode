//
//  69x 的平方根.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/9.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int res = 0;
        while (left <= right) {
            long mid = (left + right) / 2;
            long tmp = mid * mid;
            if (tmp <= x) {
                res = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return res;
    }
};
