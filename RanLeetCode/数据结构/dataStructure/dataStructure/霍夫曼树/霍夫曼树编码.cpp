//
//  霍夫曼树编码.cpp
//  dataStructure
//
//  Created by ran on 16/11/20.
//  Copyright © 2016年 ran. All rights reserved.
//

//#include<iostream>
//#include<string>
////#include<cstring>
//using namespace std;
//const int MaxW = 9999;
//class HuffNode
//{
//public:
//    int weight;
//    int parent;
//    int leftchild;
//    int rightchild;
//};
//
//class HuffMan
//{
//private:
//    void MakeTree();
//    void SelectMin(int pos,int *s1,int *s2);//从1到POS找出权值最小的两个节点
//public:									    //吧结点下标保存在S1,S2中
//    int len;//结点数量
//    int lnum;//叶子结点
//    HuffNode *huffTree;
//    string *huffCode;//每个字符的赫夫曼编码
//    void MakeTree(int n,int wt[]);
//    void Coding();
//    void Destroy();
//};
//
////这个函数就是吧所有的结点初始化一下
//void HuffMan::MakeTree(int n,int wt[]) //叶子结点n　　叶子权值数组
//{
//    int i;
//    lnum = n; //叶子结点
//    len = 2*n-1; //结点数量　　完全二叉树
//    huffTree = new HuffNode[2*n];    //从1开始计算   顺序储存结构
//    huffCode = new string[lnum+1];   //从1开始计算 huffcode实质是二维字符数组
//    //第i行表示第i个字符对应的编码
//    for(i=1;i<=n;i++)
//        huffTree[i].weight = wt[i-1];
//    for(i=1;i<=len;i++)
//    {
//        if(i>n)
//            huffTree[i].weight = 0;   //前面N个是叶子，已经设值
//        huffTree[i].parent = 0;
//        huffTree[i].leftchild = 0;
//        huffTree[i].rightchild = 0;
//    }
//    MakeTree();
//}
//void HuffMan::SelectMin(int pos,int *s1,int *s2)
//{
//    int w1,w2,i;
//    w1 = w2 = MaxW;   //初始化为最大值
//    *s1 = *s2 = 0;
//    for(i=1;i<=pos;i++)
//    {
//        //父亲为0证明第i点还没被选出来
//        if(huffTree[i].weight<w1 && huffTree[i].parent==0)
//        {
//            w2 = w1;
//            *s2 = *s1;
//            w1 = huffTree[i].weight;
//            *s1 = i;
//        }
//        else if(huffTree[i].weight<w2 && huffTree[i].parent==0)
//        {
//            w2 = huffTree[i].weight;
//            *s2 = i;
//        }
//    }
//}
//void HuffMan::MakeTree()
//{
//    int i,s1,s2;
//    for(i=lnum+1;i<=len;i++)   //非叶子结点
//    {
//        SelectMin(i-1,&s1,&s2);    //找出两个权值最小的  然后合成一棵树 注意&&&&&
//        huffTree[s1].parent = i;
//        huffTree[s2].parent = i;
//        huffTree[i].leftchild = s1;
//        huffTree[i].rightchild = s2;
//        huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;
//    }
//}
//void HuffMan::Destroy()
//{
//    len = 0;
//    lnum = 0;
//    delete []huffTree;
//    delete []huffCode;
//}
//void HuffMan::Coding()
//{
//    char *cd;             //课本p147
//    int i,c,f,start;
//    
//    cd = new char[lnum];
//    cd[lnum-1] = '\0';    //编码的结束符
//    
//    for(i=1;i<=lnum;i++)
//    {
//        start= lnum - 1;    //结束符的位置
//        for(c=i,f=huffTree[i].parent;f!=0;c=f,f=huffTree[f].parent)
//        {
//            if(huffTree[f].leftchild == c)
//                cd[--start] = '0';
//            else
//                cd[--start] = '1';
//        }
//        
//        huffCode[i].assign(&cd[start]);    //吧cd中从start到末尾的编码复制
//        
//    }
//    delete []cd;
//}
//int main()
//{
//    int t,n,i,j;
//    int wt[800];
//    HuffMan myHuff;
//    cin>>t;
//    for(i=0;i<t;i++)
//    {
//        cin>>n;
//        for(j=0;j<n;j++)
//            cin>>wt[j];
//        myHuff.MakeTree(n,wt);
//        myHuff.Coding();
//        for(j=1;j<=n;j++)
//        {
//            cout<<myHuff.huffTree[j].weight<<"-";
//            cout<<myHuff.huffCode[j]<<endl;
//        }
//        myHuff.Destroy();
//    }
//    return 0;
//}
//





