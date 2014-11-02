/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBST(head, Length(head));
    }
private:
    int Length(ListNode *head) {
        int len(0);
        for(; head; head = head->next, ++len);
        return len;
    }
    ListNode *nthNode(ListNode *head, int n) {
        while(head && (n--)) head = head->next;
        return head;
    }
    TreeNode *sortedListToBST(ListNode *head, int n) {
        if(n == 0) return nullptr;
        if(n == 1) return new TreeNode(head->val);
        ListNode *node = nthNode(head, n/2);
        TreeNode *root = new TreeNode(node->val);
        root->left = sortedListToBST(head, n/2);
        root->right = sortedListToBST(node->next, n - n/2 - 1);
        return root;
    }
};
