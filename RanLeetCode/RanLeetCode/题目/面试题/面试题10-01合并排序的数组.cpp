//
//  面试题10-01合并排序的数组.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/31.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//从后往前   -1很精髓 学习一波～
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int idx = m+n-1;
        int idxa = m-1;
        int idxb = n-1;
        
        while (idxa >= 0 || idxb >= 0) {
            if (idxa == -1) {
                A[idx--] = B[idxb--];
            } else if (idxb == -1) {
                A[idx--] = A[idxa--];
            } else if (A[idxa] >= B[idxb]) {
                A[idx--] = A[idxa--];
            } else {
                A[idx--] = B[idxb--];
            }
        }
        
    }
};

//int main(int argc, const char * argv[]) {
//    vector<int> a = {1,2,4,5,6,0};
//    vector<int> b = {3};
//    Solution s;
//
//    s.merge(a, 5, b, 1);
//
//    return 0;
//}
