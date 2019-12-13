//
//  顺序表.cpp
//  data structure
//
//  Created by ran on 16/9/11.
//  Copyright © 2016年 ran. All rights reserved.

//
//#include<iostream>
//using namespace std;
//#define ok 0
//#define error -1
//class SeqList
//{
//private:
//    int *list;
//    int maxsize;
//    int size;
//public:
//    SeqList();
//    ~SeqList();
//    void init(int tsize,int *tlist);
//    int list_size();
//    int list_insert(int i,int item);
//    int list_del(int i);
//    int list_get(int i);
//    void display();
//    
//};
//SeqList::SeqList()
//{
//    maxsize = 1000;
//    size = 0;
//    list = new int [maxsize];
//}
//SeqList::~SeqList()
//{
//    delete [] list;
//}
//void SeqList::init(int tsize, int *tlist)
//{
//    size = tsize;
//    int i;
//    for(i=0;i<size;i++)
//    {
//        list[i] = tlist[i];
//    }
//    
//}
//int SeqList::list_size()
//{
//    return size;
//    
//}
//int SeqList::list_insert(int i, int item)
//{
//    if(i<1 || i>size+1)
//        return error;
//    int j;
//    for(j=size;j>= i;j--)
//        list[j] = list[j-1];
//    list[i-1] = item;
//    size++;
//    return ok;
//    
//}
//int SeqList::list_del(int i)
//{
//    if(i<1 || i>size)
//        return error;
//    int j;
//    for(j=i-1;j<size-1;j++)
//        list[j] = list[j+1];
//    size--;
//    return ok;
//    
//}
//int SeqList::list_get(int i)
//{
//    if(i < 1 || i > size)
//        return error;
//    return list[i-1];
//
//}
//void SeqList::display()
//{
//    int i;
//    for(i=0;i<size;i++)
//        cout<<list[i]<<" ";
//    cout<<endl;
//}
//int main()
//{
//    int tsize;
//    int *tlist = new int[100];
//    int j;
//    cin>>tsize;
//    for(j=0;j<tsize;j++)
//        cin>>tlist[j];
//    SeqList a;
//    a.init(tsize, tlist);
//    
//    int i;
//    int item;
//    
//    //执行插入
//    cin>>i>>item;
//    if(a.list_insert(i, item) == 0)
//        a.display();
//    else
//        cout<<"error"<<endl;
//    
//    cin>>i>>item;
//    if(a.list_insert(i, item) == 0)
//        a.display();
//    else
//        cout<<"error"<<endl;
//    
//    //执行删除
//    cin>>i;
//    if(a.list_del(i) == 0)
//        a.display();
//    else
//        cout<<"error"<<endl;
//    
//    cin>>i;
//    if(a.list_del(i) == 0)
//        a.display();
//    else
//        cout<<"error"<<endl;
//    
//    
//    //执行查找
//    cin>>i;
//    if(a.list_get(i) == -1)
//        cout<<"error"<<endl;
//    else
//        cout<<a.list_get(i);
//    
//    
//    cin>>i;
//    if(a.list_get(i) == -1)
//        cout<<"error"<<endl;
//    else
//        cout<<a.list_get(i)<<endl;
//    
//    return 0;
//    
//}