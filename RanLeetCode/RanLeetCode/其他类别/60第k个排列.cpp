//
//  60第k个排列.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/26.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int idx;
    string res;
public:
    string getPermutation(int n, int k) {
        idx = 0;
        backtrack(n, k, "", vector<bool>(n, false));
        return res;
    }
    
    bool backtrack(int n, int k, string path, vector<bool> used) {
        if (path.length() == n) {
            if (++idx == k) {
                res = path;
                return true;
            }
            return false;
        }
        
        for (int i=1; i<=n; i++) {
            if (used[i-1])
                continue;
            
            char ch = '0' + i;
            string tmp = path + ch;
            used[i-1] = true;
            if (backtrack(n, k, tmp, used))
                return true;
            used[i-1] = false;
        }
        
        return false;
    }
};

//int main() {
//    Solution s;
//    s.getPermutation(3, 3);
//}

/*
 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 给定 n 和 k，返回第 k 个排列。

 说明：

 给定 n 的范围是 [1, 9]。
 给定 k 的范围是[1,  n!]。
 示例 1:

 输入: n = 3, k = 3
 输出: "213"
 示例 2:

 输入: n = 4, k = 9
 输出: "2314"

 */
