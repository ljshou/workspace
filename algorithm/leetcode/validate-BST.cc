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
    bool isValidBST(TreeNode *root) {
        if(root == nullptr) return true;
        if(isValidBST(root->left) && isValidBST(root->right)) {
            //find the max of left sub-tree
            TreeNode *max(root->left);
            for(; max && max->right; max=max->right);
            if(max && max->val >= root->val) return false;
            //find the min of right sub-tree
            TreeNode *min(root->right);
            for(; min && min->left; min=min->left);
            if(min && min->val <= root->val) return false;
            return true;
        }
        else  return false;
    }
};
