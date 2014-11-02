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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num.begin(), num.end());
    }
private:
    TreeNode *sortedArrayToBST(Iterator left, Iterator right) {
        if(left >= right) return nullptr;
        auto mid = left + (right - left)/2;
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(left, mid);
        root->right = sortedArrayToBST(mid+1, right);
        return root;
    }
};
