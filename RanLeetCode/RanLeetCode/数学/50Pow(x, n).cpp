//
//  50Pow(x, n).cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/25.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//again

/*
   递归法
   x^77 <- x^38 <- x^19 <- x^9 <- x^4 <- x^2 <- x^1 <- x^0
 */
class Solution {
public:
    double myPow(double x, int n) {
        long t = n;
        return t >= 0 ? func(x, t) : 1 / func(x, -t);
    }
    
    double func(double x, long n) {
        if (n == 0) {
            return 1.0;
        }
        
        double y = func(x, n/2);
        return n % 2 == 0 ? y * y : y * y * x;
    }
};


/*
 实现 pow(x, n) ，即计算 x 的 n 次幂函数。

 示例 1:

 输入: 2.00000, 10
 输出: 1024.00000
 示例 2:

 输入: 2.10000, 3
 输出: 9.26100
 示例 3:

 输入: 2.00000, -2
 输出: 0.25000
 解释: 2-2 = 1/22 = 1/4 = 0.25
 说明:

 -100.0 < x < 100.0
 n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/powx-n
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
