/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr) return;
        //using list
        TreeLinkNode dummy(-1);
        TreeLinkNode *pre = &dummy;
        for(; root; root = root->next) {
            if(root->left) {
                pre->next = root->left;
                pre = pre->next;
            }
            if(root->right) {
                pre->next = root->right;
                pre = pre->next;
            }
        }
        connect(dummy.next);
    }
};
