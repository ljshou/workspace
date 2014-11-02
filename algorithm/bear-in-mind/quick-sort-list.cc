// copyright @ L.J.SHOU Dec.15, 2013
// quick-sort for lists
// type num: 1
#include "linked-list.h"
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

ListNode * QuickSortList(ListNode *list, ListNode *last)
{
  if(list == NULL || list == last) return list;
  assert(list && last);
  int x = last->val; //pivot
  ListNode *left(NULL), *left_end(NULL), *right(NULL), *right_end(NULL);

  while(list != last)
  {
    assert(list);
    if(list->val <= x)
	{
	  if(left_end == NULL)
	    left = left_end = list;
	  else{
	    left_end->next = list;
		left_end = list;
	  }
	}
	else
	{
	  if(right_end == NULL)
	    right = right_end = list;
   	  else{
	    right_end->next = list;
		right_end = list;
	  }
	}
	list = list->next;
  }//end while

  if(left_end != NULL)
  {
    left_end->next = NULL;
	left = QuickSortList(left, left_end);
  }
  if(right_end != NULL)
  {
    right_end->next = NULL;
	right = QuickSortList(right, right_end);
  }
  //note: left_end and right_end are obsolete!!!!

  //merge
  left_end = Last(left); //left_end should be updated
  if(left == NULL)
    left = left_end = last;
  else{
    left_end->next = last;
	left_end = last;
  }
  assert(left_end);
  left_end->next = right;
  
  return left;
}

ListNode* QuickSortList(ListNode *list)
{
  ListNode *last = Last(list);
  return QuickSortList(list, last);
}

int main(void)
{
  int x;
  ListNode *list(NULL);

  srand(time(0));
  for(int i=0; i<10; ++i)
  {
	x = rand() % 20;
    list = InsertFront(list, x);
  }
	 
  cout << "Original: ";
  PrintList(list);

  list = QuickSortList(list);
  PrintList(list);

  list = Destroy(list);
  return 0;
}
