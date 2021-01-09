//
//  7整数反转.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2021/1/9.
//  Copyright © 2021 mahuanran. All rights reserved.
//

#include "common.h"

// 7 8 9题都是整数反转
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x) {
            int t = x % 10; //⚠️负数%10还是负数
            x = x / 10;
            res = res * 10 + t;
        }

        if (res > INT_MAX || res < INT_MIN)
            return 0;

        return res;
    }
};
//
//int main() {
//    Solution s;
//    s.reverse(-123);
//}
