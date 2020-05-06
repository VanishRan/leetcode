//
//  霍夫曼树-带权路径和.cpp
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
//    int depth;
//    BiNode *left;
//    BiNode *right;
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
//    int weightIndex;
//    int index;
//    int sum;
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
//    weightIndex = 0;
//    index = 0;
//    sum = 0;
//}
//BiNode* BiTree::createTree(BiNode *parent)
//{
//    BiNode *node;
//    char c = mainStr[index++];
//    if(c == '0')
//        node = NULL;
//    else {
//
//        node = new BiNode();
//        if(parent)
//        {
//            node->depth = parent->depth + 1;
//        }
//        else{
//            node->depth = 1;
//        }
//        node->ch = c;
//        node->left = createTree(node);
//        node->right = createTree(node);
//    }
//    return node;
//}
//void BiTree::preOrder(BiNode *node)
//{
//    if(node==NULL)
//        return;
//    if(node->left == NULL && node->right ==NULL)
//        sum += (node->depth - 1) * weights[weightIndex++];
//    preOrder(node->left);
//    preOrder(node->right);
//
//}
//
//int main()
//{
//    BiTree mytree;
//    
//    string str;
//    cin>>str;
//    mytree.mainStr.assign(str);
//    
//    int n;
//    int *weights = new int[100];
//    cin>>n;
//    for(int i=0;i<n;i++)
//        cin>>weights[i];
//    mytree.weights = weights;
//    
//    mytree.root = mytree.createTree(NULL);
//    mytree.preOrder(mytree.root);
//    cout<<mytree.sum<<endl;
//
//    return 0;
//
//}
