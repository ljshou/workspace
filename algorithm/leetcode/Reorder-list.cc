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
    void reorderList(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return;
        ListNode *fast(head->next), *slow(head);
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *rhs = slow->next;
        slow->next = nullptr;
        rhs = reverse(rhs);
        
        //merge head and lhs
        ListNode *next(nullptr);
        while(rhs) {
            next = rhs->next;
            rhs->next = head->next;
            head->next = rhs;
            head = head->next->next;
            rhs = next;
        }
    }
private:
    ListNode *reverse(ListNode *list) {
        ListNode *new_list(nullptr), *next(nullptr);
        while(list) {
            next = list->next;
            list->next = new_list;
            new_list = list;
            list = next;
        }
        return new_list;
    }
};
