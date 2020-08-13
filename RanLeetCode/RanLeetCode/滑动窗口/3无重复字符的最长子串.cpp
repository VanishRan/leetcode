//
//  3无重复字符的最长子串.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA
/*滑动窗口题目:

3. 无重复字符的最长子串

30. 串联所有单词的子串

76. 最小覆盖子串

159. 至多包含两个不同字符的最长子串

209. 长度最小的子数组

239. 滑动窗口最大值

567. 字符串的排列

632. 最小区间

727. 最小窗口子序列

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int res = 0;
        map<char, int> window;
        
        while (right < s.length()) {
            char ch = s[right];
            //扩大窗口
            right++;
            
            window[ch]++;
            
            //缩小窗口
            while (window[ch] > 1) {
                char tmp = s[left];
                left++;
                window[tmp]--;
            }
            
            res = max(res, right-left);
        }
        
        return res;
    }
};

//int main() {
//    Solution s;
//    cout<<s.lengthOfLongestSubstring("tmmzuxt");
//}

/*
 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

 示例 1:

 输入: "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 示例 2:

 输入: "bbbbb"
 输出: 1
 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 示例 3:

 输入: "pwwkew"
 输出: 3
 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

 */
