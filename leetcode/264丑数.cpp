//
//  264丑数.cpp
//  leetcode
//
//  Created by ran on 2019/12/13.
//  Copyright © 2019 mahuanran. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        
        int idx2 = 0;
        int idx3 = 0;
        int idx5 = 0;
        vector<int> nums;
        nums.push_back(1);
        
        int curIdx = 0;//数组有一个数了
        while (curIdx < n-1) {
            int tmp = min(nums[idx2]*2, min(nums[idx3]*3 ,nums[idx5]*5));
            
            if (tmp == nums[idx2]*2) {
                idx2++;
            }
            
            if (tmp == nums[idx3]*3) {
                idx3++;
            }
            
            if (tmp == nums[idx5]*5) {
                idx5++;
            }
            
            nums.push_back(tmp);
            curIdx++;
        }
        
        return nums[n-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.nthUglyNumber(11)<<endl;
    
    return 0;
}


//思路：从1开始
// 1               1 要乘 2 3 5  找到最小的, 加入数组
// 1 2             1 要乘 3 5    2 要乘 2   找到最小的加入数组
// 1 2 3           1 要乘 5      2 要乘 2 3 找到最小的加入数组
//总结：每个数组的数都要乘 2  3  5

//编写一个程序，找出第 n 个丑数。
//
//丑数就是只包含质因数 2, 3, 5 的正整数。
//
//示例:
//
//输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
//说明:
//
//1 是丑数。
//n 不超过1690。
