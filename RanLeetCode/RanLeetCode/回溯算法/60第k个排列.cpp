//
//  60第k个排列.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/7/26.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"

/*
   输入: n = 4, k = 9
   输出: "2314"
  
   k = k-1 = 8
 
   [0,1,2,6]
 
   [1,2,3,4]  k / 3! = 1 ... 2 -> 2   k = 2
   [1,3,4]    k / 2! = 1 ... 0 -> 3   k = 0
   [1,4]      k = 0, [1,4] 出列
 
 输入: n = 3, k = 3
 输出: "213"
 系数 [0,1,2]
 [1,2,3]  3/2 = 1...1  res=2    k=1
 [1,3]    1/1 = 1...0  res=20   k=0
 [3]                   res=203
 
 */
//有个回溯剪枝可学一波
class Solution {
public:
    int idx;
    string res;
public:
    string getPermutation(int n, int k) {
        //⚠️关键
        k--;
        
        //1.系数 1！ 2！ 3！ 4！
        vector<int> v(n, 0);
        v[0] = 1;
        for (int i=1; i<n; i++) {
            v[i] = v[i-1] * i;
        }
        
        //2.数组
        vector<int> num(n,0);
        for (int i=0; i<n; i++) {
            num[i] = i + 1;
        }
        
        //3.求余数
        string res;
        int j = n-1;
        while (k > 0) {
            int m = k / v[j];
            k = k % v[j];
            
            res += (num[m] + '0');
            
            //移除
            num = remove(num, m);
            j--;
        }
        
        //4.把剩余的数字添加到后面
        int t = num.size();
        for (int i=0; i<t; i++) {
            res += (num[i] + '0');
        }
        
        return res;
    }
    
    vector<int> remove(vector<int> t, int j) {
        vector<int> res;
        for (int i=0; i<t.size(); i++) {
            if (i != j)
                res.push_back(t[i]);
        }
        return res;
    }
};

//int main() {
//    Solution s;
//    s.getPermutation(3, 3);
//}

/*
 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 给定 n 和 k，返回第 k 个排列。

 说明：

 给定 n 的范围是 [1, 9]。
 给定 k 的范围是[1,  n!]。
 示例 1:

 输入: n = 3, k = 3
 输出: "213"
 示例 2:

 输入: n = 4, k = 9
 输出: "2314"

 */
