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

/*
 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

 说明：

 拆分时可以重复使用字典中的单词。
 你可以假设字典中没有重复的单词。
 示例 1：

 输入: s = "leetcode", wordDict = ["leet", "code"]
 输出: true
 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 示例 2：

 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 输出: true
 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
      注意你可以重复使用字典中的单词。
 示例 3：

 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 输出: false

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/word-break
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
