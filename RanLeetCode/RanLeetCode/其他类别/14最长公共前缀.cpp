//
//  14最长公共前缀.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/19.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//比较简单 可以写优雅点
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        
        if (strs.size() == 1)
            return strs[0];
            
        string res;
        
        int i = 0;
        while (1) {
            char ch;
            if (i >= strs[0].length()) {
                break;
            }
            
            ch = strs[0][i];
            
            bool isDifferent = false;
            for (int j=1; j<strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != ch) {
                    isDifferent = true;
                    break;
                }
            }
            
            if (isDifferent) {
                break;
            }
            
            res += ch;
            i++;
        }
        
        return res;
    }
};

//int main() {
//    vector<string> t =  {"flower","flow","flight"};
//    Solution s;
//    s.longestCommonPrefix(t);
//}


/*
 编写一个函数来查找字符串数组中的最长公共前缀。

 如果不存在公共前缀，返回空字符串 ""。

 示例 1:

 输入: ["flower","flow","flight"]
 输出: "fl"
 示例 2:

 输入: ["dog","racecar","car"]
 输出: ""
 解释: 输入不存在公共前缀。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-common-prefix
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
