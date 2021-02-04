//
//  49字母异位词分组.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/25.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,int> mp; //存res数组的索引 灵性
        vector<vector<string>> res;
        int idx = 0;
        for (int i=0; i<strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end()); //⚠️
            
            if (mp.count(s) > 0) {
                res[mp[s]].push_back(strs[i]);
            } else {
                vector<string> v;
                v.push_back(strs[i]);
                mp[s] = idx++;
                res.push_back(v);
            }
        }
        
        return res;
    }
};


/*
 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

 示例:

 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 输出:
 [
   ["ate","eat","tea"],
   ["nat","tan"],
   ["bat"]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/group-anagrams
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
