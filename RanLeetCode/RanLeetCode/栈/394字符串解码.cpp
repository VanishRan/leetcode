//
//  394字符串解码.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/10.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

#include "stack"

//#include <stdlib.h>


//3[a]2[bc]

/*
  3[a2[c]]
 i       0    1          2         3         4              5               6          7
 multi   3    0          0         2         0              0               0          0
 res     ""   ""         a         a         a              c               acc        accaccacc
 stack1  []   [3]        [3]      [3]        [3,2]          [3,2]           [3]        []
 stack2  []   [""]       [""]     [""]       ["","a"]       ["","a"]        [""]       []
 */

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string res = "";
        int multi = 0;
        
        for (int i=0; i<s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                multi = multi * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                numStack.push(multi);
                strStack.push(res);
                multi = 0;
                res = "";
            } else if (s[i] == ']') {
                int t1 = numStack.top();
                string t2 = strStack.top();
                numStack.pop();
                strStack.pop();
                string t3;
                while (t1--) {
                    t3 += res;
                }
                res = t2 + t3;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};


//int main() {
//    Solution s;
//    s.decodeString("3[a]2[bc]");
//}
/*

 给定一个经过编码的字符串，返回它解码后的字符串。



 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。



 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。



 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。



 



 示例 1：



 输入：s = "3[a]2[bc]"

 输出："aaabcbc"

 示例 2：



 输入：s = "3[a2[c]]"

 输出："accaccacc"

 示例 3：



 输入：s = "2[abc]3[cd]ef"

 输出："abcabccdcdcdef"

 示例 4：



 输入：s = "abc3[cd]xyz"

 输出："abccdcdcdxyz"



 */
