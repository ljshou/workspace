/**
 * @file largest-independent-set.cc
 * @brief LIS问题分析原题这个LIS问题，
 * 可不是Longest Increasing Subsequence，而是Largest Independent Set，
 * 含义如下：给定一棵二叉树，找到满足如下条件的最大节点集合：
 * 集合中的任意两个节点之间，都没有边
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-21
 */

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x=0):
        val(x), left(nullptr), right(nullptr) {}
};

int LargestIndependetSet(TreeNode *root)
{
    if(root == nullptr) return 0;
    unordered_map<TreeNode*, int> hash[2];
    hash[0][nullptr] = 0;
    hash[1][nullptr] = 0;

    //post traversal
    TreeNode *cur = root, *pre = nullptr;
    stack<TreeNode *> s;
    while(cur || !s.empty()) {
        while(cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top(); s.pop();
        if(cur->right == nullptr || cur->right == pre) {
            //cout << cur->val << " ";
            //visit cur
            hash[0][cur] = max(hash[0][cur->left], hash[1][cur->left]) + 
                            max(hash[0][cur->right],hash[1][cur->right]);
            hash[1][cur] = 1 + hash[0][cur->left] + hash[0][cur->right];
            pre = cur;
            cur = nullptr; //do not forget
        }
        else {
            s.push(cur); //do not forget
            cur = cur->right;
        }
    }
    return max(hash[0][root], hash[1][root]);
}

TreeNode* Destroy(TreeNode *root)
{
    if(root == nullptr) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}

void Test()
{
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    root->right = new TreeNode(22);
    root->right->right = new TreeNode(25);

    cout << LargestIndependetSet(root) << endl;

    root = Destroy(root);
}

int main(void)
{
    Test();
    return 0;
}
