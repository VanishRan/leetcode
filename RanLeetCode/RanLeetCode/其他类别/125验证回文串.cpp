//
//  125验证回文串.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while (i<=j) {
            while (i<j && !isValid(s[i])) i++;
            while (i<j && !isValid(s[j])) j--;
            
            if (i<=j) {     //⚠️这一句解决了空串问题
                if (tolower(s[i]) != tolower(s[j]))
                    return false;
                i++;
                j--;
            }
        }
        return true;
    }
    
    bool isValid(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            return true;
        }
        if (ch >= 'A' && ch <= 'Z') {
            return true;
        }
        if (ch >= '0' && ch <= '9') {
            return true;
        }
        return false;
    }
};

//int main() {
//    Solution s;
//    s.isPalindrome("A man, a plan, a canal: Panama");
//}
/*
 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

 说明：本题中，我们将空字符串定义为有效的回文串。

 示例 1:

 输入: "A man, a plan, a canal: Panama"
 输出: true
 示例 2:

 输入: "race a car"
 输出: false

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/valid-palindrome
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
