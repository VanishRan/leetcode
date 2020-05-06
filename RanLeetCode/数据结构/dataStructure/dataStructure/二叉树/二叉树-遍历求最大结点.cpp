//
//  二叉树-遍历求最大结点.cpp
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
//    int weight;
//    BiNode()
//    {
//        left = NULL;
//        right = NULL;
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
//    int maxWeight;
//    char maxChar;
//public:
//    BiTree();
//    BiNode* createTree();
//    void preOrder(BiNode *node);
//};
//BiTree::BiTree()
//{
//    root = new BiNode();
//    mainStr = "";
//    weights = new int[100];
//    index = 0;
//    weightIndex = 0;
//    maxWeight = 0;
//    maxChar = '\0';
//    
//}
//BiNode* BiTree::createTree()
//{
//    BiNode *node;
//    char c = mainStr[index++];
//    if(c == '0')
//        node = NULL;
//    else {
//        node = new BiNode();
//        node->ch = c;
//        node->weight = weights[weightIndex++];
//        node->left = createTree();
//        node->right = createTree();
//    }
//    return node;
//}
//void BiTree::preOrder(BiNode *node)
//{
//    if(node==NULL)
//        return;
//    
//    if(node->weight > maxWeight)
//    {
//        maxWeight = node->weight;
//        maxChar = node->ch;
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
//    mytree.root = mytree.createTree();
//    mytree.preOrder(mytree.root);
//    cout<<mytree.maxChar<<endl;
//    return 0;
//}



