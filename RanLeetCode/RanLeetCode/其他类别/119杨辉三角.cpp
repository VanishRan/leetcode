//
//  119杨辉三角.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> cur(rowIndex+1, 1);

        for (int i=1;  i<=rowIndex; i++) {
            int t1 = 1;
            for (int j=1;  j<i; j++) {
                int t2 = cur[j];
                cur[j] = cur[j] + t1;
                t1 = t2;
            }
        }

        return cur;
    }
};

/*
 0  1  2  3  4  5  6
 
 1
 1  1
 1  2  1
 1  3  3  1
 1  4  6  4  1
 1  5  10 10 5  1
 1  6  15 20 15 6  1
 1  7  21 35 35 21 7  1
 
 
 
 */
