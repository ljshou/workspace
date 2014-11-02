/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *list(nullptr), *next(nullptr);
        while(head) {
            next = head->next;
            list = Insert(list, head);
            head = next;
        }
        return list;
    }
private:
    ListNode* Insert(ListNode *list, ListNode *node) {
        assert(node != nullptr);
        ListNode *prev(nullptr), *cur(list);
        while(cur && cur->val < node->val) {
            prev = cur;
            cur = cur->next;
        }
        if(prev) {
            node->next = prev->next;
            prev->next = node;
        }
        else { //insert at front
            node->next = list;
            list = node;
        }
        return list;
    }
}; 
