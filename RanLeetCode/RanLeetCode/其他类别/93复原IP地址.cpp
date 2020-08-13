//
//  93复原IP地址.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        backTrack(s, "", 0, 0);
        return res;
    }
    
    void backTrack(string s, string path, int begin, int part) {
        if (part == 4) {
            if (path.length() - 3 == s.length())
                res.push_back(path);
            return;
        }
        
        
        for (int i=1; i<=3; i++) {
            if (begin+i-1 >= s.length())
                continue;
            
            string tmp = s.substr(begin, i);
            
            if (!isValid(tmp))
                continue;
            
            string newPath = path + tmp;
            newPath += part == 3 ? "" : ".";
            backTrack(s, newPath, begin+i, part+1);
        }
    }
    
    bool isValid(string str) {
        if (str[0] == '0' && str.length() > 1)
            return false;
        
        int t = stoi(str);
        return t >= 0 && t <= 255;
    }
};

/*
 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

 有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

  

 示例:

 输入: "25525511135"
 输出: ["255.255.11.135", "255.255.111.35"]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/restore-ip-addresses
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
