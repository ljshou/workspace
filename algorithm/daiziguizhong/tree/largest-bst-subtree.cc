/**
 * @file largest-bst-subtree.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-03
 */

#include <iostream>
#include <cassert>
using namespace std;

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int x=0):
        val(x), left(nullptr), right(nullptr) {}
};

/**
 * @retval -1: not a bst
 * @retval positive integer: # of nodes 
 */
int LargestBST(TreeNode *root, int &min_val, int &max_val, int &res)
{
    if(!root) return 0;
    bool isBst = true;

    int left_nodes = LargestBST(root->left, min_val, max_val, res);
    int cur_min = left_nodes == 0 ? root->val : min_val;
    if(left_nodes == -1 || (left_nodes != 0 && max_val >= root->val)) {
        isBst = false;
    }

    int right_nodes = LargestBST(root->right, min_val, max_val, res);
    int cur_max = right_nodes == 0 ? root->val : max_val;
    if(right_nodes == -1 || (right_nodes != 0 && root->val >= min_val)) {
        isBst = false;
    }

    if(isBst) {
        cout << root->val << " is bst" << endl;
        min_val = cur_min, max_val = cur_max;
        res = max(res, 1+left_nodes+right_nodes);
        return 1+left_nodes+right_nodes;
    }
    else {
        return -1;
    }
}

int LargestBST(TreeNode *root)
{
    int min_val, max_val;
    int res = 1;
    LargestBST(root, min_val, max_val, res);
    return res;
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
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    assert(LargestBST(root) == 3);

    root = Destroy(root);
}

int main(void)
{
    Test();
    return 0;
}
