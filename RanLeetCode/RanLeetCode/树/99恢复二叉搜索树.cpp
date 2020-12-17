//
//  99恢复二叉搜索树.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/10/11.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

//方法三：Morris 中序遍历
class Solution {
public:
    void recoverTree(TreeNode* root) {
        
    }
};


/*
 二叉搜索树中的两个节点被错误地交换。

 请在不改变其结构的情况下，恢复这棵树。

 示例 1:

 输入: [1,3,null,null,2]

    1
   /
  3
   \
    2

 输出: [3,1,null,null,2]

    3
   /
  1
   \
    2
 示例 2:

 输入: [3,1,4,null,null,2]

   3
  / \
 1   4
    /
   2

 输出: [2,1,4,null,null,3]

   2
  / \
 1   4
    /
   3
 进阶:

 使用 O(n) 空间复杂度的解法很容易实现。
 你能想出一个只使用常数空间的解决方案吗？

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/recover-binary-search-tree
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
