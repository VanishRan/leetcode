//
//  72编辑距离.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/10/11.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/*
 
 当 word1[i] == word2[j]，dp[i][j] = dp[i-1][j-1]；

 当 word1[i] != word2[j]，dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1

        ''  r   o   s
    ''  0   1   2   3
    h   1   1   2   3
    o   2   2   1   2
    r   3   2   2   2
    s   4   3   3   2
    e   5   4   4   3
 
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length() + 1;
        int len2 = word2.length() + 1;
        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        
        //第一行
        for (int i=1; i<len2; i++)
            dp[0][i] = i;
        
        //第一列
        for (int i=1; i<len1; i++)
            dp[i][0] = i;
        
        for (int i=1; i<len1; i++) {
            for (int j=1; j<len2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        
        return dp[len1-1][len2-1];
    }
};


/*
 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

 你可以对一个单词进行如下三种操作：

 插入一个字符
 删除一个字符
 替换一个字符
  

 示例 1：

 输入：word1 = "horse", word2 = "ros"
 输出：3
 解释：
 horse -> rorse (将 'h' 替换为 'r')
 rorse -> rose (删除 'r')
 rose -> ros (删除 'e')
 示例 2：

 输入：word1 = "intention", word2 = "execution"
 输出：5
 解释：
 intention -> inention (删除 't')
 inention -> enention (将 'i' 替换为 'e')
 enention -> exention (将 'n' 替换为 'x')
 exention -> exection (将 'n' 替换为 'c')
 exection -> execution (插入 'u')

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/edit-distance
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
