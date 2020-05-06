//
//  139单词拆分.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/6.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> mp;
        for (int i=0; i<wordDict.size(); i++) {
            mp[wordDict[i]] = true;
        }
        
        vector<bool> dp(s.length(), false);
        for (int i=0; i<s.length(); i++) {
            if (mp[s.substr(0, i+1)] == true) {
                dp[i] = true;
                continue;
            }
            
            for (int j=i-1; j>=0; j--) {
                if (dp[j] == true && mp[s.substr(j+1, i-j)] == true)
                    dp[i] = true;
            }
        }
        
        return dp[s.length()-1];
    }
};
