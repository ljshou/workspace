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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> s;
        while(root || !s.empty()) {
            while(root) {
                s.push(root);
                res.push_back(root->val);
                root = root->left;
            }
            root = s.top(); s.pop();
            root = root->right;
        }
        return res;
    }
};
