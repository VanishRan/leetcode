//
//  拓扑排序.cpp
//  dataStructure
//
//  Created by ran on 2017/5/16.
//  Copyright © 2017年 ran. All rights reserved.
//

//拓扑排序算法：给出有向图邻接矩阵       (入度为0，  删，并且删掉尾巴)
//1.逐列扫描矩阵，找出入度为0且编号最小的顶点v
//2.输出v，并标识v已访问
//3.把矩阵第v行全清0
//重复上述步骤，直到所有顶点输出为止

//#include<iostream>
//using namespace std;
//void topo_sort(int matrix[10][10],int n)
//{
//    int finish[10] = {0};
//    int i,j,k,v = 0,sum;
//    for(i=0;i<n;i++)   //输出n个点
//    {
//        //找入度为0，看列
//        
//        for(j=0;j<n;j++)
//        {
//            sum = 0;
//            v = 0;
//            
//            for(k=0;k<n;k++)
//            {
//                
//                if(matrix[k][j] == 0)
//                {
//                    sum++;
//                }
//
//                
//            }
//            if(sum == n && !finish[j])
//            {
//                v = j;
//                break;
//            }
//        }
//        //输出标志访问
//        cout<<v<<" ";
//        finish[v] = 1;
//        
//        //删掉尾巴
//        for(j = 0;j<n;j++)
//        {
//            matrix[v][j] = 0;
//        }
//        
//    }
//    
//}
//int main()
//{
//    int m[10][10] = {0};
//    int i,j,n;
//    cin>>n;
//    for(i=0;i<n;i++)
//        for(j=0;j<n;j++)
//            cin>>m[i][j];
//    topo_sort(m, n);
//}
