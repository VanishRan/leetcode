//
//  单链表-多项式相加.cpp
//  dataStructure
//
//  Created by ran on 2017/2/13.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include<iostream>
//using namespace std;
//class ListNode
//{
//public:
//    int coef;  //coefficient 系数
//    int expn;   //exponent 阶数
//    ListNode *next;
//public:
//    ListNode(){ next = NULL;}
//};
//class LinkList
//{
//public:
//    ListNode *head;
//    int len;
//public:
//    LinkList();
//    void insert(int i,int coef,int expn);
//    void display();
//};
//LinkList::LinkList()
//{
//    head = new ListNode();
//    len = 0;
//}
//void LinkList::insert(int i, int coef,int expn)
//{
//    ListNode *p,*q;
//    int j = 0;
//    p = head;
//    while(p && j<i-1)
//    {
//        p = p->next;
//        j++;
//    }
//    if(!p || j>i-1)
//        return;
//    q = new ListNode();
//    q->coef = coef;
//    q->expn = expn;
//    q->next = p->next;
//    p->next = q;
//    
//}
//void  LinkList::display()  //算法对的   不知道输出有没有bug
//{
//    ListNode *p;
//    int flag = 0;
//    p = head->next;
//    
//    //第一项
//    if(p->coef == 0)
//        flag = 1;      //第一项系数为 0
//    
//    else if(p->coef < 0)     //系数小于0
//    {
//        if(p->expn == 0)
//            cout<<"("<<p->coef<<")";
//        else if(p->expn > 0)
//            cout<<"("<<p->coef<<")X^"<<p->expn;
//        else if(p->expn < 0)
//            cout<<"("<<p->coef<<")X^"<<"("<<p->expn<<")";
//    }
//    
//    else if(p->coef > 0)
//    {
//        if(p->expn == 0)
//            cout<<p->coef;
//        else if(p->expn > 0)
//            cout<<p->coef<<"X^"<<p->expn;
//        else if(p->expn < 0)
//            cout<<p->coef<<"X^"<<"("<<p->expn<<")";
//    }
//    
//    p = p->next;
//    
//    while(p)
//    {
//        if(flag == 1) {}  //第一项系数为0   有可能前面多项都是系数为0
//            
//        else
//        {
//            if(p->coef != 0)
//                cout<<" + ";
//        }
//        
//        
//        if(p->coef == 0) {}
//            
//        else if(p->coef < 0)     //系数小于0
//        {
//            if(p->expn == 0)
//                cout<<"("<<p->coef<<")";
//            else if(p->expn > 0)
//                cout<<"("<<p->coef<<")X^"<<p->expn;
//            else if(p->expn < 0)
//                cout<<"("<<p->coef<<")X^"<<"("<<p->expn<<")";
//            flag = 0;  //输出过系数，才可以吧"+"放出来
//        }
//        else if(p->coef > 0)      //系数大于0
//        {
//            if(p->expn == 0)
//                cout<<p->coef;
//            else if(p->expn > 0)
//                cout<<p->coef<<"X^"<<p->expn;
//            else if(p->expn < 0)
//                cout<<p->coef<<"X^"<<"("<<p->expn<<")";
//            flag = 0;   //输出过系数，才可以吧"+"放出来
//            
//        }
//        p = p->next;
//    }
//    cout<<endl;
//
//    
//}
//void add(ListNode *A,ListNode *B)
//{
//    LinkList mylist;
//    ListNode *a,*b,*c;
//    a = A->next;
//    b = B->next;
//    c = mylist.head;
//    while(a && b)
//    {
//
//        if(a->expn < b->expn)
//        {
//            c->next = a;
//            c = a;
//            a = a->next;
//
//        }
//        else if(a->expn > b->expn)
//        {
//            c->next = b;
//            c = b;
//            b = b->next;
//            
//        }
//        else
//        {
//            c->next = a;
//            c = a;
//            c->coef = a->coef + b->coef;
//            a = a->next;
//            b = b->next;
//        }
//    }
//    c->next = a? a:b;
//    mylist.display();
//    
//}
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        LinkList mylist1,mylist2;
//        int m,n,i,j,coef,expn;
//        cin>>m;
//        for(i=0;i<m;i++)
//        {
//            cin>>coef>>expn;
//            mylist1.insert(i+1,coef,expn);
//        }
//        mylist1.display();
//        
//        cin>>n;
//        for(j=0;j<n;j++)
//        {
//            cin>>coef>>expn;
//            mylist2.insert(j+1, coef, expn);
//        }
//        mylist2.display();
//        
//        add(mylist1.head, mylist2.head);
//    }
//    
//    
//    
//    return 0;
//}
