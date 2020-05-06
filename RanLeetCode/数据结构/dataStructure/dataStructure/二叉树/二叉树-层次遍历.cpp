//
//  二叉树-层次遍历.cpp
//  dataStructure
//
//  Created by ran on 2017/4/13.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include<iostream>
//#include<string>
//#include<queue>
//using namespace std;
//class BiNode
//{
//public:
//    char ch;
//    BiNode *left;
//    BiNode *right;
//    
//public:
//    BiNode()
//    {
//        left = NULL;
//        right = NULL;
//    }
//};
//
//class BiTree
//{
//public:
//    BiNode *root;
//    string mainStr;
//    int index;
//    
//public:
//    BiTree();
//    BiNode* createTree();
//    void levelTraverse();
//};
//
//BiTree::BiTree()
//{
//    root = new BiNode();
//    mainStr = "";
//    index = 0;
//}
//
//BiNode* BiTree::createTree()
//{
//    BiNode *n;
//    char c = mainStr[index++];
//    if(c == '0' || index >= mainStr.length())
//        n = NULL;
//    else
//    {
//        n = new BiNode();
//        n->ch = c;
//        n->left = createTree();
//        n->right = createTree();
//        
//    }
//    return n;
//    
//    
//}
//void BiTree::levelTraverse()
//{
//    queue<BiNode*> q;
//    q.push(root);
//    while(!q.empty())
//    {
//        BiNode *a = q.front();
//        q.pop();
//        if(a != NULL)
//        {
//            cout<<a->ch;
//            q.push(a->left);
//            q.push(a->right);
//        }
//    }
//}
//
//int main()
//{
//    BiTree mytree;
//    string str;
//    cin>>str;
//    mytree.mainStr.assign(str);
//    mytree.root = mytree.createTree();
//    mytree.levelTraverse();
//    cout<<endl;
//    return 0;
//}

