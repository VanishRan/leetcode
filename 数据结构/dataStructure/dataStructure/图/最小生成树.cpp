//
//  最小生成树.cpp
//  dataStructure
//
//  Created by ran on 2017/5/1.
//  Copyright © 2017年 ran. All rights reserved.
//

//两个数组，一个记录路径  一个记录最小消耗    最小生成树
// 普里姆算法   克鲁斯卡尔算法

//#include<iostream>   //贪心法不断更新当前 的lowcost
//using namespace std;
//class Graph
//{
//public:
//    int matrix[10][10] = {0};
//    int n;
//    int lowcost[10] = {0};
//public:
//    Graph()
//    {
//        n = 0;
//    }
//    int prim();
//};
//int Graph::prim()
//{
//    int i,j,k;
//    int sum =0;
//    
//    for(i=1;i<n;i++)
//        lowcost[i] = matrix[0][i];
//    lowcost[0] = 0;
//    for(i=1;i<n;i++)  //找N-1个点
//    {
//        int min = 999;
//        k=0;
//        for(j=1;j<n;j++)
//        {
//            if(lowcost[j] != 0 && lowcost[j] < min)
//            {
//                min = lowcost[j];
//                k = j;
//            }
//        }
//        
//        cout<<k<<" ";
//        sum = sum + min;
//        
//        lowcost[k] = 0;  //表示已经访问过
//        
//        for(j=1;j<n;j++)
//        {
//            if(lowcost[j]!=0 && matrix[k][j] < lowcost[j])
//            {
//                lowcost[j] = matrix[k][j];
//            }
//        }
//    }
//    cout<<endl;
//    return sum;
//}
//int main()
//{
//    Graph mygraph;
//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++)
//        for(int j=0;j<n;j++)
//            cin>>mygraph.matrix[i][j];
//    
//    mygraph.n = n;
//    cout<<mygraph.prim()<<endl;
//}

//答案 最小权值和  15
//99 6 1 5 99 99
//6 99 5 99 3 99
//1 5 99 5 6 4
//5 99 5 99 99 2
//99 3 6 99 99 6
//99 99 4 2 6 99
