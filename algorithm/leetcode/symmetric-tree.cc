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
    bool isSymmetric(TreeNode *root) {
        if(root == nullptr) return true;
        return helper(root->left, root->right);
    }
private:
    bool helper(TreeNode *lhs, TreeNode *rhs) {
        if(lhs == nullptr && rhs == nullptr) return true;
        if(lhs && rhs) return lhs->val == rhs->val && (helper(lhs->left, rhs->right)) 
        && (helper(lhs->right, rhs->left));
        return false;
    }
};
