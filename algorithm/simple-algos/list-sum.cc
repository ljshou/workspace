/**
 * @file list-sum.cc
 * @brief 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-06
 */

#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x=0)
    :val(x), next(NULL) {}
};

ListNode* CloneList(ListNode *list)
{
  ListNode dummy(0);
  ListNode *rear(&dummy), *node(NULL);

  while(list){
    node = new ListNode(list->val);
    rear->next = node;
    rear = rear->next;
    list = list->next;
  }
  return dummy.next;
}

ListNode* AddPaddings(ListNode *list, int n)
{
  assert(n >= 0);
  if(n == 0) return list;
  ListNode *node(NULL);
  for(int i=0; i<n; ++i)
  {
    node = new ListNode();
    node->next = list;
    list = node;
  }
  return list;
}

ListNode* DeletePaddings(ListNode *list, int n)
{
  assert(n >= 0);
  ListNode *next(NULL);
  for(int i=0; i<n && list; ++i)
  {
    next = list->next;
    delete list;
    list = next;
  }
  return list;
}

ListNode* DestroyList(ListNode *list)
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

/**
 * two lists of the same length
 * return their sum
 */
ListNode* Sum(int &carry, ListNode *lhs, ListNode *rhs)
{
  //exit
  if(lhs == NULL){
    carry = 0;
    return NULL;
  }

  ListNode *new_list = Sum(carry, lhs, rhs);

  int value = carry + lhs->val + rhs->val;
  carry = value / 10;
  value %= 10;

  ListNode *node = new ListNode(value);
  node->next = new_list;
  new_list = node;

  return new_list;
}

ListNode* add(ListNode *lhs, ListNode *rhs)
{
  int len1 = Length(lhs);
  int len2 = Length(rhs);

  //lhs always <= rhs
  if(len1 > len2){
    swap(lhs, rhs);
  }
  if(lhs == NULL) return CloneList(rhs);

  // add paddings
  lhs = AddPaddings(lhs, abs(len1 - len2));

  ListNode *new_list(NULL);
  int carry(0);

  new_list = Sum(carry, lhs, rhs);
  if(carry){
    ListNode *node = new ListNode(carry);
    node->next = new_list;
    new_list = node;
  }

  // delete paddings
  lhs = DeletePaddings(lhs, abs(len1 - len2));

  return new_list;
}

int main(void)
{
  ListNode *lhs(NULL), *rhs(NULL), *sum(NULL);

  lhs = new ListNode(1);
  lhs
  lhs = DestroyList(lhs);
  rhs = DestroyList(rhs);
  sum = DestroyList(sum);
  return 0;
}


