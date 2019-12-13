//
//  图的最短路径.cpp
//  dataStructure
//
//  Created by ran on 2017/5/1.
//  Copyright © 2017年 ran. All rights reserved.
//
//
//图的最短路径  迪杰斯特拉算法   跟普里姆算法差不多  主旋律 都是  那个一维数组
//#include <iostream>
//using namespace std;
//class Graph   //三个一维数组
//{
//public:
//    int matrix[10][10] = {0};
//    int n;
//    int finish[10] = {0};
//    int d[10] = {0}; //v0到每个点的最短路径的权值和
//    int p[10] = {0}; //最短路径前一个节点的下标
//public:
//    Graph()
//    {
//        n = 0;
//    }
//    void dijkstra();
//    void display(int n);
//};
//
//void Graph::dijkstra()
//{
//    int i,j,k;
//    finish[0] = 1;//v0已经求出最短路径
//    p[0] = 0;
//    for(i=0;i<n;i++)
//        d[i] = matrix[0][i];
//    
//    for(i=1;i<n;i++)  //求出剩下的n-1个点的最短路径
//    {
//        int min = 99;
//        k = 0;
//        for(j=1;j<n;j++)   //找到要访问的下一个权值最小结点
//        {
//            if(!finish[j] && d[j] < min)
//            {
//                min = d[j];
//                k = j;
//            }
//        }
//        
//        finish[k] = 1;
//        
//        for(j=1;j<n;j++)
//        {
//            if(!finish[j] && min + matrix[k][j] < d[j])
//            {
//                d[j] = min + matrix[k][j];
//                p[j] = k;
//            }
//        }
//    }
//    
//}
//
//void Graph::display(int n)
//{
//    cout<<d[n]<<endl;
//    cout<<n<<" ";
//    int a = p[n];
//    while(a)
//    {
//        cout<<a<<" ";
//        a = p[a];
//    }
//    cout<<a<<endl;
//}
//
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
//    mygraph.dijkstra();
//    mygraph.display(8);//手动改值
//}



//0 5 99 7 15
//99 0 5 99 99
//99 99 0 99 1
//99 99 2 0 99
//99 99 99 99 0



//9
//0 1 5 99 99 99 99 99 99
//1 0 3 7 5 99 99 99 99
//5 3 0 99 1 7 99 99 99
//99 7 99 0 2 99 3 99 99
//99 5 1 2 0 3 6 9 99
//99 99 7 99 3 0 99 5 99
//99 99 99 3 6 99 0 2 7
//99 99 99 99 9 5 2 0 4
//99 99 99 99 99 99 7 4 0






