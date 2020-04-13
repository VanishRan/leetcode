//
//  1013将数组分成和相等的三个部分.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/27.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (int i=0; i<A.size(); i++) {
            sum += A[i];
        }
        
        if (sum % 3 != 0) {
            return false;
        }
        
        int idx1 = 0;
        int idx2 = A.size()-1;
        int tmp1 = 0;
        int tmp2 = 0;
        
        for (; idx1<A.size()-2; idx1++) {
            tmp1 += A[idx1];
            if (tmp1 == sum / 3)
                break;
        }

        for (; idx2>1; idx2--) {
            tmp2 += A[idx2];
            if (tmp2 == sum / 3)
                break;
        }
        
        return idx1 + 1 < idx2;
    }
};
