//
//  8字符串转换整数 (atoi).cpp
//  RanLeetCode
//
//  Created by mahuanran on 2021/1/9.
//  Copyright © 2021 mahuanran. All rights reserved.
//

#include "common.h"

//好艰难的题
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (s[i] == ' ') i++;

        int flag = 1;
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            i++;
            flag = -1;
        }

        long res = 0;
        for (;i<s.length();i++) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                res = res * 10 + (ch - '0');
                if (res > INT_MAX)
                    break;
            } else {
                break;
            }
        }

        res = res * flag;
        if (INT_MAX < res) return INT_MAX;
        if (INT_MIN > res) return INT_MIN;
        return res;
    }
};
