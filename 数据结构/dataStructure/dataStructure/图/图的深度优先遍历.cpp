//
//  图的深度优先遍历.cpp
//  dataStructure
//
//  Created by ran on 2017/4/20.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include<iostream>
//using namespace std;
//class Graph {
//public:
//    int vertexNum;
//    int matrix[100][100] = {0};
//    int visited[100] = {0};   // 0 没有访问过
//public:
//    Graph()
//    {
//        vertexNum = 0;
//    }
//    void DFS1();
//    void DFS2(int vertex);
//    
//};
//
//void Graph::DFS1()
//{
//    for(int i=0;i<vertexNum;i++)
//        if(!visited[i])
//            DFS2(i);
//}
//
//void Graph::DFS2(int vertex)
//{
//    visited[vertex] = 1;
//    cout<<vertex<<" ";
//    
//    for(int i=0;i<vertexNum;i++)     //找到所有连接点
//    {
//        if(matrix[vertex][i] == 1)
//        {
//                if(!visited[i])
//                    DFS2(i);
//            
//        }
//    }
//    
//
//}
//
//
//
//int main()
//{
//    Graph g;
//    int n;
//    cin>>n;
//    
//    int a[100][100] = {0};
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//        {
//            cin>>a[i][j];
//            g.matrix[i][j] = a[i][j];
//        }
//    }
//    g.vertexNum = n;
//    
//    g.DFS1();
//    
//}









