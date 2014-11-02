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
    int sumNumbers(TreeNode *root) {
        int res(0);
        dfs(root, 0, res);
        return res;
    }
private:
    void dfs(TreeNode *root, int sum, int &res) {
        if(root == nullptr) {
            res += sum;
            return;
        }
        sum = sum*10 + root->val;
        if(root->left == nullptr && root->right == nullptr) {
            res += sum;
            return;
        }
        if(root->left) dfs(root->left, sum, res);
        if(root->right) dfs(root->right, sum, res);
    }
};
