//
//  Ran121买卖股票的最佳时机.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/25.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        
        for (int i=0; i<prices.size(); i++) {
            maxProfit = max(prices[i]-minPrice, maxProfit);
            minPrice = min(prices[i], minPrice);
        }
        
        return maxProfit;
    }
};

//int main(int argc, const char * argv[]) {
//    vector<int> tmp(6,0);
//    tmp[0] = 7;
//    tmp[1] = 1;
//    tmp[2] = 5;
//    tmp[3] = 3;
//    tmp[4] = 6;
//    tmp[5] = 4;
//    Solution s;
//
//    cout<<s.maxProfit(tmp)<<endl;
//
//    return 0;
//}

