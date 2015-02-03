/**
 * @file order-statistic-tree.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-02
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    TreeNode *left, *right;
    int val;
    int left_size; //# of nodes in left sub-tree
    TreeNode(int x=0):
        val(x), left(nullptr), right(nullptr), left_size(0) {}
};

TreeNode *Insert(TreeNode *root, int x)
{
    if(!root) return new TreeNode(x);
    if(x <= root->val) {
        root->left = Insert(root->left, x);
        ++ root->left_size;
    }
    else {
        root->right = Insert(root->right, x);
    }
    return root;
}

int GetRank(TreeNode *root, int x)
{
    if(!root) return -1;
    if(x == root->val) {
        return root->left_size;
    }
    else if(x < root->val) {
        return GetRank(root->left, x);
    }
    else {
        int right_rank = GetRank(root->right, x);
        return right_rank == -1 ? -1 : 1+root->left_size+right_rank;
    }
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
    int a[] = {3,1,5,2,6,8,2,10};
    const int n = sizeof(a)/sizeof(int);
    TreeNode *root = nullptr;
    for(int i=0; i<n; ++i)
        root = Insert(root, a[i]); 

    sort(a, a+n);
    for(int i=n-1; i>=0; --i)
        cout << GetRank(root, a[i]) << endl;
    root = Destroy(root);
}

int main(void)
{
    Test();
    return 0;
}
