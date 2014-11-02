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
    typedef vector<int>::iterator Iterator;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        assert(inorder.size() == postorder.size());
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
private:
    TreeNode *buildTree(Iterator in_left, Iterator in_right, Iterator post_left, Iterator post_right) {
        if(in_left == in_right) return nullptr;
        auto mid = std::find(in_left, in_right, *(post_right-1));
        TreeNode *root = new TreeNode(*(post_right-1));
        root->left = buildTree(in_left, mid, post_left, post_left + (mid-in_left));
        root->right = buildTree(mid+1, in_right, post_left+(mid-in_left), post_right-1);
        return root;
    }
};
