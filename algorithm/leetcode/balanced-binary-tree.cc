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
    bool isBalanced(TreeNode *root) {
        int depth(0);
        return isBalanced(root, depth);
    }
private:
    bool isBalanced(TreeNode *root, int &depth) {
        if(root == nullptr) {
            depth = 0;
            return true;
        }
        if(root->left == nullptr && root->right == nullptr) {
            depth = 1;
            return true;
        }
        int leftDepth(0), rightDepth(0);
        bool flag = isBalanced(root->left, leftDepth) && isBalanced(root->right, rightDepth);
        depth = 1 + max(leftDepth, rightDepth);
        return flag && (abs(rightDepth - leftDepth) < 2);
    }
};
