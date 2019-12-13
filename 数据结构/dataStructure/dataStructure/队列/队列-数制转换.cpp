//
//  队列-数制转换.cpp
//  dataStructure
//
//  Created by ran on 2017/3/29.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include <iostream>
//#include <stack>
//#include <queue>
//using namespace std;
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        stack <int> myStack;
//        queue <int> myQueue;
//        double  n;  //十进制浮点数
//        int k; //进制
//        cin>>n;
//        cin>>k;
//        
//        int zhengshu;
//        double xiaoshu;
//        int a;  //整数取余
//        int b;  //小数取整数
//        
//        zhengshu = (int)n;
//        xiaoshu = n - zhengshu;
//        
//        while(zhengshu)
//        {
//            a = zhengshu % k;
//            zhengshu = zhengshu / k;
//            myStack.push(a);
//        }
//    
//        while(xiaoshu < 1.0)
//        {
//            b = xiaoshu * k / 1;
//            xiaoshu = xiaoshu * k;
//            myQueue.push(b);
//        }
//        
//        while(!myStack.empty())    //输出栈
//        {
//            int m = myStack.top();
//            switch (m) {
//                case 10:
//                    cout<<'A';
//                    break;
//                case 11:
//                    cout<<'B';
//                    break;
//                case 12:
//                    cout<<'C';
//                    break;
//                case 13:
//                    cout<<'D';
//                    break;
//                case 14:
//                    cout<<'E';
//                    break;
//                case 15:
//                    cout<<'F';
//                    break;
//                default:
//                    cout<<m;
//                    break;
//            }
//            myStack.pop();
//        }
//        
//        cout<<'.';   //输出小数点
//        int sum = 0;//保留三位小数
//        
//        while(!myQueue.empty())    //输出栈
//        {
//            if(sum > 3)
//                break;
//            
//            int m = myQueue.front();
//            switch (m) {
//                case 10:
//                    cout<<'A';
//                    break;
//                case 11:
//                    cout<<'B';
//                    break;
//                case 12:
//                    cout<<'C';
//                    break;
//                case 13:
//                    cout<<'D';
//                    break;
//                case 14:
//                    cout<<'E';
//                    break;
//                case 15:
//                    cout<<'F';
//                    break;
//                default:
//                    cout<<m;
//                    break;
//            }
//            myQueue.pop();
//            sum++;
//        }
//        if (sum == 1)
//            cout<<"00";
//        else if (sum == 2)
//            cout<<'0';
//        cout<<endl;
//    
//        
//    }
//    return 0;
//}
