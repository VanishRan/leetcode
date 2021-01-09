//
//  20有效的括号.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/6/22.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "stack"

class Solution {
public:
    stack<char> myStack;
public:
    bool isValid(string s) {
        if (s.length() <= 0) {
            return true;
        }
        
        map<char, char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                myStack.push(s[i]);
                continue;
            }
            
            if (myStack.empty()) {
                return false;
            }
            
            if (mp[myStack.top()] == s[i]) {
                myStack.pop();
            } else {
                return false;
            }
        }
        
        return myStack.empty();
    }
};


/*
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

 有效字符串需满足：

 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 注意空字符串可被认为是有效字符串。

 示例 1:

 输入: "()"
 输出: true
 示例 2:

 输入: "()[]{}"
 输出: true
 示例 3:

 输入: "(]"
 输出: false
 示例 4:

 输入: "([)]"
 输出: false
 示例 5:

 输入: "{[]}"
 输出: true

 */
