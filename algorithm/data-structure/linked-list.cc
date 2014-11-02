// copyright @ L.J.SHOU Dec.10, 2013
// type num: 3
#include "linked-list.h"
#include <iostream>
using namespace std;

/*
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x=0, ListNode* p=NULL)
    : val(x), next(p){}
};
*/

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

ListNode* Insert(ListNode *list, int x)
{ //keep list in order after inserting x
  ListNode *cur(list), *pre(NULL), *node(NULL);

  //找到插入位置
  while(cur && cur->val < x){
    pre = cur;
	cur = cur->next;
  }

  if((node = new ListNode(x))==NULL){
    cerr << "Out of space!!!" << endl;
	return list;
  }

  node->next = cur;
  //插入在首部
  if(pre == NULL)
    list = node;
  else
    pre->next = node;

  return list;
}

ListNode* InsertFront(ListNode *list, int x)
{//insert into list front O(1)
  ListNode *node = new ListNode(x, list);

  return node;
}

ListNode* InsertRear(ListNode *list, int x)
{ 
  ListNode *rear(list), *node(NULL);

  while(rear && rear->next)
    rear = rear->next;

  node = new ListNode(x, NULL);

  // insert as the first node
  if(rear == NULL)
    list = node;
  else
    rear->next = node;

  return list;
}

ListNode* Find(ListNode *list, int x)
{
  while(list && list->val != x)
  {
    list = list->next;
  }

  return list;
}

// return pointer to last node
// return NULL if list is empty
ListNode* Last(ListNode *list)
{//return pointer to the last node
  while(list && list->next)
    list = list->next;

  return list;
}

ListNode* Delete(ListNode *list, int x)
{
  if(list == NULL) return NULL;
  ListNode *cur(list), *pre(NULL);
  //locate at the previous node
  while(cur && cur->val != x)
  {
    pre = cur;
	cur = cur->next;
  }
  //x not found
  if(cur == NULL)
	return list;

  //delete node containing x
  if(pre == NULL)
    list = cur->next;
  else
    pre->next = cur->next;
  delete cur;

  return list;
}

ListNode* Destroy(ListNode *list)
{
  ListNode *node(NULL), *cur(list); 

  while(cur)
  {
    node = cur;
	cur = cur->next;
	delete node;
  }
  return NULL;
}

int Length(ListNode const *list)
{
  if(list == NULL) return 0;
  else return 1+Length(list->next);
}

void PrintList(ListNode const *list)
{
  for(; list!=NULL; list=list->next)
    cout << list->val << " ";
  cout << endl;
}

ListNode* Reverse(ListNode *list)
{
  if(list == NULL || list->next == NULL) return list;
  ListNode *reverse_list(NULL), *next(NULL);

  while(list)
  {
    next = list->next;
    list->next = reverse_list;
	reverse_list = list;
	list = next;
  }
  return reverse_list;
}

#if 0
int main(void)
{
  ListNode *list(NULL);
  for(size_t i=0; i<10; ++i)
    list = Insert(list, i);
  list = Reverse(list);
  PrintList(list);
  cout << "Last node: " << Last(list)->val << endl;
  cout << Find(list, 8)->val << endl;
  cout << "length: " << Length(list) << endl;
  list = Destroy(list);
  return 0;
}
#endif
