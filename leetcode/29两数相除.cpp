//
//  29两数相除.cpp
//  leetcode
//
//  Created by ran on 2019/12/15.
//  Copyright © 2019 mahuanran. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            return INT_MAX;
        }
        
        // 10 / 3 = 3 。。。1
        // 3 * 2^n <= 10
        return 0;
    }
};
//-2147483648
//int main(int argc, const char * argv[]) {
//    Solution s;
//    cout<<s.divide(-2147483648,-1)<<endl;
//
//    return 0;
//}
