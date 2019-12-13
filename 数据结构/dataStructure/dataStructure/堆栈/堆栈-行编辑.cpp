//
//  堆栈-行编辑.cpp
//  dataStructure
//
//  Created by ran on 2017/2/24.
//  Copyright © 2017年 ran. All rights reserved.
//
//
//#include<iostream>
//#include<string>
//#include<stack>
//using namespace std;
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        stack <char> s;
//        string str;
//        cin>>str;
//        int len;
//        len = str.length();
//        int i;
//        for(i=0;i<len;i++)
//        {
//            if(str[i] == '#')
//            {
//                if(!s.empty())
//                    s.pop();
//            }
//            else
//                s.push(str[i]);
//        }
//        if(s.empty())
//            cout<<"NULL"<<endl;
//        else
//        {
//            stack <char> o;
//            while(!s.empty())
//            {
//                char ch = s.top();
//                s.pop();
//                o.push(ch);
//            }
//            while(!o.empty())
//            {
//                char ch = o.top();
//                o.pop();
//                cout<<ch;
//            }
//            cout<<endl;
//        }
//        
//    }
//    return 0;
//}
