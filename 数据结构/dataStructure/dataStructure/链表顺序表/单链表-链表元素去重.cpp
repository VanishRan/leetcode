//
//  单链表-链表元素去重.cpp
//  dataStructure
//
//  Created by ran on 2017/2/12.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include<iostream>
//using namespace std;
//
//class ListNode
//{
//public:
//    int data;
//    ListNode *next;
//    ListNode(){ next = NULL;}
//};
//
//class LinkList
//{
//public:
//    ListNode *head;
//    int len;
//public:
//    LinkList();
//    void insert(int i,int item);
//    void display();
//    void deleteRepeat();
//};
//LinkList::LinkList()
//{
//    len = 0;
//    head = new ListNode();
//}
//void LinkList::insert(int i, int item)
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
//    if(!p || j>i-1)
//        return;
//    q = new ListNode();
//    q->data = item;
//    q->next = p->next;
//    p->next = q;
//    
//}
//
//void LinkList::display()
//{
//    ListNode *p;
//    p = head->next;
//    while(p)
//    {
//        cout<<p->data<<" ";
//        p = p->next;
//    }
//    cout<<endl;
//   
//}
//void LinkList::deleteRepeat()
//{
//    ListNode *p,*q,*s;
//    p = head->next;
//    while(p)
//    {
//        q = p;
//        while(q->next)
//        {
//            if(q->next->data ==  p->data)
//            {
//                s = q->next;
//                q->next = s->next;
//                delete s;
//                
//            }
//            else
//                q = q->next;
//        }
//        p = p->next;
//       
//    }
//    
//}
//int main()
//{
//    int n,i;
//    int item;
//    LinkList mylist;
//    i = 0;
//    while(cin>>item)   //command + c ???
//    {
//        mylist.insert(i+1, item);
//        i++;
//        
//    }
//    mylist.deleteRepeat();
//    mylist.display();
//}
