// copyright @ L.J.SHOU Dec.14, 2013
// merge sort for list
// type num: 1
#include "linked-list.h"
#include <iostream>
#include <cassert>
using namespace std;

ListNode* MergeListRecur(ListNode *lhs, ListNode *rhs)
{//pre: lhs and rhs already in order
  ListNode *list(NULL);

  if(lhs == NULL || rhs == NULL)//exit
  {
    return lhs!=NULL?lhs:rhs;
  }

  assert(lhs && rhs);
  if(lhs->val < rhs->val)
  {
	list = lhs;
    list->next = MergeListRecur(lhs->next, rhs);
  }
  else
  {
	list = rhs;
    list->next = MergeListRecur(lhs, rhs->next);
  }
  return list;
}

ListNode* MergeList(ListNode *lhs, ListNode *rhs)
{
  ListNode *list(NULL), *rear(NULL);
  
  while(lhs && rhs)
  {
    if(lhs->val < rhs->val)
	{
	  if(rear == NULL)
	    list = rear = lhs;
	  else{
	    rear->next = lhs;
		rear = lhs;
	  }
	  lhs = lhs->next;
	}
	else
	{
	  if(rear == NULL)
	    list = rear = rhs;
	  else{
	    rear->next = rhs;
		rear = rhs;
	  }
	  rhs = rhs->next;
	}
  }//end while

  if(lhs)
  {
    if(rear == NULL)
	  list = lhs;
	else
	  rear->next = lhs;
  }

  if(rhs)
  {
    if(rear == NULL)
	  list = rhs;
	else
	  rear->next = rhs;
  }

  return list;
}


ListNode* MergeSortList(ListNode *list)
{
  if(list == NULL || list->next == NULL)
    return list;
  ListNode *fast(list), *slow(list), *rhs(NULL);

  //divide list into two equal ones
  fast = fast->next;
  while(fast && fast->next)
  {
    fast = fast->next->next;
	slow = slow->next;
  }
  rhs = slow->next;
  slow->next = NULL;
  
  //merge
  list = MergeSortList(list);
  rhs =  MergeSortList(rhs);
  list = MergeList(list, rhs);
  return list;
}

int main(void)
{
  ListNode *list(NULL);

  list = InsertRear(list, 3);
  list = InsertRear(list, 2);
  list = InsertRear(list, 6);
  list = InsertRear(list, 5);
  list = InsertRear(list, 4);

  list = MergeSortList(list);
  PrintList(list);
  list = Destroy(list);

  return 0;
}
