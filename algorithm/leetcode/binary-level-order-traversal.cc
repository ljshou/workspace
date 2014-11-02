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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        vector<int> vals;
        if(root == nullptr) return res;
        queue<TreeNode*> cur, next;
        cur.push(root);
        
        while(!cur.empty()) {
            root = cur.front(); cur.pop();
            vals.push_back(root->val);
            if(root->left) {
                next.push(root->left);
            }
            if(root->right) {
                next.push(root->right);
            }
            if(cur.empty()) {
                if(!vals.empty()) {
                    res.push_back(vals);
                    vals.clear();
                }
                cur.swap(next);
            }
        }
   
        return res;
    }
};
