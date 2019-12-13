//
//  单链表-类实现.cpp
//  data structure
//
//  Created by ran on 16/9/19.
//  Copyright © 2016年 ran. All rights reserved.
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
//    ListNode * LL_index(int i);      //暂时不实现这个函数
//    int LL_get(int i);
//    int LL_insert(int i,int item);
//    int LL_del(int i);
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
//int LinkList::LL_get(int i)
//{
//    int j,e;
//    ListNode *p;
//    p = head->next;
//    j = 1;
//    while(p && j<i)
//    {
//        p = p->next;
//        j++;
//    }
//    if(!p || j>i)
//        return error;
//    e = p->data;
//    return e;
//}
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
//    return ok;
//  
//}
//
//int LinkList::LL_del(int i)
//{
//    int j;
//    ListNode *p,*q;
//    p = head;
//    j = 0;
//    while(p && j<i-1)
//    {
//        p = p->next;
//        j++;
//    }
//    if( !p || j>i-1)
//        return error;
//    q = p->next;
//    p->next = q->next;
//    delete q;
//    return ok;
//    
//}
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
//    //insert
//    cin>>i>>item;
//    if(mylist.LL_insert(i, item) == ok)
//        mylist.LL_display();
//    else
//        cout<<"error"<<endl;
//    
//    cin>>i>>item;
//    if(mylist.LL_insert(i, item) == ok)
//        mylist.LL_display();
//    else
//        cout<<"error"<<endl;
//    
//    
//    //delete
//    cin>>i;
//    if(mylist.LL_del(i) == ok)
//        mylist.LL_display();
//    else
//        cout<<"error"<<endl;
//    
//    
//    cin>>i;
//    if(mylist.LL_del(i) == ok)
//        mylist.LL_display();
//    else
//        cout<<"error"<<endl;
//    
//    
//    //get
//    cin>>i;
//    if(mylist.LL_get(i) != error)
//        cout<<mylist.LL_get(i)<<endl;
//    else
//        cout<<"error"<<endl;
//    
//    
//    cin>>i;
//    if(mylist.LL_get(i) != error)
//        cout<<mylist.LL_get(i)<<endl;
//    else
//        cout<<"error"<<endl;
//    
//    return 0;
//    
//    
//    
//    
//}