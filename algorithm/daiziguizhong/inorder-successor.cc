/**
 * @file inorder-successor.cc
 * @brief inorder successor node of a node 
 * in a binary tree
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-14
 */

#include <iostream>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right, *parent;
    TreeNode(int x=0):
        val(x), left(nullptr), right(nullptr),
        parent(nullptr) {}
};

TreeNode* LeftMostNode(TreeNode *node)
{
    if(node == nullptr) return nullptr;
    while(node->left) 
        node = node->left;
    return node;
}

TreeNode* Destroy(TreeNode *root)
{
    if(root == nullptr) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}

TreeNode* InorderSuccessor(TreeNode *node)
{
    if(node == nullptr) return nullptr;
    TreeNode *p = node->parent;
    if(node->right) {
        return LeftMostNode(node->right);
    }
    else {
        while(p && p->left != node) {
            node = p;
            p = node->parent;
        }
        return p;
    }
}

void AddChild(TreeNode *root, int child, int val) 
{
    if(root == nullptr) return;
    TreeNode *node = new TreeNode(val);
    node->parent = root;
    if(child == 0) {
        //left child
        root->left = node;
    }
    else {
        //right child
        root->right = node;
    }
}

void Test()
{
    TreeNode *root = new TreeNode(30);
    AddChild(root, 0, 10);
    AddChild(root, 1, 20);
    AddChild(root->left, 0, 50);
    AddChild(root->left->left, 1, 60);
    AddChild(root->right, 0, 45);
    AddChild(root->right, 1, 35);

    TreeNode * p = LeftMostNode(root);
    while(p) {
        cout << p->val << " ";
        p = InorderSuccessor(p);
    }
    root = Destroy(root);
}

int main(void)
{
    Test();
    return 0;
}
