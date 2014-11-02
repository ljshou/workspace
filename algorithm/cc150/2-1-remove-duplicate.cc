// copyright @ L.J.SHOU Dec.08, 2013
// remove duplicates in unsorted list
// Problem 2.1 from Cracking the coding interview
#include <cassert>
#include <iostream>
#include <set>
using namespace std;

struct ListNode 
{
  int val;
  struct ListNode* next;
  ListNode(int x): val(x), next(NULL){};
};
typedef struct ListNode ListNode;

ListNode *deleteDuplicates(ListNode *head) 
{
  if(head == NULL || head->next == NULL) return head;
  ListNode *cur(head), *pre(NULL);
  int x(cur->val), flag(0);
        
  pre = cur;
  cur = cur->next;
  while(cur)
  {
    if(cur->val == x)
	{
      pre->next = cur->next;
      delete cur;
      cur = pre->next;
      flag = 1;
   } 
   else
   {
      pre = cur;
      cur = cur->next;
   }
  }//end while
  assert(head);
  if(flag){//delete head
    pre = head;
    head = head->next;
    delete pre;
	if(head)
	  head = deleteDuplicates(head);
  }
  else
  {
    if(head->next)
	  head->next = deleteDuplicates(head->next);
  }
  
  return head;
}

ListNode* RemoveDuplicate(ListNode *list)
{
  set<int> check;
  ListNode *current(list), *p(NULL);
  check.insert(list->val);

  //while(current->next) //Error
  while(current && current->next)
  {
    if(check.count(current->next->val))
	{ //already in the list
	  p = current->next;
	  current->next = current->next->next;
	  delete p;
	}
	else
	{
	  check.insert(current->next->val);
	  current = current->next;//increment
	}
  }

  return list;
}

ListNode* RemoveDuplicate2(ListNode *list)
{ //not allowed to use extra space
  ListNode *previous(NULL), *current(NULL), *p(NULL);
  int x;
  current = list;
  while(current)
  {
    x = current->val;
	p = list;
	while(p != current)
	{
	  if(p->val == x)
	    break;
	  p = p->next;
	}
	if(p != current)
	{//duplicated
	  previous->next = current->next;
	  delete current;//current is invalid
	  current = previous;//must
	}
	previous = current;
	current = current->next;
  }
  return list;
}

void PrintList(ListNode *list)
{
  while(list)
  {
    cout << list->val << " ";
	list = list->next;
  }
  cout << endl;
}

ListNode* Insert(ListNode *list, int x)
{ //insert node into the front of a list
  ListNode *node = new ListNode(x); 

  node->next = list;
  list = node;
  return list;
}

ListNode* DestroyList(ListNode *list)
{
  ListNode *previous(NULL);
  while(list)
  {
    previous = list;
	list = list->next;
	delete previous;
  }
  return NULL;
}

int main(void)
{
  ListNode *list(NULL);

  list = Insert(list, 2);
  list = Insert(list, 2);
  list = Insert(list, 2);
  PrintList(list);

  list = deleteDuplicates(list);
  PrintList(list);
  list = DestroyList(list);
  return 0;
}
