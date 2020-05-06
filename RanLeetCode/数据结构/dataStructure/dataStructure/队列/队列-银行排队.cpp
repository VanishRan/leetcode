//
//  队列-银行排队.cpp
//  dataStructure
//
//  Created by ran on 2017/2/24.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include<iostream>
//#include<queue>
//using namespace std;
//int main()
//{
//    int len,temp;
//    int a,b,c; //每类总人数
//    int ta,tb,tc;//每类总时间
//    char type;
//    int time;
//    queue<int> q;
//    
//    a=0,ta=0;
//    b=0,tb=0;
//    c=0,tc=0;
//    
//    cin>>temp;
//    len=temp;
//    while(len--)
//    {
//        cin>>type;
//        q.push(type);
//        if(type == 'A')
//            a++;
//        else if(type == 'B')
//            b++;
//        else if(type == 'C')
//            c++;
//    }
//    len=temp;
//    while(len--)
//    {
//        cin>>time;
//        char ch = q.front();
//        q.pop();
//        if(ch == 'A')
//            ta=ta+time;
//        else if(ch == 'B')
//            tb=tb+time;
//        else if(ch == 'C')
//            tc=tc+time;
//        
//    }
//    cout<<ta/a<<endl;
//    cout<<tb/b<<endl;
//    cout<<tc/c<<endl;
//    
//    
//}
