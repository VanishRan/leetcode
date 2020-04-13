//
//  面试题40最小的k个数.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/31.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        for (int i=k; i<arr.size(); i++) {
            int tmp = i;
            for (int j=k-1; j>=0; j--) {
                if (arr[tmp] >= arr[j])
                    break;
                
                    swap(arr[j], arr[tmp]);
                    tmp = j;
                
                
            }
        }
    
        return arr;
    }
};

//int main(int argc, const char * argv[]) {
//    
//    
//    Solution s;
//
//    
//    return 0;
//}
