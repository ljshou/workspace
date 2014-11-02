// copyright @ L.J.SHOU Feb.27, 2014
// test whether two lists are intersected
#include <iostream>
#include <cassert>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x)
    :val(x), next(NULL){}
};

ListNode* HasCircle(ListNode*);
bool IsIntersectedCircle(ListNode*, ListNode*);

// version 1
// test whether two lists are intersected
// assume each list has no circle
bool IsIntersectedNoCircle(ListNode *lhs, ListNode *rhs)
{
  if(lhs == NULL || rhs == NULL)
    return false;

  ListNode *tail1(lhs);
  for(; tail1->next; tail1 = tail1->next);

  ListNode *tail2(lhs);
  for(; tail2->next; tail2 = tail2->next);

  return tail1 == tail2;
}

// version 2
// assume lists may have a circle inside 
bool IsIntersectedCircle(ListNode *lhs, ListNode *rhs)
{
  ListNode *enter1(NULL), *enter2(NULL);

  enter1 = HasCircle(lhs);
  enter2 = HasCircle(rhs);

  // case 1: both lists have no circles
  if(enter1 == NULL && enter2 == NULL)
  {
    return IsIntersectedNoCircle(lhs, rhs);
  }
  // case 2: each have a circle
  else if(enter1 && enter2)
  { 
    ListNode *node(enter1->next); 

	while(node != enter1 && node != enter2){
	  node = node->next;
	}
	return node == enter2;
  }
  // case 3: one has a circle, while the other not
  else
  {
    return false;
  }
}


// test whether list has a circle
// if true, return the enter node
// if not,  return NULL
ListNode* HasCircle(ListNode *list)
{
  if(list == NULL || list->next == NULL) 
    return NULL;

  // fast/slow pointer method
  // if circled, slow pointer will catch up with fast one
  ListNode *fast(list), *slow(list);

  while(fast)
  {
    fast = fast->next;
	if(fast == NULL) return NULL;
	fast = fast->next;
	slow = slow->next;

	if(fast == slow)
	  break;
  }
  assert(fast == NULL || slow == fast); 

  if(fast == NULL) 
    return NULL;

  // list definitely has a circle
  // find the enter node
  // fast and enter will meet at the enter node
  ListNode *enter(list);

  while(enter != fast)
  {
    enter = enter->next;
	fast = fast->next;
  }

  return enter;
}

// destroy list
ListNode* Destroy(ListNode *list)
{
  ListNode *next(NULL);

  while(list)
  {
    next = list->next;
	delete list;
	list = next;
  }

  return NULL;
}

int main(void)
{
  ListNode *list(NULL);

  // testing case 1: both have no circles
  list = new ListNode(1);
  list->next = new ListNode(2);
  list->next->next = new ListNode(3);

  ListNode *list2 = list->next;
  cout << IsIntersectedCircle(list, list2) << endl;

  // testing case 2: both have circles
  list2 = new ListNode(1);
  list2->next = new ListNode(2);
  list2->next->next = list->next;

  list->next->next->next = list->next;
  cout << IsIntersectedCircle(list, list2) << endl;

  list->next->next->next = NULL;
  list2->next->next = NULL;

  // testing case 3: only one has a circle
  list->next->next->next = list->next;
  cout << IsIntersectedCircle(list, list2) << endl;
  list->next->next->next = NULL;


  list = Destroy(list);
  list2 = Destroy(list2);

  return 0;
}
