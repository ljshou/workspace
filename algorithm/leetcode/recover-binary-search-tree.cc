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
    void recoverTree(TreeNode *root) {
        //using morris inorder traversal
        TreeNode *pre(nullptr);
        pair<TreeNode*, TreeNode*> nodes{nullptr, nullptr};
        while(root) {
            if(root->left == nullptr) {
                //visit root
                if(pre && pre->val >= root->val) {
                    if(nodes.first == nullptr) nodes.first = pre;
                    nodes.second = root;
                }
                pre = root;
                
                root = root->right;
                continue;
            }
            //find the lastest node in left sub-tree
            TreeNode *largest(root->left);
            for(; largest->right && largest->right != root; largest = largest->right);
            if(largest->right == nullptr) {
                largest->right = root;
                root = root->left;
            }
            else {
                largest->right = nullptr;
                //visit root
                if(pre && pre->val >= root->val) {
                    if(nodes.first == nullptr) nodes.first = pre;
                    nodes.second = root;
                }
                pre = root;
                root = root->right;
            }
        }
        if(nodes.first && nodes.second)
            swap(nodes.first->val, nodes.second->val);
    }
};
