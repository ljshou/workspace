// copyright @ L.J.SHOU Dec.12, 2013
// list partition
#include "linked-list.h"
#include <iostream>
using namespace std;

ListNode* PartitionList(ListNode *list, int x)
{ // insert node(<x) into the front of new_list  
  ListNode *new_list(NULL), *new_list_end(NULL),
           *cur(list), *pre(NULL);
  while(cur)
  {
    if(cur->val < x)
	{
	  //insert into new_list
	  if(new_list_end == NULL)
	    new_list = new_list_end = cur;
	  else
	  {
	    new_list_end->next = cur;
		new_list_end = cur;
	  }

	  //delete from original list
	  if(pre == NULL)
	  {
	    list = cur->next;
		cur = list;
	  }
	  else
	  {
	    pre->next = cur->next;//cur is invalid
		cur = pre->next;
	  }
	}
	else
	{
	  pre = cur;
	  cur = cur->next;
	}
  }
  //merge into one list
  if(new_list_end == NULL)
    new_list = list;
  else
    new_list_end->next = list;
  
  return new_list;
}

int main(void)
{
  ListNode *list(NULL);

  for(int i=1; i<=10; ++i) 
    list = InsertFront(list, i);
  list = PartitionList(list, 7);
  PrintList(list);
  list = Destroy(list);
  return 0;
}
