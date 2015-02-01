/**
 * @file serialize-tree.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-04
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
using namespace std;
#define MARKER -1

struct TreeNode 
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x = 0): 
        val(x), left(nullptr), right(nullptr) {}
};

void Serialize(TreeNode *root,  ofstream &out)
{
    if(root == nullptr) {
        out << MARKER << "\t";
        return;
    }
    out << root->val << "\t";
    Serialize(root->left, out);
    Serialize(root->right, out);
}

TreeNode * Deserialize(ifstream &in)
{
    int v(0);
    TreeNode *root = nullptr;
    in >> v;
    if(v == MARKER) return nullptr;
    else {
        root = new TreeNode(v);
        root->left = Deserialize(in);
        root->right = Deserialize(in);
    }
    return root;
}

TreeNode* Destroy(TreeNode *root)
{
    if(root == nullptr) 
        return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}

bool IsSameTree(TreeNode *lhs, TreeNode *rhs)
{
    if(lhs == nullptr && rhs == nullptr)
        return true;
    else if(lhs == nullptr || rhs == nullptr)
        return false;
    return lhs->val == rhs->val && IsSameTree(lhs->left, rhs->left)
        && IsSameTree(lhs->right, rhs->right);
}


int main(void)
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(3);
    root->right->left->right = new TreeNode(4);

    ofstream out("tree.out");
    Serialize(root, out);
    out.close();

    ifstream in("tree.out");
    TreeNode *root2 = Deserialize(in);
    in.close();

    assert(true == IsSameTree(root, root2));

    root = Destroy(root);
    root2 = Destroy(root2);
    return 0;
}
