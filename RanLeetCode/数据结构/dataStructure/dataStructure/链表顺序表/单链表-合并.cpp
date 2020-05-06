//
//  单链表-合并.cpp
//  data structure
//
//  Created by ran on 16/9/22.
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
//    //~LinkList();  这道题不能有这个函数 不然运行不了
//    void LL_display();
//    int LL_insert(int i,int item);
//    int LL_merge(ListNode *a,ListNode *b);
//};
//LinkList::LinkList()
//{
//    len = 0;
//    head = new ListNode();
//}
//
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
//int LinkList::LL_merge(ListNode *a, ListNode *b)
//{
//    ListNode *pa,*pb,*pc;
//    pa = a->next;
//    pb = b->next;
//    pc = head;
//    while(pa && pb)
//    {
//        if(pa->data <= pb->data)
//        {
//            pc->next = pa;
//            pc = pa;
//            pa = pa->next;
//            
//        }
//        else
//        {
//            pc->next = pb;
//            pc = pb;
//            pb = pb->next;
//            
//        }
//        pc->next = pa? pa:pb;
//        
//    }
//    return ok;
//    
//}
//
//int main()
//{
//    int n,i;
//    int item;
//    LinkList mylist1,mylist2,mylist3;
//    cin>>n;
//    for(i=0;i<n;i++)
//    {
//        cin>>item;
//        mylist1.LL_insert(i+1, item);
//
//    }
//    cin>>n;
//    for(i=0;i<n;i++)
//    {
//        cin>>item;
//        mylist2.LL_insert(i+1, item);
//        
//    }
//    
//    mylist3.LL_merge(mylist1.head, mylist2.head);
//    mylist3.LL_display();
//    return 0;
//
//
//
//
//}
