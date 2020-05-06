//
//  构建邻接表.cpp
//  dataStructure
//
//  Created by ran on 2017/4/16.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include<iostream>
//using namespace std;
//class Node
//{
//public:
//    int data;  //编号
//    Node *next;
//public:
//    Node()
//    {
//        next = NULL;
//    }
//};
//
//class graphic
//{
//public:
//    char info;   //顶点字母
//    Node *head;
//public:
//    graphic();
//    void insert(char data);
//};
//
//graphic::graphic()
//{
//    head = new Node();
//    
//}
//
//void graphic::insert(char data)
//{
//    Node *p;
//    p = head;
//    while(p->next)
//    {
//        p = p->next;
//    }
//    Node *q = new Node();
//    q->data = data - 'A';
//    p->next = q;
//}
//
//void display(graphic *g,int n)
//{
//    for(int i=0;i<n;i++)
//    {
//        cout<<i<<" "<<g[i].info<<"-";
//        Node *p = g[i].head;
//        p = p->next;
//        while(p)
//        {
//            cout<<p->data<<"-";
//            p = p->next;
//        }
//        cout<<"^"<<endl;
//        
//    }
//    
//}
//
//int main()
//{
//    int n,k;
//    cin>>n>>k; //n 顶点数   k边数
//    graphic g[10];
//    for(int i=0;i<n;i++)
//        g[i].info = char('A'+i);
//    
//    int t = k;
//    while(t--)
//    {
//        char a,b;
//        cin>>a>>b;
//        int j = a - 'A';
//        g[j].insert(b);
//    }
//    display(g,n);
//}
