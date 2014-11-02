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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        assert(preorder.size() == inorder.size());
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
private:
    typedef vector<int>::iterator Iterator;
    TreeNode *buildTree(Iterator preBegin, Iterator preEnd, Iterator inBegin, Iterator inEnd) {
        if(preBegin == preEnd) return nullptr;
        TreeNode *root = new TreeNode(*preBegin);
        auto pos = find(inBegin, inEnd, root->val);
        int leftCnt = pos - inBegin;
        int rightCnt = inEnd - pos - 1;
        
        root->left = buildTree(next(preBegin), next(preBegin)+leftCnt, inBegin, pos);
        root->right = buildTree(preEnd-rightCnt, preEnd, pos+1, inEnd);
        return root;
    }
};
