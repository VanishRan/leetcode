//
//  二叉排序树-创建、插入.cpp
//  dataStructure
//
//  Created by ran on 2017/5/2.
//  Copyright © 2017年 ran. All rights reserved.
//

//#include<iostream>     //好好理解一下指针！
//using namespace std;
//class Node {
//public:
//    int data;
//    Node *left;
//    Node *right;
//    Node *parent;
//public:
//    Node() {left = NULL; right = NULL; parent = NULL; data = -1;}
//};
//
//class BST {       //binary sort tree       left < mid  < right  中序遍历
//public:
//    int *a;
//    int size;
//    Node *root;
//    
//public:
//    BST() { a = new int [100]; size = 0; root = new Node();}
//    int BST_search(Node *T,Node *parent, int key,Node **ret);
//    void BST_Insert(int key);
//    void BST_delete1(int key);
//    void BST_display(Node *T);
//
//};
//int BST::BST_search(Node *T,Node *parent,int key,Node **ret) //T当前结点  ret返回的结点
//{
//    if(!T)
//    {
//        *ret = parent;
//        return 0;
//    }
//    else if(T->data == key)
//    {
//        *ret = T;
//        return 1;
//    }
//    else if(key < T->data)
//        return BST_search(T->left,T ,key, ret);
//    else
//        return BST_search(T->right, T ,key, ret);   //没有根结点
//}
//
//
//void BST::BST_Insert(int key)
//{
//    Node *ret;
//    if(!BST_search(root,NULL, key, &ret))  //没找到，回到到父节点
//    {
//        Node *p = new Node();
//        p->data = key;
//        
//        if(ret->data < 0)    //默认排序数都大于0   初始化-1
//            root->data = key;    //插入根结点
//        else if(key < ret->data)
//        {
//            ret->left = p;
//            p->parent = ret;
//        }
//        else
//        {
//            ret->right = p;
//            p->parent = ret;
//        }
//    }
//}
//
//void BST::BST_delete1(int key)  //删除有bug  救命
//{
//    Node *ret;
//    Node *p;
//    Node *parent;
//    if(BST_search(root,NULL, key, &ret))
//    {
//        parent = ret->parent;
//        if(ret->left == NULL && ret->right == NULL) //叶子结点
//        {
//            if(parent->left->data == ret->data)
//                parent->left = NULL;
//            else
//                parent->right = NULL;
//            delete ret;
//            ret = NULL;
//        }
//        else if(ret->left == NULL) //只有右子树
//        {
//            p = ret;
//            ret = ret->right;
//            
//            if(parent->left->data == p->data)
//                parent->left = ret;
//            else
//                parent->right = ret;
//            
//            delete p;
//            p = NULL;
//            
//        }
//        else if(ret->right == NULL) //只有左子树
//        {
//            p = ret;
//            ret = ret->left;
//            
//            if(parent->left->data == p->data)
//                parent->left = ret;
//            else
//                parent->right = ret;
//            
//            delete p;
//            p = NULL;
//        }
//        else       //左右都不为空
//        {
//            Node *q;  //q代表前一个
//            q = ret;
//            p = ret->left;
//            while(p->right)
//            {
//                q = p;
//                p = p->right;
//            }
//            ret->data = p->data;
//            if(q == ret)
//            {
//                ret->left = p->left;
//                delete p;
//                p = NULL;
//            }
//            else
//            {
//                q->right = p->left;
//                delete p;
//                p = NULL;
//            }
//        }
//    }
//}
//
//void BST::BST_display(Node *T)
//{
//    if(!T)
//        return;
//    BST_display(T->left);
//    cout<<T->data<<" ";
//    BST_display(T->right);
//}
//
//int main()
//{
//    BST mybst;
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        int key;
//        cin>>key;
//        mybst.BST_Insert(key);
//    }
//    mybst.BST_display(mybst.root);
//    
////    cin>>t;
////    while(t--)
////    {
////        int key;
////        cin>>key;
////        mybst.BST_delete(key);
////    }
////    mybst.BST_display(mybst.root);
//}






