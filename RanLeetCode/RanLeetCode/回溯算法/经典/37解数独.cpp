//
//  37解数独.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/12.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        backTrack(board, 0, 0);
    }
    
    bool backTrack(vector<vector<char>>& board, int row, int col) {
        if (col == 9) {
            return backTrack(board, row+1, 0);
        }
        
        if (row == 9) {
            return true;
        }
        
        if (board[row][col] != '.') {
            return backTrack(board, row, col+1);
        }
        
        
        for (int i=0; i<9; i++) {
            char ch = '1' + i;
            if (!isValid(board, row, col, ch)) {
                continue;
            }
            
            board[row][col] = ch;
            
            if(backTrack(board, row, col+1))
                return true;
            
            board[row][col] = '.';
        }
        
        return false;
    }
    
    
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i=0; i<9; i++) {
            //检查行
            if (board[i][col] == ch)
                return false;
            
            //检查列
            if (board[row][i] == ch)
                return false;
            
            
           //检查9*9小正方形
            int x = (row/3)*3 + i/3;
            int y = (col/3)*3 + i%3;
            if (board[x][y] == ch)
                return false;
        }
        
        return true;
    }
};





/*
 编写一个程序，通过已填充的空格来解决数独问题。

 一个数独的解法需遵循如下规则：

 数字 1-9 在每一行只能出现一次。
 数字 1-9 在每一列只能出现一次。
 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

 Note:

 给定的数独序列只包含数字 1-9 和字符 '.' 。
 你可以假设给定的数独只有唯一解。
 给定数独永远是 9x9 形式的。
 
 */
