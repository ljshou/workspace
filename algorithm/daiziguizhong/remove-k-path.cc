/**
 * @file remove-k-path.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-15
 */
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x=0):
        val(x), left(nullptr), right(nullptr) {}
};

//first scheme
TreeNode* Remove(TreeNode* root, int k, int to_root, int &to_leaf)
{
    if(!root) {
        to_leaf = 0;
        return nullptr;
    }
    int left(0), right(0);
    root->left = Remove(root->left, k, 1+to_root, left);
    root->right = Remove(root->right, k, 1+to_root, right);
    to_leaf = max(left, right) + 1;
    
    if(to_leaf + to_root < k) {
        delete root;
        root = nullptr;
    }
    return root;
}

//second scheme
TreeNode* Remove2(TreeNode *root, int k, int level)
{
    if(!root) return nullptr;
    root->left = Remove2(root->left, k, 1 + level);
    root->right = Remove2(root->right, k, 1 + level);
    if(!root->left && !root->right && level < k) {
        delete root;
        root = nullptr;
    }
    return root;
}

TreeNode* Destroy(TreeNode *root)
{
    if(root == nullptr) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}

void PreOrder(TreeNode *root)
{
    if(!root) return;
    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void Test()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(7);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(8);

    PreOrder(root);
    cout << endl;

    //int to_leaf(0);
    //root = Remove(root, 4, 0, to_leaf);
    root = Remove2(root, 4, 1);

    PreOrder(root);
    cout << endl;

    root = Destroy(root);
}

int main(void)
{
    Test();
    return 0;
}
