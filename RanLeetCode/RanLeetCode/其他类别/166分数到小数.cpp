//
//  166分数到小数.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/8.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "math.h"

//这道题还要再做一遍  4/333为例
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        if (denominator == 0)
            return "";
        
        long nume = numerator;
        long deno = denominator;
        
        string res;
        if ((nume>0) ^ (deno>0)) {
            res = "-";
        }
        
        nume = fabs(nume);
        deno = fabs(deno);
        res += to_string(nume / deno);
        
        nume = nume % deno;
        if (nume == 0) {
            return res;
        }
        
        res += '.';
        int idx = res.length();
        
        map<long,long> mp; //记录余数的位置
        while (nume) {
            if (mp.count(nume)) {
                res.insert(mp[nume], "(");
                res += ')';
                return res;
            }
            
            mp[nume] = idx++;
            nume *= 10;
            res += to_string(nume / deno);
            nume = nume % deno;
        }
        
        return res;
    }
};

//int main() {
//    Solution s;
//    s.fractionToDecimal(4, 333);
//}

/*
 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

 如果小数部分为循环小数，则将循环的部分括在括号内。

 示例 1:

 输入: numerator = 1, denominator = 2
 输出: "0.5"
 示例 2:

 输入: numerator = 2, denominator = 1
 输出: "2"
 示例 3:

 输入: numerator = 2, denominator = 3
 输出: "0.(6)"

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/fraction-to-recurring-decimal
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
