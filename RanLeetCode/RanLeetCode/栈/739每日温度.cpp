//
//  739每日温度.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/10.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "stack"

/* 从右往左 单调栈 找右边第一个比自己大的数
         73               74           75       71        69             72        76      73
 stack  [76,75,74,73]     [76,75,74]   [76,75]  [76,72]   [76,72,69]     [76，72]  [76]    [73]
 res      1               1             4       2          1              1         0       0
 
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> idxStack;
        vector<int> res(T.size(), 0);
        for (int i=T.size()-1; i>=0; i--) {
            while (!idxStack.empty() && T[idxStack.top()] <= T[i]) {
                idxStack.pop();
            }
            
            res[i] = idxStack.empty() ? 0 : idxStack.top()-i;
            idxStack.push(i);
        }
        return res;
    }
};

//int main() {
//    Solution s;
//}

/*
 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

 
 */
