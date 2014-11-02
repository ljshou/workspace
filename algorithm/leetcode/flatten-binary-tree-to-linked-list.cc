/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left) {
            TreeNode *rear = root->left;
            for(; rear->right; rear = rear->right);
            rear->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};
