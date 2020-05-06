//
//  common.h
//  RanLeetCode
//
//  Created by mahuanran on 2020/3/27.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#ifndef common_h
#define common_h


#endif /* common_h */

#include <stdio.h>
#include "iostream"
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 
 int main(int argc, const char * argv[]) {
     vector<int> v1 = { 0,0,2,2 };
     vector<int> v2 = { 1,1,3,3 };
 
     Solution s;
 
     cout<<s.isRectangleOverlap(v1,v2)<<endl;
 
     return 0;
 }
 
 */
