/**
 * @file split-bst.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-27
 */

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x=0): 
        val(x), left(nullptr), right(nullptr) {}
};

pair<TreeNode*, TreeNode*> SplitTrees(TreeNode *root, int x)
{
    TreeNode *left_tree(nullptr), *right_tree(nullptr);
    if(!root) 
        return make_pair(left_tree, right_tree);
    if(root->val == x) {
        right_tree = root->right;
        root->right = nullptr;
        left_tree = root;
    }
    else if(root->val < x) {
        left_tree = root;
        auto sub_trees = SplitTrees(root->right, x);
        left_tree->right = sub_trees.first;
        right_tree = sub_trees.second;
    }
    else {
        right_tree = root;
        auto sub_trees = SplitTrees(root->left, x);
        right_tree->left = sub_trees.second;
        left_tree = sub_trees.first;
    }
    return make_pair(left_tree, right_tree);
}

void InOrder(TreeNode *root)
{
    if(!root) return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}

void Test()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    auto sub_trees = SplitTrees(root, 4);
    InOrder(sub_trees.first);
    cout << endl;

    InOrder(sub_trees.second);
    cout << endl;
}

int main(void)
{
    Test();
    return 0;
}
