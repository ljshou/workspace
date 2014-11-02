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
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
private:
    vector<TreeNode*> generateTrees(int left, int right) {
        if(left > right) return vector<TreeNode*>{nullptr};
        vector<TreeNode *> res;
        for(int i=left; i<=right; ++i) {
            auto leftTrees = generateTrees(left, i-1);
            auto rightTrees = generateTrees(i+1, right);
            for(auto left_child : leftTrees) {
                for(auto right_child : rightTrees) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left_child;
                    root->right = right_child;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
