//
//  43字符串相乘.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/25.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "math.h"
/*
              1  2  3
                 4  5
        -----------------
                 1  5
              1  0
           0  5
              1  2 <---
           0  8
        0  4
        -----------------
        0  0  7  3  5
 
   索引  0  1  2  3  4      最多5位
 
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> res (num1.size()+num2.size(), 0);
        
        for (int i=len1-1; i>=0; i--) {
            for (int j=len2-1; j>=0; j--) {
                int multi = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j;
                int p2 = i + j +1;
                
                res[p1] += (res[p2] + multi) / 10;
                res[p2] = (res[p2] + multi) % 10;   //这里是=号 不是+=
                
            }
        }
        
        int i = 0;
        while (i<res.size() && res[i] == 0) {
            i++;
        }
        
        string str;
        for (;i<res.size();i++) {
            str.push_back('0' + res[i]);
        }
        
        return str.size() == 0 ? "0" : str;
    }
};

//int main() {
//    Solution s;
//    
//    s.multiply("45","123");
//}

/*
 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

 示例 1:

 输入: num1 = "2", num2 = "3"
 输出: "6"
 示例 2:

 输入: num1 = "123", num2 = "456"
 输出: "56088"
 说明：

 num1 和 num2 的长度小于110。
 num1 和 num2 只包含数字 0-9。
 num1 和 num2 均不以零开头，除非是数字 0 本身。
 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/multiply-strings
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
