//
//  191位1的个数.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/6.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            if (n&1) {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};

//方法2: n&(n-1)     将 n 和 n - 1 做与运算，会把最后一个 1 的位变成 0
class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count++;
            n = n & (n-1);
        }
        return count;
    }
};

/*
 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。

  

 示例 1：

 输入：00000000000000000000000000001011
 输出：3
 解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
 示例 2：

 输入：00000000000000000000000010000000
 输出：1
 解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
 示例 3：

 输入：11111111111111111111111111111101
 输出：31
 解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/number-of-1-bits
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
