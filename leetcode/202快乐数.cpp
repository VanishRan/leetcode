//
//  202快乐数.cpp
//  leetcode
//
//  Created by ran on 2019/12/15.
//  Copyright © 2019 mahuanran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
        map<int,bool> mp;
        int t1 = n;
        while (t1!=1) {
            
            int sum = 0;
            int t2 = t1;
            while (t2) {
                int tmp = t2 % 10;
                sum = sum + tmp * tmp;
                t2 = t2 / 10;
            }
        
            if (mp[sum] == true) {
                return false;
            }
            mp[sum] = true;
            
            t1 = sum;
        }
        
        return true;
    }
};

//int main(int argc, const char * argv[]) {
//    Solution s;
//    cout<<s.isHappy(2)<<endl;
//
//    return 0;
//}

