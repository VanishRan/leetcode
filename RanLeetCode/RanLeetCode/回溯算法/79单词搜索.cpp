//
//  79单词搜索.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/13.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    char tmp = board[i][j];
                    board[i][j] = '*';
                    if (backTrack(board, word, i, j, 1))
                        return true;
                    board[i][j] = tmp;
                }
            }
        }
        return false;
    }
    
    bool backTrack(vector<vector<char>>& board, string word, int row, int col, int idx) {
        if (idx == word.length()) {
            return true;
        }
        
        
        vector<int> t1 = {-1,1,0,0};
        vector<int> t2 = {0,0,-1,1};
        for (int i=0; i<4; i++) {
                int x = row+t1[i];
                int y = col+t2[i];
                if (x >= 0 && x < board.size() &&
                    y >= 0 && y < board[0].size() &&
                    board[x][y] == word[idx] && board[x][y] != '*') {
                    
                    char tmp = board[x][y];
                    board[x][y] = '*';
                    if(backTrack(board, word, x, y, idx+1))
                        return true;
                    board[x][y] = tmp;
                }
        }
        
        return false;
    }
};

//int main() {
//    vector<vector<char>> board;
//    board.push_back({'A','B','C','E'});
//    board.push_back({'S','F','C','S'});
//    board.push_back({'A','D','E','E'});
//    
//    Solution s;
//    s.exist(board, "ABCCED");
//}
/*
 给定一个二维网格和一个单词，找出该单词是否存在于网格中。

 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

  

 示例:

 board =
 [
   ['A','B','C','E'],
   ['S','F','C','S'],
   ['A','D','E','E']
 ]

 给定 word = "ABCCED", 返回 true
 给定 word = "SEE", 返回 true
 给定 word = "ABCB", 返回 false
  

 提示：

 board 和 word 中只包含大写和小写英文字母。
 1 <= board.length <= 200
 1 <= board[i].length <= 200
 1 <= word.length <= 10^3

 */
