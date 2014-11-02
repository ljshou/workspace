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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        while(root) {
            if(root->left == nullptr) {
                //visit root
                res.push_back(root->val);
                root = root->right;
                continue;
            }
            //find the precessor of root
            TreeNode *prev = root->left;
            for(; prev->right && prev->right != root; prev = prev->right);
            if(prev->right == nullptr) {
                prev->right = root;
                root = root->left;
            }
            else {
                prev->right = nullptr;
                //visit root
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
