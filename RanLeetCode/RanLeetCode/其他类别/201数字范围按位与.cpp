//
//  201数字范围按位与.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/9.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/*
 5    1 1 1
 6    1 1 0
 7    1 0 1
 
 在上面的例子中，在对所有数字执行完与操作以后，剩余的部分是所有这些位字符串的公共前缀。

 这个问题的最终结果由位字符串的公共前缀为左半部分，其余的位为零组成。

 更具体的说，所有这些位字符串的公共前缀也是指定范围的起始和结束编号的公共前缀（即在上面的示例中分别为 9 和 12）。

 因此，我们可以将问题重新表述为：给定两个整数，要求我们找到她们二进制字符串的公共前缀。
 */

//公共前缀
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while (m < n) {
            m >>= 1;
            n >>= 1;
            shift++;
        }
        
        return m << shift;
    }
};

/*
 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

 示例 1:
 
 输入: [5,7]
 输出: 4
 示例 2:

 输入: [0,1]
 输出: 0

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/bitwise-and-of-numbers-range
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
