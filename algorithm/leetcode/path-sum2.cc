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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        vector<vector<int> > res;
        dfs(root, sum, path, res);
        return res;
    }
private:
    void dfs(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &res) {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) {
            //leaf node
            if(root->val == sum) { 
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        dfs(root->left, sum-root->val, path, res);
        dfs(root->right, sum-root->val, path, res);
        path.pop_back();
    }
};
