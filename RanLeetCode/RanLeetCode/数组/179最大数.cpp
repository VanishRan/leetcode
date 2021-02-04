//
//  179最大数.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/9.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0)
            return "";
        
        sort(nums.begin(), nums.end(), cmp);
        
        string res;
        for (int i=0; i<nums.size(); i++) {
            res += to_string(nums[i]);
        }
        return res[0] == '0' ? "0" : res;
    }
    
    static bool cmp(int m, int n) {
        string a = to_string(m);
        string b = to_string(n);
        string s1 = a + b;
        string s2 = b + a;
        return stol(s1) > stol(s2);
    }
};

//int main () {
//    Solution s;
//    vector<int> nums = {0,0};
//    s.largestNumber(nums);
//}
/*
 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

 示例 1:

 输入: [10,2]
 输出: 210
 示例 2:

 输入: [3,30,34,5,9]
 输出: 9534330
 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/largest-number
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
