//
//  图的广度优先遍历.cpp
//  dataStructure
//
//  Created by ran on 2017/4/29.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include<iostream>
//#include<queue>
//using namespace std;
//class Graphic
//{
//public:
//    int matrix[100][100] = {0};
//    int vertexNum;
//    int visit[100]= {0};
//public:
//    Graphic()
//    {
//        vertexNum = 0;
//    }
//    
//    void BFS();
//    
//};
//
//void Graphic::BFS()
//{
//    queue<int> q;
//    
//    for(int i=0;i<vertexNum;i++)
//    {
//        if(!visit[i])
//        {
//            q.push(i);
//            while(!q.empty())
//            {
//                int a = q.front();
//                q.pop();
//                if(!visit[a])
//                {
//                    char ch = 'a' + a;
//                    cout<<ch<<" ";
//                    visit[a] = 1;
//                }
//                for(int j=0;j<vertexNum;j++)
//                {
//                    if(matrix[a][j] == 1)   //直接访问
//                    {
//                        if(!visit[j])
//                        {
//                            char ch = 'a' + j;
//                            cout<<ch<<" ";
//                            visit[j] = 1;
//                            q.push(j);
//                        }
//                    }
//                }
//            }
//            
//        }
//        
//    }
//}
//
//int main()
//{
//    Graphic g;
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
//    g.BFS();
//    return 0;
//}

//0 1 0 0 1 1
//1 0 1 1 0 1
//0 1 0 1 0 0
//0 1 1 0 1 1
//0 0 0 1 0 1
//1 1 0 1 1 0
