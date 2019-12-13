//
//  asasd.cpp
//  dataStructure
//
//  Created by ran on 2017/8/25.
//  Copyright © 2017年 ran. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

class Solution {
    public:
    map<char,int> Map;
    public:
    int maxMount(int price, int cap, int emptyBottle, int money) {
        int sum = 0;
        int mygap = 0;
        int mybottle = 0;
        
        int buy = money / price;
        
        sum += buy;
        mygap += buy;
        mybottle += buy;
        
        
        while(mygap >= cap || mybottle >= emptyBottle ) {
            int gapChange = 0;
            int bottleChange = 0;
            
            if(mygap >= cap) {
                gapChange = mygap / cap;
                
                sum += gapChange;
                mygap -= gapChange * cap;
            }
            
            if(mybottle >= emptyBottle) {
                bottleChange = mybottle / emptyBottle;
                
                sum += bottleChange;
                mybottle -= bottleChange * emptyBottle;
            }
            
            mygap = mygap + gapChange + bottleChange;
            mybottle = mybottle + bottleChange +gapChange;
            
        }
        
        return sum;
    }
    
};

int main() {
    
    Solution s;
    cout<<s.maxMount(3, 4, 2, 30)<<endl;
    
}

//
//#include<vector>
//class mysolution {
//public:
//    int maxMount(int n,vector<vector<char>> matrix) {
//        
//        vector<vector<int>> dp(n,vector<int>(n,0));  //检查行
//
//        int cur = 1; // 下一块是第几块田
//        
//        //动态规划 先确定第一行和第一列
//        
//        //第一行
//        for(int i = 0;i<n;i++) {
//            if(matrix[0][i] == '*') {
//                if(i-1 >=0 && matrix[0][i-1] == '*')
//                    dp[0][i] = dp[0][i-1];
//                else {
//                    dp[0][i] = cur;
//                    cur++;
//                }
//                
//            }
//        }
//        
//        
//        //第一列
//        for(int i = 1;i<n;i++) {
//            if(matrix[i][0] == '*') {
//                if(i-1 >=0 && matrix[i-1][0] != '0')
//                    dp[i][0] = dp[i-1][0];
//                else {
//                    dp[i][0] = cur;
//                    cur++;
//                }
//                
//            }
//        }
//        
//        for(int i=1;i<n;i++) {
//            for(int j=1;j<n;j++) {
//                if(matrix[i][j] == '*') {  //看看他的  左上 上 右上  左 左下  5个位置
//                    
//                    if(dp[i-1][j-1] != 0)  {
//                        dp[i][j] = dp[i-1][j-1];
//                        continue;
//                    }
//                    
//                    else if(dp[i-1][j] != 0)  {
//                        dp[i][j] = dp[i-1][j];
//                        continue;
//                    }
//                    
//                    else if(j+1 < n && dp[i-1][j+1] != 0)  {
//                        dp[i][j] = dp[i-1][j+1];
//                        continue;
//                    }
//                    
//                    else if(dp[i][j-1] != 0)  {
//                        dp[i][j] = dp[i][j-1];
//                        continue;
//                    }
//                    
//                    else if(i+1 <n && dp[i+1][j-1] != 0)  {
//                        dp[i][j] = dp[i+1][j-1];
//                        continue;
//                    }
//                    
//                    else {
//                        dp[i][j] = cur;
//                        cur++;
//                    }
//                
//                }
//            }
//        }
//        
//        
//        
//        return cur-1;
//    }
//};
//
//int main() {
//    mysolution s;
//    
//    vector<vector<char>> matrix(4,vector<char>(4,'0'));
//    matrix[0][0] = '*';
//    matrix[2][1] = '*';
//    matrix[2][2] = '*';
//    matrix[3][3] = '*';
//    
//    cout<<s.maxMount(4, matrix);
//
//}
//        

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
