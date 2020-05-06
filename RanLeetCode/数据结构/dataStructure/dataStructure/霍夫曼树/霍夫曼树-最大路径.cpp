//
//  霍夫曼树-最大路径.cpp
//  dataStructure
//
//  Created by ran on 2017/4/16.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include<iostream>
//#include<string>
//using namespace std;
//class BiNode
//{
//public:
//    char ch;
//    BiNode *left;
//    BiNode *right;
//    BiNode *parent;
//    int weight;
//    int sumOfWeight;   //到该结点的路径和
//    BiNode()
//    {
//        left = NULL;
//        right = NULL;
//        parent = NULL;
//    }
//};
//class BiTree
//{
//public:
//    BiNode *root;
//    string mainStr;
//    int *weights;
//
//    int weightIndex;
//    int index;
//    
//    int maxPath;
//    
//public:
//    BiTree();
//    BiNode* createTree(BiNode *parent);
//    void preOrder(BiNode *node);
//};
//BiTree::BiTree()
//{
//    root = new BiNode();
//    mainStr = "";
//    weights = new int[100];
//    index = 0;
//    weightIndex = 0;
//    
//    maxPath = 0;
//
//}
//BiNode* BiTree::createTree(BiNode *parent)  //累积路经和
//{
//    BiNode *node;
//    char c = mainStr[index++];
//    if(c == '0')
//        node = NULL;
//    else {
//        node = new BiNode();
//        node->ch = c;
//        node->weight = weights[weightIndex++];
//        if(parent)
//        {
//            node->sumOfWeight = parent->sumOfWeight + node->weight;
//        }
//        else
//        {
//            node->sumOfWeight = node->weight;
//        }
//        node->left = createTree(node);
//        node->right = createTree(node);
//    }
//    return node;
//}
//void BiTree::preOrder(BiNode *node)
//{
//    if(node==NULL)
//        return;
//
//    if(node->sumOfWeight > maxPath)
//    {
//        maxPath = node->sumOfWeight;
//    }
//    preOrder(node->left);
//    preOrder(node->right);
//
//}
//
//int main()
//{
//    BiTree mytree;
//    string str;
//    int n;
//    int *weights = new int[100];
//    cin>>str;
//    cin>>n;
//    for(int i=0;i<n;i++)
//        cin>>weights[i];
//    mytree.mainStr.assign(str);        //注意
//    mytree.weights = weights;
//    mytree.root = mytree.createTree(NULL);
//    mytree.preOrder(mytree.root);
//    cout<<mytree.maxPath<<endl;
//    return 0;
//}
