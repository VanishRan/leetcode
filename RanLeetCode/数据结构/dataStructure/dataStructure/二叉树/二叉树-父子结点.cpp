//
//  二叉树-父子结点.cpp
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
//    BiNode *parent;
//    BiNode *left;
//    BiNode *right;
//    BiNode()
//    {
//        parent = NULL;
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
//    BiNode* createTree(BiNode *T);
//    void preOrder(BiNode *node);
//};
//BiTree::BiTree()
//{
//    root = new BiNode();
//    mainStr = "";
//    index = 0;
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
//        node->parent = T;
//        node->left = createTree(node);
//        node->right = createTree(node);
//    }
//    return node;
//}
//void BiTree::preOrder(BiNode *node)
//{
//    if(node==NULL)
//        return;
//    if(node->left == NULL && node->right == NULL)
//        cout<<node->ch<<" "<<node->parent->ch<<endl;   //输出格式稍有不同
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
//    return 0;
//}
//

