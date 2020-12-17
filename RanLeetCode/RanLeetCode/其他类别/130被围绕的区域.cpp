//
//  130被围绕的区域.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/8/19.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;
        int row = board.size();
        int col = board[0].size();
        
        //先把边缘的O遍历了
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (i==0 || j==0 || i==row-1 || j==col-1)
                    dfs(board, i, j);
            }
        }
        
        //再把被包围的O遍历改成X, #改成O
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]=='X' || board[i][j]=='#')
            return;
        
        board[i][j] = '#';
        dfs(board, i-1, j);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
    }
};



//我自己写的垃圾
class Solution2 {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row <= 2)
            return;
        int col = board[0].size();
        if (col <= 2)
            return;
        
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        for (int i=1; i<row-1; i++) {
            for (int j=1; j<col-1; j++) {
                if (board[i][j] == 'O' && !visit[i][j]) {
                    vector<vector<int>> path;
                    bool isWarped = true;
                    traverse(board, visit, path, i, j, isWarped);
                    if (isWarped) {
                        for (int k=0; k<path.size(); k++) {
                            vector<int> t = path[k];
                            board[t[0]][t[1]] = 'X';
                        }
                    }
                }
            }
        }
    }
    
    void traverse(vector<vector<char>>& board, vector<vector<bool>> &visit, vector<vector<int>> &path, int row, int col, bool &isWarped) {
        if (row == 0 || row == board.size()-1 || col == 0 || col == board[0].size()-1)
            isWarped = false;
        
        visit[row][col] = true;
        vector<int> t = {row, col};
        path.push_back(t);
        
        vector<int> stepX = {-1,1,0,0};
        vector<int> stepY = {0,0,-1,1};
        for (int i=0; i<4; i++) {
            int x = row + stepX[i];
            int y = col + stepY[i];
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
                continue;
            
            if (!visit[x][y] && !(board[x][y]=='X')) {
                traverse(board, visit, path, x, y, isWarped);
            }
        }
    }
};

//int main () {
//    Solution s;
//    vector<char> t1 = {'X','X','X','X'};
//    vector<char> t2 = {'X','O','O','X'};
//    vector<char> t3 = {'X','X','O','X'};
//    vector<char> t4 = {'X','O','X','X'};
//    vector<vector<char>> b = {t1,t2,t3,t4};
//    s.solve(b);
//}
/*
 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

 示例:

 X X X X
 X O O X
 X X O X
 X O X X
 运行你的函数后，矩阵变为：

 X X X X
 X X X X
 X X X X
 X O X X
 解释:

 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

 通过次数67,958提交次数161,080

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/surrounded-regions
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
