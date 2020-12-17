//
//  95不同的二叉搜索树 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *>res;
        if (n <= 0) {
            return res;
        }
        res = generate(1, n);
        return res;
    }
    
    vector<TreeNode*> generate(int begin, int end) {
        vector<TreeNode*> res;
        
        if (begin > end) {
            res.push_back(NULL);
            return res;
        }
        
        if (begin == end) {
            res.push_back(new TreeNode(begin));
            return res;
        }
        
        for (int i=begin; i<=end; i++) {
            vector<TreeNode*> left = generate(begin, i-1);
            vector<TreeNode*> right = generate(i+1, end);
            
            for (int j=0; j<left.size(); j++) {
                for (int k=0; k<right.size(); k++) {
                    TreeNode *t = new TreeNode(i);
                    t->left = left[j];
                    t->right = right[k];
                    res.push_back(t);
                }
            }
        }
        
        return res;
    }
};

int main() {
    Solution s;
    s.generateTrees(3);
}
/*
 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

  

 示例：

 输入：3
 输出：
 [
   [1,null,3,2],
   [3,2,null,1],
   [3,1,null,null,2],
   [2,1,3],
   [1,null,2,null,3]
 ]
 解释：
 以上的输出对应以下 5 种不同结构的二叉搜索树：

    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
