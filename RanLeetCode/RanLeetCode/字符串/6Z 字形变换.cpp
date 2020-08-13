//
//  6Z 字形变换.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/19.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "math.h"
//有点意思
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        int curRow = 0;  //当前行
        vector<string> v(numRows, "");
        bool isDown = true;
        for (int i=0; i<s.length(); i++) {
            v[curRow] += s[i];
            
            if (curRow == 0)
                isDown = true;
            
            if (curRow == numRows-1)
                isDown = false;
            
            curRow += isDown ? 1 : -1;
        }
        
        string res;
        for (int i=0; i<numRows; i++) {
            res += v[i];
        }
        
        return res;
    }
};

//int main() {
//    vector<int> t =  {4,3,2,7,8,2,3,1};
//    Solution s;
//    s.findDisappearedNumbers(t);
//}


/*
 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

 L   C   I   R
 E T O E S I I G
 E   D   H   N
 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

 请你实现这个将字符串进行指定行数变换的函数：

 string convert(string s, int numRows);
 示例 1:

 输入: s = "LEETCODEISHIRING", numRows = 3
 输出: "LCIRETOESIIGEDHN"
 示例 2:

 输入: s = "LEETCODEISHIRING", numRows = 4
 输出: "LDREOEIIECIHNTSG"
 解释:

 L     D     R
 E   O E   I I
 E C   I H   N
 T     S     G

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/zigzag-conversion
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
