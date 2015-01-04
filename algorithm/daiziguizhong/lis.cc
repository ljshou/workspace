/**
 * @file list.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-04
 */

#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x = 0):
        val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode *root, unordered_map<TreeNode*, pair<int,int> >  &s)
{
    if(root == nullptr || s.find(root) != s.end()) return;
    int f[2] = {0, 1};
    if(s.find(root->left) == s.end())
        dfs(root->left, s);
    if(s.find(root->right) == s.end())
        dfs(root->right, s);

    if(root->left) {
        f[0] += max(s[root->left].first, s[root->left].second);
        f[1] += s[root->left].first;
    }
    if(root->right) {
        f[0] += max(s[root->right].first, s[root->right].second);
        f[1] += s[root->right].first;
    }
    s[root] = make_pair(f[0], f[1]);
}

int LIS(TreeNode *root)
{
    if(root == nullptr) return 0;
    unordered_map<TreeNode*, pair<int,int> > s;
    s[nullptr] = make_pair(0, 0);
    dfs(root, s);
    return max(s[root].first, s[root].second);
}

TreeNode* Destroy(TreeNode *root)
{
    if(root == nullptr) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}

int main(void)
{
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    root->right = new TreeNode(22);
    root->right->right = new TreeNode(25);
    cout << LIS(root) << endl;

    root = Destroy(root);
    return 0;
}
