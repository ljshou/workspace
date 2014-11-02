// copyright @ L.J.SHOU Dec.12, 2013
// find the kth node from the rear of a linked list
#include <iostream>
#include <memory>
using namespace std;
struct ListNode;
typedef struct ListNode ListNode;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x=0, ListNode *p=NULL)
    : val(x), next(p){};
};

ListNode* Insert(ListNode *list, int x)
{
  ListNode *cur(list), *pre(NULL), *node(NULL);
  //locate before the node
  while(cur && cur->val < x)
  { 
    pre = cur;
	cur = cur->next;
  }
  node = new ListNode(x, cur);
  if(pre == NULL)
    list = node;
  else
    pre->next = node;
  return list;
}

ListNode* Destroy(ListNode *list)
{
  ListNode *node(NULL);
  while(list)
  {
    node = list;
	list = list->next;
	delete node;
  }
  return NULL;
}

void PrintList(ListNode const *list)
{
  while(list)
  {
    cout << list->val << " ";
	list = list->next;
  }
  cout << endl;
}

int NToLast1(ListNode const *list, int k)
{//find the kth number from the rear
  if(list == NULL) return 0;
  int i = 1+NToLast1(list->next, k);
  if(i == k)
    cout << list->val << endl;
  return i;
}

int NToLast2(ListNode *list, ListNode* & p, int k)
{
  if(list == NULL) return 0;
  int i = 1+NToLast2(list->next, p, k);
  if(i == k)
    p = list;
  return i;
}

ListNode* NToLast3(ListNode *list, int &i, int k)
{
  if(list == NULL) return NULL;
  ListNode *p = NToLast3(list->next, i, k);
  i = i + 1;
  if(i == k)
    return list;
  else
    return p;
}

ListNode * NToLast4(ListNode *list, int k)
{
  ListNode *p1(list), *p2(list);
  for(int i=0; i<k; ++i)
  {
    if(p2 == NULL) return NULL;
	p2 = p2->next;
  }
  while(p2)
  {
    p2 = p2->next;
	p1 = p1->next;
  }
  return p1;
}

class IntWrapper
{
  public:
    static int i;
};
int IntWrapper::i = 0;

ListNode* NToLast5(ListNode *list, int k, IntWrapper carry)
{
  if(list == NULL) return NULL;
  ListNode *p = NToLast5(list->next, k, carry);
  carry.i ++;
  if(carry.i == k)
    return list;
  else
    return p;
}

int main(void)
{
  ListNode *list(NULL), *p(NULL);
  IntWrapper carry;
  carry.i = 0;

  for(int k=0; k<10; ++k)
    list = Insert(list, k);
  PrintList(list);
  for(int k=1; k<=10; ++k)
  {
	carry.i = 0;
    p = NToLast5(list, k, carry);
	if(p != NULL)
	  cout << p->val << endl;
  }
  list = Destroy(list);
  return 0;
}
