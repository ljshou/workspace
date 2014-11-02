// copyright @ L.J.SHOU Dec.12, 2013
// compute the sum of two lists
// integer are stored int list reversely
#include "linked-list.h"
#include <iostream>
#include <cassert>
using namespace std;

ListNode* SumOfList(ListNode *lhs, ListNode *rhs)
{
  ListNode *sum_list(NULL), *end(NULL), *node(NULL);
  int n(0), flag(0);

  while(lhs && rhs)
  {
    n = lhs->val + rhs->val + flag;
	flag = n/10;//carry
	n %= 10;

    node = new ListNode(n); 
	if(end == NULL)
	  sum_list = end = node;
	else
	{
	  end->next = node;
	  end = node;
	}

	lhs = lhs->next;
	rhs = rhs->next;
  }
  while(lhs)
  {
	n = lhs->val + flag;
	flag = n/10;
	n %= 10;
	node = new ListNode(n);

	if(end == NULL)
	  sum_list = end = node;
	else
	{
	  end->next = node;
	  end = node;
	}

	lhs = lhs->next;
  }
  while(rhs)
  {
	n = rhs->val + flag;
	flag = n/10;
	n %= 10;
	node = new ListNode(n);

	if(end == NULL)
	  sum_list = end = node;
	else
	{
	  end->next = node;
	  end = node;
	}

	rhs = rhs->next;
  }
  if(flag)
  {
    node = new ListNode(flag);
	if(end == NULL)
	  sum_list = end = node;
	else
	{
	  end->next = node;
	  end = node;
	}
  }
  return sum_list;
}

ListNode* SumOfListRecur(ListNode *lhs, ListNode *rhs, int flag)
{
  int n(0);
  ListNode *sum(NULL), *end(NULL), *node(NULL);

  if(lhs == NULL && rhs == NULL && flag == 0)//exit
    return NULL;

  assert(lhs != NULL || rhs != NULL || flag != 0);
  n = flag;
  if(lhs) n += lhs->val;
  if(rhs) n += rhs->val;
  flag = n/10;
  n %= 10;

  node = new ListNode(n);
  sum = SumOfListRecur(lhs?lhs->next:NULL, rhs?rhs->next:NULL, flag);
  assert(node != NULL);
  node->next = sum;
  return node;
}

// what if the integer stored forwardly in lists
class PartialSum
{
  public:
    PartialSum(int x=0, ListNode *p=NULL)
      : carry(0), sum(p){};
    int carry;
	ListNode *sum;
};

ListNode* AddPadding(ListNode *list, int len)
{ //adding len 0s into the front
  for(int i=0; i<len; ++i)
    list = InsertFront(list, 0);
  return list;
}

PartialSum AddPartialSum(ListNode *lhs, ListNode *rhs)
{
  assert(Length(lhs) == Length(rhs));
  ListNode *node(NULL);
  PartialSum sum;
  int n(0);

  //exit
  if(lhs == NULL && rhs == NULL) return sum;
  sum = AddPartialSum(lhs->next, rhs->next);
  n = sum.carry + lhs->val + rhs->val; 
  sum.carry = n/10;
  n %= 10;

  node = new ListNode(n, sum.sum);
  sum.sum = node;

  return sum;
}

ListNode* SumOfListForward(ListNode *lhs, ListNode* rhs)
{//integer is stored forward in the list
  int len1(0), len2(0);
  PartialSum sum;

  len1 = Length(lhs);
  len2 = Length(rhs);
  if(len1 < len2)
    lhs = AddPadding(lhs, len2-len1);
  else
    rhs = AddPadding(rhs, len1-len2);
  assert(Length(lhs) == Length(rhs));

  sum = AddPartialSum(lhs, rhs);
  if(sum.carry)
    sum.sum = InsertFront(sum.sum, 1);

  return sum.sum;
}

int main(void)
{
  ListNode *lhs(NULL);
  ListNode *rhs(NULL);
  ListNode *sum(NULL);
  
  lhs = InsertFront(lhs, 5);
  lhs = InsertFront(lhs, 2);
  PrintList(lhs);
  rhs = InsertFront(rhs, 6);
  rhs = InsertFront(rhs, 7);
  PrintList(rhs);

  sum  = SumOfListForward(lhs, rhs);
  PrintList(sum);
  
  lhs = Destroy(lhs);
  rhs = Destroy(rhs);
  sum = Destroy(sum);
  return 0;
}
