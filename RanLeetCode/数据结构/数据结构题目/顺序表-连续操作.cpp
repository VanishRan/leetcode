//
//  顺序表－连续操作.cpp
//  data structure
//
//  Created by ran on 16/9/13.
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
//    int list_insert(int i,int n,int *item);
//    int list_del(int i,int n);
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
//int SeqList::list_insert(int i, int n,int *item)
//{
//
//       int j;
//
//        size = size + n;
//        for(j=size+n-1;j>=i+n-1;j--)
//        {
//            list[j] = list[j-n];
//        }
//        
//        int k;
//        for(j=i-1,k=0;k<n;j++,k++)
//        {
//            list[j] = item[k];
//        }
//        return ok;
//
//}
//
//
//int SeqList::list_del(int i,int n)
//{
//    int j;
//    if(i+n>size+1)
//    
//        return error;
//    
//    size = size - n;
//    for(j=i-1;j<size;j++)
//    {
//        list[j] = list[j+n];
//    }
//  
//    return ok;
//
//
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
//    cout<<a.list_size()<<" ";
//    a.display();
//
//    int i,n;
//    int *item = new int[100];  //!!!!!important
//
//    //执行插入
//    cin>>i>>n;
//    for(j=0;j<n;j++)
//        cin>>item[j];
//    if(a.list_insert(i,n,item) == ok)
//    {
//        cout<<a.list_size()<<" ";
//
//        a.display();
//        
//        
//    }
//
//    else
//        cout<<"error"<<endl;
//    
//
//
//    //执行删除
//    cin>>i>>n;
//    if(a.list_del(i,n) == ok)
//    {
//        cout<<a.list_size()<<" ";
//        a.display();
//        
//    }
//    else
//        cout<<"error"<<endl;
//    
//    
//    return 1;
//
//
//}
