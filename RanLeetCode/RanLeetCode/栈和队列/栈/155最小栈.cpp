//
//  155最小栈.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/6/21.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
#include "stack"

/*
 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

 push(x) —— 将元素 x 推入栈中。
 pop() —— 删除栈顶的元素。
 top() —— 获取栈顶元素。
 getMin() —— 检索栈中的最小元素。
  

 示例:

 输入：
 ["MinStack","push","push","push","getMin","pop","top","getMin"]
 [[],[-2],[0],[-3],[],[],[],[]]

 输出：
 [null,null,null,null,-3,null,0,-2]

 解释：
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.getMin();   --> 返回 -3.
 minStack.pop();
 minStack.top();      --> 返回 0.
 minStack.getMin();   --> 返回 -2.
  

 提示：
 pop、top 和 getMin 操作总是在 非空栈 上调用。
 
 -3    -3
 0     -2
 -2    -2
 
 */


class MinStack {
public:
    stack<int> myStack;
    stack<int> minStack;
    //int minNum; //错误
public:
    /** initialize your data structure here. */
    MinStack() {
        //minNum = INT_MAX; //错误 pop了之后 minNum没更新
        minStack.push(INT_MAX);
    }
    
    void push(int x) {
        myStack.push(x);
        minStack.push(min(minStack.top(), x));
    }
    
    void pop() {
        myStack.pop();
        minStack.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
