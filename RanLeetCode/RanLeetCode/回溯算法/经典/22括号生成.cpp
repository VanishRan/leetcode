//
//  22括号生成.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/12.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        
        //backTrack(n, "");
        backTrack2(n, n, "");
        return res;
    }
    
    void backTrack(int n, string path) {
        if (path.length() == 2 * n) {
            res.push_back(path);
            return;
        }
        
        if (isValid(path, '(', n)) {
            path.push_back('(');
            backTrack(n, path);
            path.pop_back();
        }
        
        if (isValid(path, ')', n)) {
            path.push_back(')');
            backTrack(n, path);
            path.pop_back();
        }
    }
    
    //优化： 剩余多少个左括号 右括号
    void backTrack2(int left, int right, string path) {
        if (right < left) {
            return;
        }
        
        if (left < 0 || right < 0 ) {
            return;
        }
        
        if (left == 0 && right == 0) {
            res.push_back(path);
        }
        
        path.push_back('(');
        backTrack2(left-1, right, path);
        path.pop_back();
        
        path.push_back(')');
        backTrack2(left, right-1, path);
        path.pop_back();
    }
    
    bool isValid(string path, char ch, int n) {
        int left = 0; int right = 0;
        for (int i=0; i<path.length(); i++) {
            if (path[i] == '(') {
                left++;
            } else {
                right++;
            }
        }
        
        ch == '(' ? left++ : right++;
        
        if (left > n || right > n) {
            return false;
        }
        
        return left >= right;
    }
};

/*
 
 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

  

 示例：

 输入：n = 3
 输出：[
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
      ]

 
 */
