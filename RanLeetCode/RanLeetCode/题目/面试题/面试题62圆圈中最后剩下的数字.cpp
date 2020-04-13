//
//  面试题62圆圈中最后剩下的数字.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/30.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//
//class Solution {
//public:
//    int lastRemaining(int n, int m) {
//        vector<int> v;
//        for (int i=0; i<n; i++) {
//            v.push_back(i);
//        }
//        
//        int idx = 0;
//        while (v.size() > 1) {
//            int t = (idx+m-1) % v.size();
//            if (v[t] != -1) {
//                v[t] = -1;
//            }
//           
//        }
//    }
//};
