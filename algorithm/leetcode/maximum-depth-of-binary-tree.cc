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
    int maxDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

//非递归
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        int level(0);
        queue<TreeNode*> cur, next;
        cur.push(root);
        
        while(!cur.empty()) {
            root = cur.front(); cur.pop();
            if(root->left) next.push(root->left);
            if(root->right) next.push(root->right);
            if(cur.empty()) {
                ++ level;
                cur.swap(next);
            }
        }
        return level;
    }
};
