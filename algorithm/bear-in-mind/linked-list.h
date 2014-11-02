// copyright @ L.J.SHOU Dec.10, 2013
// linked list without a head node
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
struct ListNode;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x=0, ListNode* p=NULL)
    : val(x), next(p){}
};

ListNode* Insert(ListNode *list, int x);
ListNode* InsertFront(ListNode *list, int x);
ListNode* InsertRear(ListNode *list, int x);

ListNode* Reverse(ListNode *list);

ListNode* Find(ListNode *list, int x);
ListNode* Last(ListNode *list);

ListNode* Delete(ListNode *list, int x);
ListNode* Destroy(ListNode *list);

void PrintList(ListNode const *list);
int Length(ListNode const *list);

#endif
