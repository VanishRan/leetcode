//
//  76最小覆盖子串.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/18.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA

//滑动窗口： 扩大 -> 收缩 找最优解 -> 扩大
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> need, window;
        for (int i=0; i<t.length(); i++)
            need[t[i]]++;
        
        int start = 0;
        int len = INT_MAX;
        int left = 0;
        int right = 0;
        int valid = 0;
        while (right < s.length()) {
            char ch = s[right];
            //扩大窗口
            right++;
            
            if (need.count(ch) > 0) {  //need.count(ch) 为啥子
                window[ch]++;
                if (window[ch] == need[ch]) {
                    valid++;
                }
            }
                
            //收缩求最优解
            while (valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                
                char ch = s[left];
                left++;
                if (need.count(ch) > 0) {
                    window[ch]--;
                    if (window[ch] < need[ch]) {
                        valid--;
                    }
                }
            }
        }
        
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

//int main() {
//    Solution s;
//    cout<<s.minWindow("ADOBECODEBANC","ABC");
//}


/*
 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。

 示例：

 输入: S = "ADOBECODEBANC", T = "ABC"
 输出: "BANC"
 说明：

 如果 S 中不存这样的子串，则返回空字符串 ""。
 如果 S 中存在这样的子串，我们保证它是唯一的答案。


 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/minimum-window-substring
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
