//
//  29两数相除.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/21.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//有点难 再做一遍
class Solution {
public:
    int divide(int dividend, int divisor) {
        
        long a = labs(dividend);
        long b = labs(divisor);
        
        long res = 0;
        
        while (a >= b) {
            long cnt = 1;
            long tmp = b;
            
            while (a >= (tmp << 1)) {
                tmp = tmp << 1;
                cnt = cnt << 1;
            }
            
            res += cnt;
            a -= tmp;
        }
        
        if ((dividend < 0) ^ (divisor < 0)) res = -res;

        if (res > INT_MAX) res = INT_MAX; // INT_MAX = 2^32 - 1

        return res;

    }
};

//int main () {
//    Solution s;
//    s.divide(10, 3);
//}
/*
 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

 返回被除数 dividend 除以除数 divisor 得到的商。

 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

  

 示例 1:

 输入: dividend = 10, divisor = 3
 输出: 3
 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
 示例 2:

 输入: dividend = 7, divisor = -3
 输出: -2
 解释: 7/-3 = truncate(-2.33333..) = -2

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/divide-two-integers
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
