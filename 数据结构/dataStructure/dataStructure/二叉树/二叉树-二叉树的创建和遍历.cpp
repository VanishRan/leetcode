//
//  二叉树-二叉树的创建和遍历.cpp
//  dataStructure
//
//  Created by ran on 2017/4/11.
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
//    int index;
//public:
//    BiTree();
//    BiNode* createTree();
//    void preOrder(BiNode *node);
//    void inOrder(BiNode *node);
//    void postOrder(BiNode *node);
//};
//BiTree::BiTree()
//{
//    root = new BiNode();
//    mainStr = "";
//    index = 0;
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
//        node->left = createTree();
//        node->right = createTree();
//    }
//    return node;
//}
//void BiTree::preOrder(BiNode *node)
//{
//    if(node==NULL)
//        return;
//    cout<<node->ch<<" ";
//    preOrder(node->left);
//    preOrder(node->right);
//    
//}
//void BiTree::inOrder(BiNode *node)
//{
//    if(node==NULL)
//        return;
//    inOrder(node->left);
//    cout<<node->ch<<" ";
//    inOrder(node->right);
//    
//}
//void BiTree::postOrder(BiNode *node)
//{
//    if(node==NULL)
//        return;
//    postOrder(node->left);
//    postOrder(node->right);
//    cout<<node->ch<<" ";
//    
//}
//int main()
//{
//    BiTree *mytree = new BiTree();
//    string str;
//    cin>>str;
//    mytree->mainStr.assign(str);
//    mytree->root = mytree->createTree();
//    mytree->preOrder(mytree->root);
//    cout<<endl;
//    mytree->inOrder(mytree->root);
//    cout<<endl;
//    mytree->postOrder(mytree->root);
//    cout<<endl;
//    return 0;
//    
//}
