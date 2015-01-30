/**
 * @file tree-path.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-27
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x=0):
        val(x), left(nullptr), right(nullptr) {}
};

bool FindPath(TreeNode *root, TreeNode *node, vector<int> &path)
{
    if(root == nullptr || node == nullptr)
        return false;
    if(root == node)
        return true;
    path.push_back(root->val);
    if(FindPath(root->left, node, path)) return true; 
    if(FindPath(root->right, node, path)) return true;
    path.pop_back();
    return false;
}

void Test()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    vector<int> path;
    if(FindPath(root, root->left->left->left, path)) {
        for(auto x : path) 
            cout << x << " ";
        cout << endl;
    }
}

int main(void)
{
    Test();
    return 0;
}
