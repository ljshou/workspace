// copyright @ L.J.SHOU Jan.15, 2014
// double-linked-list with a head node
#include "double-linked-list.h"
#include <iostream>
using namespace std;

struct ListNode{
  ListNode *pre;
  ListNode *next;
  int val;
  ListNode(int x=0)
   : val(x), pre(NULL), next(NULL){}
};

// return pointer to a head node
// list->val------length of list
// list->pre------the last node of list
// list->next---- the first node of list
ListNode* NewList()
{
  return new ListNode(0);
}

int Length(ListNode *list)
{
  return list->val;
}

ListNode* Destroy(ListNode *list)
{
  ListNode *next(NULL);
  
  while(list){
    next = list->next;
	delete list;
	list = next;
  }

  return NULL;
}

// actually, no need to return head node's pointer
// since heading node never change
ListNode* Insert(ListNode *list, int x)
{
  ListNode *pre(list), *cur(list->next);
  ListNode *node(NULL);

  while(cur && cur->val < x)
  {
    pre = cur;
	cur = cur->next;
  }
  if(cur && cur->val == x) return list;

  node = new ListNode(x);
  node->next = cur;
  pre->next = node;

  // insert at first
  if(pre != list)
    node->pre = pre;
  else
    node->pre = NULL;
  //insert at rear
  if(cur != NULL)
    cur->pre = node;
  else
	list->pre = node;

  list->val ++; // length++

  return list;
}

ListNode* Delete(ListNode *list, int x)
{
  ListNode *pre(list), *cur(list->next);

  while(cur && cur->val != x)
  {
    pre = cur;
	cur = cur->next;
  }
  
  if(cur && cur->val == x) 
  {
    pre->next = cur->next;

	//最后一个节点删除单独处理(相当与首节点删除)
	if(cur->next != NULL)
	  cur->next->pre = cur->pre; //cur->pre 而不是 pre
	else
	  list->pre = cur->pre; 

	delete cur;
	--list->val;
  }
  return list;
}

void PrintList(ListNode *list)
{
  cout << "Length of list: " << list->val << endl;
  list = list->next;
  while(list){
    cout << list->val << " ";
	list = list->next;
  }
  cout << endl;
}

void ReversePrintList(ListNode *list)
{
  list = list->pre;
  while(list){
    cout << list->val << " ";
	list = list->pre;
  }
  cout << endl;
}

int main(void)
{
  ListNode *list = NewList();

  for(int i=10; i>0; --i)
    list = Insert(list, i);
  list = Delete(list, 1);
  list = Delete(list, 5);
  list = Delete(list, 10);
  PrintList(list);
  ReversePrintList(list);

  list = Destroy(list);

  return 0;
}
