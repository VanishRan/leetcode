//
//  队列-KMP算法.cpp
//  dataStructure
//
//  Created by ran on 2017/4/7.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include<iostream>         //没做完 有bug
//#include<string>
//using namespace std;
//class KMP
//{
//public:
//    string mainStr;
//    int length;
//public:
//    KMP();
//    void setString(string m);
//    void getNext(string s, int *next);    //m 主串  s 子串
//    int KMPFind(string s, int pos);
//};
//KMP::KMP()
//{
//    mainStr = "";
//    length = 0;
//}
//void KMP::setString(string m)
//{
//    mainStr = m;
//    length = (int)mainStr.length();
//}
//void KMP::getNext(string s, int *next)
//{
//    next[1] = 0;
//    int i = 1;
//    int j = 0;
//    while(i < s.length() )
//    {
//        if(j == 0 || s[i] == s[j])
//        {
//            i++;
//            j++;
//            next[i] = j;
//        } else {
//            j = next[j];
//        }
//    }
//}
//int KMP::KMPFind(string s, int pos) //注意   全都是从1开始
//{
//    int i = pos;
//    int j = 1;
//    int *next = new int[length];    //用主串的大小开  防止不够空间
//    getNext(s,next);
//    while(i <= length && j <= s.length())
//    {
//        if(j == 0 || mainStr[i] == s[j])
//        {
//            i++;
//            j++;
//        } else {
//            j = next[j];
//        }
//    }
//    if(j > s.length())
//        return i-(int)s.length();
//    else
//        return 0;
//    
//}
//int main()
//{
//    KMP myKmp;
//    string m;
//    string s;
//    cin>>m>>s;
//    myKmp.setString(m);
//    cout<<myKmp.KMPFind(s,1)<<endl;   //从1开始
//}
