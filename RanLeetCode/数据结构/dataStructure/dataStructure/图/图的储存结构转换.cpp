//
//  图的储存结构转换.cpp
//  dataStructure
//
//  Created by ran on 2017/4/17.
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
//    void insert(int data);
//};
//
//graphic::graphic()
//{
//    head = new Node();
//
//}
//
//void graphic::insert(int data)
//{
//    Node *p;
//    p = head;
//    while(p->next)
//    {
//        p = p->next;
//    }
//    Node *q = new Node();
//    q->data = data;
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
//    int n;
//    cin>>n;
//    graphic g[10];
//    
//    char info;
//    int i,j;
//    
//    for(i=0;i<n;i++)
//    {
//        cin>>info;
//        g[i].info = info;
//    }
//    
//    int matrix[10][10];
//    for(i=0;i<n;i++)
//        for(j=0;j<n;j++)
//            cin>>matrix[i][j];
//    
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<n;j++)
//        {
//            if(matrix[i][j] == 1)
//            {
//                g[i].insert(j);
//            }
//        }
//    }
//    display(g,n);
//    return 0;
//}
