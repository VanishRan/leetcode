//
//  14最长公共前缀.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/19.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//排序 然后对比第一个 和 最后一个
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";

        sort(strs.begin(), strs.end());
        string t1 = strs[0];
        string t2 = strs[strs.size()-1];
        string res = "";
        
        int i = 0;
        int j = 0;
        while (i < t1.length() && j < t2.length() && t1[i] == t2[j]) {
            res += t1[i];
            i++;
            j++;
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
