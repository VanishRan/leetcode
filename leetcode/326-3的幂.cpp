//
//  326-3的幂.cpp
//  leetcode
//
//  Created by mahuanran on 2019/12/17.
//  Copyright © 2019 mahuanran. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
//        if (n==1) {
//            return true;
//        }
//
//        while(n) {
//            if (n%3 != 0) {
//                return false;
//            }
//
//            int t = n/3;
//            if (t == 1) {
//                return true;
//            }
//            n = t;
//        }
//        return false;
        return n > 0 && 1162261467 % n == 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.isPowerOfThree(45)<<endl;

    return 0;
}
