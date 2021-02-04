//
//  151翻转字符串里的单词.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//整体反转 + 单词反转
//跟旋转数组有点像
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string res;
        
        for (int i=0; i<s.length(); i++) {
            //先找到第一个不为“ ”的字符
            if (s[i] != ' ') {
                int j = i;
                for (; j<s.length(); j++) {
                    if (s[j] == ' ') {
                        break;
                    }
                }
                
                string t1 = s.substr(i, j-i);
                reverse(t1.begin(), t1.end());
                res += res.length() == 0 ? t1 : (" " + t1);
                i = j;
            }
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
