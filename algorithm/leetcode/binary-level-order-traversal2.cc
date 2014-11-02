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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        vector<int> path;
        queue<TreeNode*> cur, next;
        if(root == nullptr) return res;
        
        cur.push(root);
        while(!cur.empty()) {
            root = cur.front(); cur.pop();
            //visit root
            path.push_back(root->val);
            if(root->left) next.push(root->left);
            if(root->right) next.push(root->right);
            
            if(cur.empty()) {
                if(!path.empty()) res.push_back(path);
                path.clear();
                cur.swap(next);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
