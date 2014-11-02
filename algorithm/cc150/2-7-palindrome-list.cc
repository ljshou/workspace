// copyright @ L.J.SHOU Dec.14, 2013
// check whether a list is a palindrome
#include "linked-list.h"
#include <cassert>
#include <iostream>
#include <stack>
using namespace std;

bool IsPalindrome(ListNode const *list)
{ //仅需比较后半部分和前半部分是否逆序相同
  //fast, slow pointer
  ListNode const *fast(list), *slow(list);
  stack<int> my_stack;

  while(fast && fast->next)
  {
    fast = fast->next->next;
	my_stack.push(slow->val);
	slow = slow->next;
  }
  if(fast != NULL)
    slow = slow->next;

  while(slow)
  {
	if(my_stack.top() != slow->val)
	  return false;
    slow = slow->next;
	my_stack.pop();
  }

  return true;
}

bool IsPalindromeRecur(ListNode const *list, int length, ListNode * & next)
{
  if(length == 0 || list == NULL){
    next = NULL;
	return true;
  }
  if(length == 1){
    next = list->next;
	return true;
  }
  if(length == 2){
    next = list->next->next;
	return (list->val == list->next->val);
  }
  bool flag;
  if(IsPalindromeRecur(list->next, length-2, next))
  {
    flag = list->val == next->val; 
	next = next->next;
	return flag;
  }
  else
    return false;
}

bool IsPalindrome2(ListNode const *list)
{
  ListNode *next;
  return IsPalindromeRecur(list, Length(list), next);
}

int main(void)
{
  ListNode *list(NULL); 

  list = InsertRear(list, 1);
  list = InsertRear(list, 2);
  list = InsertRear(list, 2);
  list = InsertRear(list, 1);

  PrintList(list);
  cout << "Is palindrome? " << IsPalindrome2(list) << endl;
  list = Destroy(list);
  return 0;
}
