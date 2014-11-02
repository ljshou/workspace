/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        RandomListNode *cur(head), *node(nullptr);
        while(cur) {
            node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = cur->next->next;
        }
        //set the random pointer
        cur = head;
        while(cur) {
            if(cur->random) cur->next->random = cur->random->next; //别忘了判断非空
            cur = cur->next->next;
        }
        //separate lists
        RandomListNode dummy(-1), *rear(&dummy);
        cur = head;
        while(cur) {
            node = cur->next;
            cur->next = cur->next->next;
            rear->next = node;
            rear = rear->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};
