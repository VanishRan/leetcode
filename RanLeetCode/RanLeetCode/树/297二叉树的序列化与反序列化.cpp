//
//  297二叉树的序列化与反序列化.cpp
//  RanLeetCode
//
//  Created by mahuanran on 2020/5/2.
//  Copyright © 2020 mahuanran. All rights reserved.
//

#include "common.h"
//下次再做吧
//说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。class Codec {
//    class Codec {
//    public:
//
//        string serialize(TreeNode* root) {
//            ostringstream out;
//            serialize(root, out);
//            return out.str();
//        }
//
//        TreeNode* deserialize(string data) {
//            istringstream in(data);
//            return deserialize(in);
//        }
//
//    private:
//
//        void serialize(TreeNode* root, ostringstream& out) {
//            if (root) {
//                out << root->val << ' ';
//                serialize(root->left, out);
//                serialize(root->right, out);
//            } else {
//                out << "# ";
//            }
//        }
//
//        TreeNode* deserialize(istringstream& in) {
//            string val;
//            in >> val;
//            if (val == "#")
//                return nullptr;
//            TreeNode* root = new TreeNode(stoi(val));
//            root->left = deserialize(in);
//            root->right = deserialize(in);
//            return root;
//        }
//    };




//int main() {
//    TreeNode *t1 = new TreeNode (1);
//    TreeNode *t2 = new TreeNode (2);
//    TreeNode *t3 = new TreeNode (3);
//    TreeNode *t4 = new TreeNode (4);
//    TreeNode *t5 = new TreeNode (5);
//    t1->left = t2;
//    t1->right = t3;
//    
//    t3->left = t4;
//    t3->right = t5;
//    
//    TreeNode *ttt;
//    //Codec s;
//    s.deserialize(s.serialize(NULL));
//    
//
//
//}

