//
//  268缺失数字.cpp
//  leetcode
//
//  Created by mahuanran on 2019/12/17.
//  Copyright © 2019 mahuanran. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//方法1:求和
//class Solution {
//public:
//    int missingNumber(vector<int>& nums) {
//        int n = nums.size();
//        int sum = n*(n+1)/2;
//
//        int t1 = 0;
//        for (int i=0; i<n; i++) {
//            t1 = t1 + nums[i];
//        }
//
//        return sum - t1;
//    }
//};

//方法2:异或
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missing = n;
        for (int i=0; i<n; i++) {
            missing = missing ^ nums[i] ^ i;
        }
        
        return missing;
    }
};

//int main(int argc, const char * argv[]) {
//    Solution s;
//    
//    vector<int> tmp(4, 0);
//    tmp[0] = 3;
//    tmp[1] = 0;
//    tmp[2] = 1;
//    tmp[3] = 2;
//    
//    cout<<s.missingNumber(tmp)<<endl;
//
//    return 0;
//}
