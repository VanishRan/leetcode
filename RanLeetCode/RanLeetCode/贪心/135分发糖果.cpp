//
//  135分发糖果.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/30.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
 算法流程：
https://leetcode-cn.com/problems/candy/solution/candy-cong-zuo-zhi-you-cong-you-zhi-zuo-qu-zui-da-/
 先从左至右遍历学生成绩 ratings，按照以下规则给糖，并记录在 left 中：

 1.先给所有学生 1 颗糖；
 2.若 ratings_i>ratings_{i-1}  则第 i 名学生糖比第 i - 1 名学生多 1 个。
 3.若 ratings_i<=ratings_{i-1} 则第 i 名学生糖数量不变。（交由从右向左遍历时处理。）
 
 经过此规则分配后，可以保证所有学生糖数量 满足左规则 。
 同理，在此规则下从右至左遍历学生成绩并记录在 right 中，可以保证所有学生糖数量 满足右规则 。

 最终，取以上 2 轮遍历 left 和 right 对应学生糖果数的 最大值 ，这样则 同时满足左规则和右规则 ，即得到每个同学的最少糖果数量。


 */
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> left(len, 1);
        vector<int> right(len, 1);
        
        for (int i=1; i<len; i++) {
            if (ratings[i] > ratings[i-1])
                left[i] = left[i-1] + 1;
        }
        
        int res = max(left[len-1], right[len-1]);
        
        for (int i=len-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1])
                right[i] = right[i+1] + 1;
            res += max(left[i], right[i]);
        }
        
        return res;
    }
};
