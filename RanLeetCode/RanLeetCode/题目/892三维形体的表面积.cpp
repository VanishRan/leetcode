//
//  892三维形体的表面积.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/25.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {

                int n = grid[i][j];
                
                //1.自己
                if (n > 0) {
                    res += 4*n + 2;
                }
                //2.上边
                if (i>0) {
                    res -= min(n, grid[i-1][j]) * 2;
                }
                //3.左边
                if (j>0) {
                    res -= min(n, grid[i][j-1]) * 2;
                }
            }
        }
        
        return res;
    }
};

//int main(int argc, const char * argv[]) {
//    vector<vector<int>> tmp(3,vector<int>(3,2));
//    tmp[1][1] = 1;
//
//    Solution s;
//
//    cout<<s.surfaceArea(tmp)<<endl;
//
//    return 0;
//}
