//
//  96不同的二叉搜索树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/4/8.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
/*
二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）它或者是一棵空树，或者是具有下列性质的二叉树：
 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树。

 输入: 3
 输出: 5
 解释:
 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3
*/

//动态规划  dp[n]= 1...n 分别作根节点求sum(dp[i-1]*dp[n-i])
//dp[0] = 1
//dp[1] = 1
//dp[2] = dp[0]*dp[1] + dp[1]*dp[0];
//dp[3] = dp[0]*dp[2] + dp[1]*dp[1] + dp[2]*dp[0];
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i=2; i<=n; i++) {
            for (int j=1; j<=i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        
        return dp[n];
    }
};
