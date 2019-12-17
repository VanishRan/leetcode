//
//  171Excel表列序号.cpp
//  leetcode
//
//  Created by ran on 2019/12/15.
//  Copyright © 2019 mahuanran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

//    A -> 1
//    B -> 2
//    C -> 3
//    ...
//    Z -> 26
//    AA -> 27
//    AB -> 28
//    ...


class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i=0; i<s.length(); i++) {
            int t = s[i] - 'A' + 1;
            res = res * 26 + t;
        }
        return res;
    }
};

//int main(int argc, const char * argv[]) {
//    Solution s;
//    cout<<s.titleToNumber("ZY")<<endl;
//
//    return 0;
//}
