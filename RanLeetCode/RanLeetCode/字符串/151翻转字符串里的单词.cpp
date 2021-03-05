//
//  151翻转字符串里的单词.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//双指针
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = s.length() - 1;
        while (i >= 0) {
            if (s[i] == ' ') {
                i--;
                continue;
            }

            int j = i;
            while (j > 0 && s[j-1] != ' ')
                j--;
            
            string tmp = s.substr(j, i-j+1);

            res += (res.length() == 0) ? tmp : (" " + tmp);

            i = j - 1;
        }

        return res;
    }
};




/*

 给定一个字符串，逐个翻转字符串中的每个单词。

  

 示例 1：

 输入: "the sky is blue"
 输出: "blue is sky the"
 示例 2：

 输入: "  hello world!  "
 输出: "world! hello"
 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 示例 3：

 输入: "a good   example"
 输出: "example good a"
 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
  

 说明：

 无空格字符构成一个单词。
 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
  

 进阶：

 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 */
