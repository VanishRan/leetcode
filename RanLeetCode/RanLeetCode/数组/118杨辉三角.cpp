//
//  118杨辉三角.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows <= 0)
            return res;

        vector<int> pre(1, 1);
        res.push_back(pre);

        for (int i=2;  i<=numRows; i++) {
            vector<int> cur(i, 1);
            for (int j=1;  j<i-1; j++) {
                int sum = pre[j-1] + pre[j];
                cur[j] = sum;
            }
            res.push_back(cur);
            pre = cur;
        }

        return res;
    }
};
