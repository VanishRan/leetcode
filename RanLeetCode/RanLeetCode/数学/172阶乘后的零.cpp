//
//  172阶乘后的零.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/6.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//有点难
//方法： 5的个数
// 每隔 5 个数，出现一个 5，每隔 25 个数，出现 2 个 5，每隔 125 个数，出现 3 个 5... 以此类推。
// res = n/5 + n /25 + n/125 ....
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n) {
            count += n/5;
            n /= 5;
        }
        return count;
    }
};

/*
 给定一个整数 n，返回 n! 结果尾数中零的数量。

 示例 1:

 输入: 3
 输出: 0
 解释: 3! = 6, 尾数中没有零。
 示例 2:

 输入: 5
 输出: 1
 解释: 5! = 120, 尾数中有 1 个零.
 说明: 你算法的时间复杂度应为 O(log n) 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/factorial-trailing-zeroes
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
