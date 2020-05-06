//
//  二叉树-遍历求深度.cpp
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
//    BiNode *parent;
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
//    int index;
//    int maxDepth;
//public:
//    BiTree();
//    BiNode* createTree(BiNode *T);
//    void preOrder(BiNode *node);
//};
//BiTree::BiTree()
//{
//    root = new BiNode();
//    mainStr = "";
//    index = 0;
//    maxDepth = 0;
//}
//BiNode* BiTree::createTree(BiNode *T)
//{
//    BiNode *node;
//    char c = mainStr[index++];
//    if(c == '0')
//        node = NULL;
//    else {
//        node = new BiNode();
//        node->ch = c;
//        if(T)
//        {
//            node->parent = T;
//            node->depth = T->depth + 1;
//        }
//        else
//        {
//            node->depth = 1;
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
//    if(node->left == NULL && node->right == NULL)
//    {
//        if(node->depth > maxDepth)
//            maxDepth = node->depth;
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
//    cin>>str;
//    mytree.mainStr.assign(str);        //注意
//    mytree.root = mytree.createTree(NULL);
//    mytree.preOrder(mytree.root);
//    cout<<mytree.maxDepth<<endl;
//    return 0;
//}


