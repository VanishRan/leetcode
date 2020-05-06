//
//  3无重复字符的最长子串.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

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
        if (s.length() == 0) {
            return 0;
        }
        
        int maxLen = 1;
        int left = 0;
        for (int i=1; i<s.length(); i++) {
            int j=left;
            for (; j<i; j++) {
                if (s[j] == s[i]) {
                    left = j+1;
                    break;
                }
            }
            
            if (j == i) {
                maxLen = max(maxLen, i-left+1);
            }
        }
        
        return maxLen;
    }
};

//int main() {
//    Solution s;
//    cout<<s.lengthOfLongestSubstring("tmmzuxt");
//}
