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
    int maxPathSum(TreeNode *root) {
        int res(INT_MIN);
        helper(root, res);
        return res;
    }
private:
    int helper(TreeNode *root, int &res) {
        if(root == nullptr) return 0;
        int sum = root->val;
        
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        
        if(left > 0) sum += left;
        if(right > 0) sum += right;
        res = max(res, sum);
        
        return root->val + (max(left, right)>0 ? max(left, right) : 0); 
    }
};
