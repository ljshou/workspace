/**
 * @file largest-bst.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-03
 */

#include <iostream>
using namespace std;

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int x=0):
        val(x), left(nullptr), right(nullptr) {}
};

int LargestBST(TreeNode *root, int &res)
{
    if(!root) return 0;
    int size = 1;
    if(root->left && root->val > root->left->val) {
        size += LargestBST(root->left, res);
    }
    if(root->right && root->val < root->right->val) {
        size += LargestBST(root->right, res);
    }
    res = max(res, size);
    return size;
}

TreeNode* Destroy(TreeNode *root)
{
    if(!root) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}

void Test()
{
    TreeNode *root = new TreeNode(15);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(2);
    root->left->right->right = new TreeNode(5);

    int res = 0;
    LargestBST(root, res);
    cout << "LargestBST: " << res << endl;

    root = Destroy(root);
}

int main(void)
{
    Test();
    return 0;
}
