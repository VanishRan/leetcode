//
//  836矩形重叠.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/26.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //x1 y1,  x2 y2
        //左上0 4 左下0 1 右上2 4 右下2 3
        vector<int> xv1(2,0); xv1[0] = rec1[0]; xv1[1] = rec1[2];
        vector<int> yv1(2,0); yv1[0] = rec1[1]; yv1[1] = rec1[3];
        
        vector<int> xv2(2,0); xv2[0] = rec2[0]; xv2[1] = rec2[2];
        vector<int> yv2(2,0); yv2[0] = rec2[1]; yv2[1] = rec2[3];
        
        bool res = false;
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                
                if (xv1[i] > xv2[0] &&
                    xv1[i] < xv2[1] &&
                    yv1[j] > yv2[0] &&
                    yv1[j] < yv2[1]) {
                    res = true;
                    break;
                }
                
                if (xv2[i] > xv1[0] &&
                    xv2[i] < xv1[1] &&
                    yv2[j] > yv1[0] &&
                    yv2[j] < yv1[1]) {
                    res = true;
                    break;
                }
            }
        }
        
        return res;
    }
};

//int main(int argc, const char * argv[]) {
//    vector<int> v1 = { 0,0,2,2 };
//    vector<int> v2 = { 1,1,3,3 };
//    
//    Solution s;
//
//    cout<<s.isRectangleOverlap(v1,v2)<<endl;
//
//    return 0;
//}
