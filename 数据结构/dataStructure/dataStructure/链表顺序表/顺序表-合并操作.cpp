//
//  顺序表-合并操作.cpp
//  data structure
//
//  Created by ran on 16/9/14.
//  Copyright © 2016年 ran. All rights reserved.
//

//#include<iostream>
//using namespace std;
//#define ok 0
//#define error -1
//class SeqList
//{
//private:
//    int size;
//    int *list;
//    int maxsize;
//public:
//    SeqList();
//    ~SeqList();
//    int merge(int n1,int n2,int *a,int *b);
//    void display();
//};
//SeqList::SeqList()
//{
//    size=0;
//    maxsize=1000;
//    list = new int [maxsize];
//    
//}
//SeqList::~SeqList()
//{
//    delete []list;
//}
//int SeqList::merge(int n1, int n2, int *a, int *b)
//{
//    int i,j,k;
//    size = n1 + n2;
//    i=0;
//    j=0;
//    k=0;
//    while(i<n1 && j<n2)
//    {
//        if(a[i]<=b[j])
//        {
//            list[k] = a[i];
//            k++;
//            i++;
//        }
//        else
//        {
//            list[k] = b[j];
//            k++;
//            j++;
//        }
//    }
//    if(i == n1)
//    {
//        while(k<n1+n2)
//        {
//            list[k] = b[j];
//            k++;
//            j++;
//        }
//    }
//    else if(j == n2)
//    {
//        while(k<n1+n2)
//        {
//            list[k] = a[i];
//            i++;
//            k++;
//            
//        }
//    }
//    return ok;
//}
//void SeqList::display()
//{
//    int i;
//    cout<<size<<" ";
//    for(i=0;i<size;i++)
//        cout<<list[i]<<" ";
//    cout<<endl;
//}
//int main()
//{
//    int n1,n2;
//    int *a = new int[100];
//    int *b = new int[100];
//    SeqList mylist;
//    cin>>n1;
//    int i;
//    for(i=0;i<n1;i++)
//        cin>>a[i];
//    cin>>n2;
//    for(i=0;i<n2;i++)
//        cin>>b[i];
//    mylist.merge(n1, n2, a, b);
//    mylist.display();
//    return 0;
//}
