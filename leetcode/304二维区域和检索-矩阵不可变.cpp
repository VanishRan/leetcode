//
//  304二维区域和检索-矩阵不可变.cpp
//  leetcode
//
//  Created by mahuanran on 2019/12/17.
//  Copyright © 2019 mahuanran. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//这题没有看答案 代码可以优化简洁一点
class NumMatrix {
public:
    vector<vector<int>> sumMatrix;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;//构造函数可以return？
        
        vector<vector<int>> tmp(matrix.size() ,vector<int>(matrix[0].size(),0));
        sumMatrix = tmp;
        
        sumMatrix[0][0] = matrix[0][0];
        for (int i=0;i<matrix.size();i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                if (i > 0 && j == 0) {
                    sumMatrix[i][j] = sumMatrix[i-1][j] + matrix[i][j];
                }
                
                if (i == 0 && j > 0) {
                    sumMatrix[i][j] = sumMatrix[i][j-1] + matrix[i][j];
                }
                
                if (i > 0 && j > 0) {
                    sumMatrix[i][j] = sumMatrix[i-1][j] + sumMatrix[i][j-1] - sumMatrix[i-1][j-1] + matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = sumMatrix[row2][col2];
        
        if (row1 > 0) {
            res = res - sumMatrix[row1-1][col2];
        }
        
        if (col1 > 0) {
            res = res - sumMatrix[row2][col1-1];
        }
        
        if (row1 > 0 && col1 > 0) {
            res = res + sumMatrix[row1-1][col1-1];
        }
        
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

//int main(int argc, const char * argv[]) {
//    vector<vector<int>> tmp(2, vector<int>(2,0));
//    tmp[0][0] = 3;
//    tmp[0][1] = 0;
//    tmp[1][0] = 5;
//    tmp[1][1] = 6;
//
//    NumMatrix *s = new NumMatrix(tmp);
//    cout<<s->sumRegion(0, 0, 1, 1)<<endl;
//
//    return 0;
//}
