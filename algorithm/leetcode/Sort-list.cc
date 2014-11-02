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
    //use merge sort
    ListNode *sortList(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return head;
        //divide
        ListNode *lhs(head), *rhs(nullptr);
        ListNode *fast(head->next), *slow(head);
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        rhs = slow->next;
        slow->next = nullptr;
        
        lhs = sortList(lhs);
        rhs = sortList(rhs);
        //merge
        return mergeList(lhs, rhs);
    }
private:
    ListNode *mergeList(ListNode *lhs, ListNode *rhs) {
        ListNode dummy(-1), *rear(&dummy);
        while(lhs && rhs) {
            if(lhs->val < rhs->val) {
                rear->next = lhs;
                lhs = lhs->next;
            }
            else {
                rear->next = rhs;
                rhs = rhs->next;
            }
            rear = rear->next;
        }
        if(lhs) {
            rear->next = lhs;
        }
        if(rhs) {
            rear->next = rhs;
        }
        return dummy.next;
    }
};
