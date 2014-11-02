// copyright @ L.J.SHOU Dec.15, 2013
// insert-sort for list
// type num: 1
#include "linked-list.h"
#include "cassert"
#include <iostream>
using namespace std;

ListNode *InsertNodeRecur(ListNode *list, ListNode *node)
{  //recursively
  if(list == NULL || node->val <= list->val){
    node->next = list;
    list = node;
	return list;
  }
  list->next = InsertNodeRecur(list->next, node);

  return list;
}

ListNode* InsertNode(ListNode *list, ListNode *node)
{ //None-recursive
  ListNode *cur(list), *pre(NULL);

  while(cur && cur->val < node->val)
  {
	pre = cur;
    cur = cur->next;
  }

  if(pre == NULL)
  {
    node->next = list;
	list = node;
  }
  else
  {
    node->next = cur;
	pre->next = node;
  }

  return list;
}

ListNode* InsertSortList(ListNode *list)
{
  ListNode *new_list(NULL);
  ListNode *cur(list), *pre(NULL);

  while(cur)
  {
    pre = cur; 
	cur = cur->next;
	new_list = InsertNode(new_list, pre);
  }

  return new_list;
}

int main(void)
{
  ListNode *list(NULL);

  list = InsertFront(list, 1);
  list = InsertFront(list, 3);
  list = InsertFront(list, 8);
  list = InsertFront(list, 2);
  list = InsertFront(list, 4);

  list = InsertSortList(list);

  PrintList(list);
  list = Destroy(list);

  return 0;
}
