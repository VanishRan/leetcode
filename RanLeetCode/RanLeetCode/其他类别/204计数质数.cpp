//
//  204计算质数.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/6.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "math.h"
//again
class Solution {
public:
    int countPrimes(int n) {
        double t = sqrt(n);
        vector<bool> isPrim(n, true);
        for (int i=2; i<=t; i++) {
            if (isPrim[i]) {
                for (int j=2*i; j<n; j+=i) {
                    isPrim[j] = false;
                }
            }
        }
        
        int count = 0;
        for (int i=2; i<n; i++) {
            if (isPrim[i] == true) {
                count++;
            }
        }
        
        return count;
    }
};

//int main() {
//    Solution s;
//    s.countPrimes(10);
//}
/*
 统计所有小于非负整数 n 的质数的数量。

 示例:

 输入: 10
 输出: 4
 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 */
