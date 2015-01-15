/**
 * @file print-nodes-distance.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-15
 */
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right, *parent;
    TreeNode(int x=0):
        val(x),left(nullptr), right(nullptr), parent(nullptr) {}
};

/**
 * @brief print level'th depth nodes
 * level starts from 0
 */
void PrintLevel(TreeNode *root, int level)
{
    if(!root || level < 0) return;
    if(level == 0) {
        cout << root->val << " ";
        return;
    }
    PrintLevel(root->left, level-1);
    PrintLevel(root->right, level-1);
}

void PrintNodesDistance(TreeNode *root, int dist)
{
    if(!root) return;
    //case 1
    PrintLevel(root, dist);

    //case2
    TreeNode *p = root->parent;
    for(int i=1; i<=dist && p; ++i) {
        if(i == dist) {
            PrintLevel(p, 0);
            continue;
        }
        if(p->left == root) {
            PrintLevel(p->right, dist-i-1);
        }
        else {
            PrintLevel(p->left, dist-i-1);
        }
        root = p;
        p = root->parent;
    }
    cout << endl;
}

TreeNode* Destroy(TreeNode *root)
{
    if(root == nullptr) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
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

void PreOrder(TreeNode *root)
{
    if(root == nullptr) return;
    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void Test()
{
    TreeNode *root = new TreeNode(30);
    AddChild(root, 0, 10);
    AddChild(root, 1, 20);
    AddChild(root->left, 0, 50);
    AddChild(root->left, 1, 70);
    AddChild(root->left->left, 1, 60);
    AddChild(root->right, 0, 45);
    AddChild(root->right, 1, 35);
    PreOrder(root);
    cout << endl;

    PrintNodesDistance(root->left->right, 0);
    PrintNodesDistance(root->left->right, 1);
    PrintNodesDistance(root->left->right, 2);
    PrintNodesDistance(root->left->right, 3);
    PrintNodesDistance(root->left->right, 4);
    PrintNodesDistance(root->left->right, 5);

    root = Destroy(root);
}

int main(void)
{
    Test();
    return 0;
}
