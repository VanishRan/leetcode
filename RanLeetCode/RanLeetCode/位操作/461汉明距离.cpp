//
//  461汉明距离.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/18.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int z = x ^ y;
        
        while(z) {
            int t = z % 2;
            if (t == 1) {
                res++;
            }
            
            z = z / 2;
        }
        return res;
    }
};


/*
 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

 给出两个整数 x 和 y，计算它们之间的汉明距离。

 注意：
 0 ≤ x, y < 231.

 示例:

 输入: x = 1, y = 4

 输出: 2

 解释:
 1   (0 0 0 1)
 4   (0 1 0 0)
        ↑   ↑

 上面的箭头指出了对应二进制位不同的位置。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/hamming-distance
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
