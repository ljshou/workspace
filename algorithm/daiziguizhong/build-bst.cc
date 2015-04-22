/**
 * @file build-bst.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.io
 * @version 0.1.00
 * @date 2015-01-20
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x=0):
        val(x), left(nullptr), right(nullptr) {}
};

/**
 * @brief build Binary Search Tree using pre-order traversal
 * time O(N), space O(N)
 */
TreeNode* BuildBST(const vector<int> &preorder)
{
    TreeNode *root = nullptr, *node = nullptr;
    TreeNode *last = nullptr;
    stack<TreeNode*> s;
    for(auto x : preorder) {
        node = new TreeNode(x);
        if(s.empty()) { 
            root = node;
            s.push(root);
            continue;
        }

        //in left sub-tree of previous node
        if(x < s.top()->val) {
            s.top()->left = node;
        }
        else {
            //in right sub-tree of some parent node
            while(!s.empty() && x > s.top()->val) {
                last = s.top(); s.pop();
            }
            last->right = node;
        }
        s.push(node);
    }
    return root;
}

void PreOrder(TreeNode *root)
{
    if(root == nullptr)
        return;
    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(TreeNode *root)
{
    if(root == nullptr)
        return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}

TreeNode *Destroy(TreeNode *root)
{
    if(!root) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}

void Test()
{
    vector<int> preorder{4,2,3,6,5};
    TreeNode *root = BuildBST(preorder);

    PreOrder(root);
    cout << endl;

    InOrder(root);
    cout << endl;

    root = Destroy(root);
}

int main(void)
{
    Test();
    return 0;
}
