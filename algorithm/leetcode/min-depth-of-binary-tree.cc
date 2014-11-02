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
    int minDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        //leaf node
        if(root->left == nullptr && root->right == nullptr) return 1;
        if(root->left && root->right) return 1 + min(minDepth(root->left), minDepth(root->right));
        if(root->left) return 1 + minDepth(root->left);
        else return 1 + minDepth(root->right);
    }
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> cur, next;
        int level(0);
        
        cur.push(root);
        while(!cur.empty()) {
            root = cur.front(); cur.pop();
            if(root->left == nullptr && root->right == nullptr) {
                return level+1;
            }
            if(root->left) next.push(root->left);
            if(root->right) next.push(root->right);
            if(cur.empty()) {
                ++level;
                cur.swap(next);
            }
        }
        return level;
    }
};
