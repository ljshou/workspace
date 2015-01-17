/**
 * @file deepest-right-node.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-16
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x=0):
        val(x), left(nullptr), right(nullptr) {}
};

void Traverse(TreeNode *root, int level, vector<TreeNode*> &right_nodes)
{
    if(!root) return;
    if(level >= right_nodes.size())
        right_nodes.push_back(root);
    else
        right_nodes[level] = root;
    Traverse(root->left, 1 + level, right_nodes);
    Traverse(root->right, 1 + level, right_nodes);
}

TreeNode* Destroy(TreeNode *root)
{
    if(root == nullptr) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}

void Test()
{
    TreeNode *root = new TreeNode(30);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(50);
    root->right->left = new TreeNode(45);
    root->right->left->left = new TreeNode(60);
    root->right->right = new TreeNode(35);

    vector<TreeNode*> vec;
    Traverse(root, 0, vec);
    for(auto p : vec) {
        cout << p->val << " ";
    }
    cout << endl;

    root = Destroy(root);
}

int main(void)
{
    Test();
    return 0;
}

