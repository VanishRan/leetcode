//
//  单链表-结点交换.cpp
//  data structure
//
//  Created by ran on 16/9/22.
//  Copyright © 2016年 ran. All rights reserved.
//
//
//#include<iostream>
//using namespace std;
//#define ok 0
//#define error -1
//class ListNode
//{
//public:
//    int data;
//    ListNode *next;
//    ListNode() { next = NULL; }
//};
//class LinkList
//{
//public:
//    ListNode *head;
//    int len;
//public:
//    LinkList();
//    ~LinkList();
//    int LL_insert(int i,int item);
//    int swap(int pa,int pb);
//    void LL_display();
//};
//LinkList::LinkList()
//{
//    len = 0;
//    head = new ListNode();
//}
//LinkList::~LinkList()
//{
//    ListNode *p,*q;
//    p = head;
//    while(p!=NULL)
//    {
//        q = p;
//        p = p->next;
//        delete q;
//    }
//    len = 0;
//    head = NULL;
//}
//void LinkList::LL_display()
//{
//    ListNode *p;
//    p = head->next;
//    while(p)
//    {
//        cout<<p->data<<" ";
//        p = p->next;
//    }
//    cout<<endl;
//}
//
//
//int LinkList::LL_insert(int i, int item)
//{
//    int j;
//    ListNode *p;
//    p = head;
//    j = 0;
//    while(p && j<i-1)
//    {
//        p = p->next;
//        j++;
//    }
//    if( !p || j>i-1)
//        return error;
//    ListNode *q = new ListNode();//记得哦
//    q->data = item;
//    q->next = p->next;
//    p->next = q;
//    len++;   //长度哦
//    return ok;
//
//}
//
//int LinkList::swap(int pa, int pb)   //这道题我的算法 不是很好 但是是正确的
//{
//    if(pa<1 || pb<1 || pa>len || pb>len)
//        return error;
//    
//    int j;
//    ListNode *p,*q,*t1,*t2,*t3;
//    t1 = head;
//    t2 = head;
//    
//    //找到p的前一个结点
//    j = 0;
//    while(t1 && j<pa-1)
//    {
//        t1 = t1->next;
//        j++;
//    }
//    //找到第一个要交换的结点p
//    p = t1->next;
//    
//    
//    //找到p的下一个结点
//    t3 = p->next;
//    
//    //找到q的前一个结点
//    j = 0;
//    while(t2 && j<pb-1)
//    {
//        t2 = t2->next;
//        j++;
//    }
//    //找到第二个要交换的结点q
//    q = t2->next;
//    
//    
//    //当两个交换的结点相邻的时候
//    if(pa+1 == pb)
//    {
//        t1->next = q;
//        t2 = q->next;
//        q->next = p;
//        p->next = t2;
//    }
//    
//    
//    //不相邻
//    else
//    {
//        t1->next = q;
//        t2->next = p;
//        p->next = q->next;
//        q->next = t3;
//    }
//    
//    return ok;
//    
//}
//
//int main()
//{
//    int n,i;
//    int item;
//    LinkList mylist;
//    cin>>n;
//    for(i=0;i<n;i++)
//    {
//        cin>>item;
//        mylist.LL_insert(i+1, item);
//
//    }
//    mylist.LL_display();
//    
//    int pa,pb;
//    cin>>pa>>pb;
//    if( mylist.swap(pa, pb)==ok )
//        mylist.LL_display();
//    else
//        cout<<"error"<<endl;
//    
//    cin>>pa>>pb;
//    if( mylist.swap(pa, pb)==ok )
//        mylist.LL_display();
//    else
//        cout<<"error"<<endl;
//    
//    return 0;
//
//
//
//
//
//}