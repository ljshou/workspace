// copyright @ L.J.SHOU Jan.15, 2014
// double-linked-list
#ifndef DOUBLE_LIST_H_
#define DOUBLE_LIST_H_
struct ListNode;

ListNode* NewList();
ListNode* Destroy(ListNode *list);
ListNode* Insert(ListNode *list, int x);
ListNode* Delete(ListNode *list, int x);

int Length(ListNode *list);
void PrintList(ListNode *list);
void ReversePrintList(ListNode *list);

#endif
