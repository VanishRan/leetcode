//
//  567字符串的排列.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/18.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> need, window;
         for (int i=0; i<s1.length(); i++)
             need[s1[i]]++;
         
         int left = 0;
         int right = 0;
         int valid = 0;
         while (right < s2.length()) {
             char ch = s2[right];
             //扩大窗口
             right++;
             
             if (need.count(ch) > 0) {  //need.count(ch) 为啥子
                 window[ch]++;
                 if (window[ch] == need[ch]) {
                     valid++;
                 }
             }
                 
             //收缩求解
             while (right - left >= s1.length()) { //⚠️
                 if (valid == need.size())
                     return true;
                 
                 char d = s2[left];
                 left++;
                 if (need.count(d) > 0) {
                     if (window[d] == need[d]) {  //这里咋回事啊 卧槽。
                         valid--;
                     }
                     window[d]--;
                 }
             }
         }
         
        return false;
    }
};

//int main() {
//    Solution s;
//    cout<<s.checkInclusion("trinitrophenylmethylnitramine","dinitrophenylhydrazinetrinitrophenylmethylnitramine");
//}

/*给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
 

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
