//
//  52N皇后 II.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/26.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    int res;
public:
    int totalNQueens(int n) {
        res = 0;
        vector<string> board (n, string(n,'.'));
        backTrack(board, 0);
        return res;
    }
    
    void backTrack(vector<string> board, int row) {
        if (row == board.size()) {
            res++;
            return;
        }
        
        for (int i=0; i<board.size(); i++) {
            if (!isValid(board, row, i))
                continue;
            
            board[row][i] = 'Q';
            backTrack(board, row+1);
            board[row][i] = '.';
        }
    }
    
    bool isValid(vector<string> board, int row, int col) {
        //检查左上
        for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        //检查右上
        for (int i=row-1, j=col+1; i>=0 && j<board.size(); i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        //检查上方
        for (int i=0; i<row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        
        return true;
    }
};

/*
 n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



 上图为 8 皇后问题的一种解法。

 给定一个整数 n，返回 n 皇后不同的解决方案的数量。

 示例:

 输入: 4
 输出: 2
 解释: 4 皇后问题存在如下两个不同的解法。
 [
  [".Q..",  // 解法 1
   "...Q",
   "Q...",
   "..Q."],

  ["..Q.",  // 解法 2
   "Q...",
   "...Q",
   ".Q.."]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/n-queens-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
