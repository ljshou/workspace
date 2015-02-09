/**
 * @file is-complete-tree.cc
 * @brief determine whether a binary tree is
 * complete
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-14
 */

#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x=0):
        val(x), left(nullptr), right(nullptr) {}
};

TreeNode* Destroy(TreeNode *root)
{
    if(root == nullptr) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}


/**
 * O(N)
 */
bool IsComplete(TreeNode *root)
{
    if(!root) return true;
    queue<TreeNode*> q;
    q.push(root);
    bool flag = false;
    while(!q.empty()) {
        root = q.front(); q.pop();
        if(root->left == nullptr) {
            flag = true;
        }
        else {
            if(flag) return false;
            q.push(root->left);
        }

        if(root->right == nullptr) {
            flag = true;
        }
        else {
            if(flag) return false;
            q.push(root->right);
        }
    }
    return true;
}

void Test()
{
    assert(IsComplete(nullptr) == true);
    TreeNode *root = new TreeNode(1);
    assert(IsComplete(root) == true);
    root->left = new TreeNode(2);
    assert(IsComplete(root) == true);
    root->left->right = new TreeNode(3);
    assert(IsComplete(root) == false);

    root = Destroy(root);
}

int main(void)
{
    Test();
    return 0;
}
