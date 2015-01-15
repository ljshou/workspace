/**
 * @file print-edge-nodes.cc
 * @brief print edge nodes of
 * a binary tree
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-14
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x=0):
        val(x), left(nullptr), right(nullptr) {}
};

void PrintLeftEdges(TreeNode *root, bool flag)
{
    if(root == nullptr) return;
    if(flag || (!root->left && !root->right))
        cout << root->val << " ";
    PrintLeftEdges(root->left, flag);
    PrintLeftEdges(root->right, false);
}

void PrintRightEdges(TreeNode *root, bool flag)
{
    if(root == nullptr) return;
    PrintRightEdges(root->left, false);
    PrintRightEdges(root->right, flag);
    if(flag || (!root->left && !root->right))
        cout << root->val << " ";
}

void PrintEdges(TreeNode *root)
{
    if(root == nullptr) return;
    cout << root->val << " ";
    PrintLeftEdges(root->left, true);
    PrintRightEdges(root->right, true);
}

TreeNode* Destroy(TreeNode *root)
{
    if(root == nullptr) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}

int main(void)
{
    TreeNode *root = new TreeNode(30);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(50);
    root->right->left = new TreeNode(45);
    root->right->right = new TreeNode(35);
    PrintEdges(root);
    root = Destroy(root);
    return 0;
}
