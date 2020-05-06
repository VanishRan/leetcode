//
//  堆栈-括号匹配.cpp
//  dataStructure
//
//  Created by ran on 2017/2/24.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include<iostream>
//#include<stack>
//using namespace std;
//#define error 0
//#define ok 1
//int match(char *a)
//{
//    stack<char> s;
//    int i;
//    for(i=0;a[i]!='\0';i++)
//    {
//        if(a[i] == '[' || a[i] == '{' || a[i] == '(')
//        {
//            s.push(a[i]);
//        }
//        else if(a[i] == ']' || a[i] == '}' || a[i] == ')')
//        {
//            if(s.empty())
//            {
//                return error;
//            }
//            char top = s.top();
//            if(a[i] == ']')
//            {
//                if(top == '[')
//                    s.pop();
//                else
//                    return error;
//            }
//            else if(a[i] == '}')
//            {
//                if(top == '{')
//                    s.pop();
//                else
//                    return error;
//            }
//            else if(a[i] == ')')
//            {
//                if(top == '(')
//                    s.pop();
//                else
//                    return error;
//            }
//        }
//    }
//    if(!s.empty())
//    {
//        return error;
//    }
//    return ok;
//}
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        char *a = new char[100];
//        cin>>a;
//        if(match(a) == ok)
//            cout<<"ok"<<endl;
//        else
//            cout<<"error"<<endl;
//    }
//    return 0;
//}
