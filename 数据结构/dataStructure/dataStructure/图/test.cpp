//
//  test.cpp
//  dataStructure
//
//  Created by ran on 2017/6/8.
//  Copyright © 2017年 ran. All rights reserved.
//
//
//#include <stdio.h>
//#include <stack>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    stack<int> data;     //  10 6  5  7  8 数据栈
//    stack<int> m;        //  10 6  5  5  5 最小栈
//    
//    void push(int value) {
//        
//        data.push(value);
//        
//        if(m.empty())
//        {
//            m.push(value);
//        }
//        
//        m.push( value < m.top() ?  value : m.top());
//        
//    }
//    
//    void pop() {
//        data.pop();
//        m.pop();
//    }
//    
//    int top() {
//        return data.top();
//    }
//    
//    int min() {
//        return  m.top();
//    }
//};
