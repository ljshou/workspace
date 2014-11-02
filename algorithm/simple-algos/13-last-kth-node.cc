// copyright @ L.J.SHOU Mar.05, 2014
// find the last kth node in a list
#include <iostream>
#include <cassert>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x):val(x), next(NULL){}
};

ListNode* LastKthNode(ListNode *list, int k)
{
  assert(k >= 0);
  if(k == 0 || list == NULL)
    return NULL;

  ListNode *p(list);
  for(; k>0 && p; --k)
	p = p->next;

  if(k > 0) // list length less than k
    return NULL;

  while(p)
  {
    p = p->next;
	list = list->next;
  }
  
  return list;
}

int main(void)
{
  ListNode *list(NULL), *node(NULL);

  list = new ListNode(1);
  list->next = new ListNode(2);
  list->next->next = new ListNode(3);

  node = LastKthNode(list, 30);
  node = lastK(list, 3);
  if(node != NULL)
    cout << "node is : " << node->val << endl;

  while(list){
    node = list->next;
	delete list;
	list = node;
  }

  return 0;
}
