//
//  二叉树-叶子数量.cpp
//  dataStructure
//
//  Created by ran on 2017/4/12.
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
//    int leafNumber;
//public:
//    BiTree();
//    BiNode* createTree();
//    void preOrder(BiNode *node);
//};
//BiTree::BiTree()
//{
//    root = new BiNode();
//    mainStr = "";
//    index = 0;
//    leafNumber = 0;
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
//    if(node->left == NULL && node->right == NULL)
//        leafNumber++;
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
//    mytree.root = mytree.createTree();
//    mytree.preOrder(mytree.root);
//    cout<<mytree.leafNumber<<endl;
//    return 0;
//}
//
