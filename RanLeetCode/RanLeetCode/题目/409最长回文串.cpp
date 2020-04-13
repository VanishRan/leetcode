//
//  409最长回文串.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/26.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        
        for (int i=0; i<s.length(); i++) {
            mp[s[i]]++;
        }
        
        int res = 0;
        int flag = 0;//有没有奇数
        map<char,int>::iterator iter;
        for (iter = mp.begin(); iter != mp.end(); iter++) {
            int v = iter->second;
            res += v / 2 * 2;
            if (v % 2 == 1)
                flag = 1;
        }
        
        if (flag)
            res++;
        
        return res;
    }
};
