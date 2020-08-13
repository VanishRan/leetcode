//
//  51N皇后.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/12.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

class Solution {
public:
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> t (n, string(n, '.')); //⚠️这个初始化方式记住哈
        backTrack(0, t);
        return res;
    }

    void backTrack(int row, vector<string> path) {
        if (row == path.size()) {
            res.push_back(path);
            return;
        }

        for (int col=0; col<path.size(); col++) {
            if (!isValid(path, row, col)) {
                continue;
            }

            path[row][col] = 'Q';
            backTrack(row+1, path);
            path[row][col] = '.';
        }

    }

    bool isValid(vector<string> path, int row, int col) {
        //检查上方
        for (int i=0; i<row; i++) {
            if (path[i][col] == 'Q') {
                return false;
            }
        }

        //检查左上
        for (int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if (path[i][j] == 'Q') {
                return false;
            }
        }

        //检查右上
        for (int i=row-1, j=col+1; i>=0 && j<path.size(); i--, j++) { //⚠️ 这里row-1    i>=0  i--    不是 row+1 小心啊 我去
            if (path[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

//int main() {
//    Solution s;
//    s.solveNQueens(5);
//}


/*

 上图为 8 皇后问题的一种解法。

 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 示例:

 输入: 4
 输出: [
  [".Q..",  // 解法 1
   "...Q",
   "Q...",
   "..Q."],

  ["..Q.",  // 解法 2
   "Q...",
   "...Q",
   ".Q.."]
 ]
 解释: 4 皇后问题存在两个不同的解法。
  

 提示：

 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一到七步，可进可退。（引用自 百度百科 - 皇后 ）

 */
