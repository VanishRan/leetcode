//
//  91解码方法.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/1.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int res;
public:
    int numDecodings(string s) {
        map<int, char> mp;
        mp[1] = 'A';  mp[2] = 'B';  mp[3] = 'C';  mp[4] = 'D';
        mp[5] = 'E';  mp[6] = 'F';  mp[7] = 'G';  mp[8] = 'H';
        mp[9] = 'I';  mp[10] = 'J'; mp[11] = 'K'; mp[12] = 'L';
        mp[13] = 'M'; mp[14] = 'N'; mp[15] = 'O'; mp[16] = 'P';
        mp[17] = 'Q'; mp[18] = 'R'; mp[19] = 'S'; mp[20] = 'T';
        mp[21] = 'U'; mp[22] = 'V'; mp[23] = 'W'; mp[24] = 'X';
        mp[25] = 'Y'; mp[26] = 'Z';
        
        res = 0;
        backTrack(s, 0, mp);
        return res;;
    }
    
    void backTrack(string s, int begin, map<int, char> mp) {
        if (begin >= s.length()) {
            res++;
            return;
        }
        
        int i = 2;
        while (i) {
            string t = s.substr(begin,i);
            int n = stoi(t);
            if (mp.count(n)) {
                backTrack(s, begin+i, mp);
            }
            i--;
        }
    }
};



/*
 一条包含字母 A-Z 的消息通过以下方式进行了编码：

 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 给定一个只包含数字的非空字符串，请计算解码方法的总数。

 示例 1:

 输入: "12"
 输出: 2
 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 示例 2:

 输入: "226"
 输出: 3
 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/decode-ways
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
