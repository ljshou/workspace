/**
 * @file build-max-heap.cc
 * @brief build max heap based on mid traversal sequences
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-04
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x=0):
        val(x), left(nullptr), right(nullptr) {}
};

TreeNode * buildMaxHeap(const vector<int> &vec)
{
    TreeNode *root(nullptr), *node(nullptr);
    stack<TreeNode *> s;
    for(int i=0; i<vec.size(); ++i) {
        node = new TreeNode(vec[i]);
        while(!s.empty()) {
            TreeNode *ptr = s.top();
            if(ptr->val > node->val) {
                node->left = ptr->right;
                ptr->right = node;
                s.push(node);
                break;
            }
            s.pop();
        }
        if(s.empty()) {
            node->left = root;
            root = node;
            s.push(node);
        }
    }
    return root;
}

void MidTraversal(TreeNode *root)
{
    if(root == nullptr) return;
    MidTraversal(root->left);
    cout << root->val << " ";
    MidTraversal(root->right);
}

TreeNode* Destroy(TreeNode* root) 
{
    if(root == nullptr) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}

int main(void)
{
    vector<int> vec{1,4,2,0,3};
    TreeNode * root = buildMaxHeap(vec);
    MidTraversal(root);
    cout << endl;
    root = Destroy(root);
    return 0;
}
