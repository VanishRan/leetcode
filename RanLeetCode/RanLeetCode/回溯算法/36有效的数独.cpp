//
//  36有效的数独.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/24.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<9; i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j] == '.')
                    continue;
                if (!isValid(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col) {
          for (int i=0;i<9;i++) {
              //检查行
              if (i != col && board[row][i] == board[row][col])
                  return false;
              //检查列
              if (i != row && board[i][col] == board[row][col])
                  return false;
              //检查3*3小正方形
              int x = row/3*3 + i/3;
              int y = col/3*3 + i%3;
              if ( (x!=row || y!=col) && board[x][y] == board[row][col])
                  return false;
          }
          
          return true;
      }
    
};

//int main() {
//    vector<char> t1 = {'5','3','.','.','7','.','.','.','.'};
//    vector<char> t2 = {'6','.','.','1','9','5','.','.','.'};
//    vector<char> t3 = {'.','9','8','.','.','.','.','6','.'};
//    vector<char> t4 = {'8','.','.','.','6','.','.','.','3'};
//    vector<char> t5 = {'4','.','.','8','.','3','.','.','1'};
//    vector<char> t6 = {'7','.','.','.','2','.','.','.','6'};
//    vector<char> t7 = {'.','6','.','.','.','.','2','8','.'};
//    vector<char> t8 = {'.','.','.','4','1','9','.','.','5'};
//    vector<char> t9 = {'.','.','.','.','8','.','.','7','9'};
//    
//    vector<vector<char>> ttt = {t1,t2,t3,t4,t5,t6,t7,t8,t9};
//    Solution s;
//    cout<<s.isValidSudoku(ttt);
//}
