//
//  查找-折半查找.cpp
//  dataStructure
//
//  Created by ran on 2017/5/1.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include<iostream>
//using namespace std;
//int mid_search(int *a,int n,int key)
//{
//    int low = 0;
//    int high = n - 1;
//    int mid;
//    while(low <= high)   //<=           比较次数    至多 （log 2 n 下取整 +   1）
//    {
//        mid = (low + high) / 2;
//        if(a[mid] == key) return mid;
//        else if(a[mid] < key) {low = mid + 1;}
//        else if(a[mid] > key) {high = mid - 1;}
//    }
//    return -1;
//    
//}
//
//
//int main()
//{
//    int *a = new int[100];
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++)
//        cin>>a[i];
//    
//    
//    int key;
//    while(1)
//    {
//        cin>>key;
//        cout<<mid_search(a, n, key)<<endl;
//    }
//}
