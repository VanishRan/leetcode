//
//  914卡牌分组.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/27.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

//辗转相除法
//求最大公约数 >= 2即可
// 30 % 25 = 5;
// 25 % 5 = 0; -> 5
// 11 % 5 = 1
// 5 % 1 = 0 -> 1
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() <= 1) {
            return false;
        }
        
        map<int, int> mp;
        for (int i=0; i<deck.size(); i++) {
            mp[deck[i]]++;
        }

        vector<int> v;
        for (auto m : mp) {
            v.push_back(m.second);
        }
        
        int g = v[0];
        for (int i=1; i<v.size(); i++) {
            g = gcd(g, v[i]);
        }
        
        return g>=2;
    }
    
    int gcd(int a, int b) {
        int t = a % b;
        return t == 0 ? b : gcd(b, t);
    }
};
