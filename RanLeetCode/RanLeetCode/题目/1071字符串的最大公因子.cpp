//
//  1071字符串的最大公因子.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/27.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int g = gcd(str1.length(), str2.length());
        
        
        for (int i=0; i<str1.length(); i++) {
            int t = i % g;
            if (str1[i] != str1[t]) {
                return "";
            }
        }
        
        for (int i=0; i<str2.length(); i++) {
            int t = i % g;
            if (str2[i] != str2[t]) {
                return "";
            }
        }
        
        string res;
        for (int i=0; i<g; i++) {
            res.push_back(str2[i]);
        }
        
        return res;
    }
    
    int gcd(int a, int b) {
        int t = a % b;
        return t == 0 ? b : gcd(b, t);
    }
};

//int main(int argc, const char * argv[]) {
//    string a = "ABCABC";
//    string b = "ABC";
//    
//    Solution s;
//
//    cout<<s.gcdOfStrings(a,b)<<endl;
//
//    return 0;
//}
