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

/**
 *   Definition for binary tree
 *    struct TreeNode {
 *         int val;
 *          TreeNode *left;
 *           TreeNode *right;
 *           TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *         };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return depth(root) >= 0;
    }
private:
    int depth(TreeNode *root) {
        if(!root) return 0;
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        if(left_depth < 0 || right_depth < 0 || abs(left_depth - right_depth) > 1)
            return -1;
        return 1 + max(left_depth, right_depth);
    }
};
