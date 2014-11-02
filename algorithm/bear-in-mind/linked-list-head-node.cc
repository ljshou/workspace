/* linked list with a head node 
  Author: L.J.
  Nov.22, 2013
  Type num: 2
*/
#include "linked-list-head-node.h"
#include <iostream>
using namespace std;

struct Node{
  ElementType element;
  struct Node *next;
  Node(ElementType x=0, struct Node* p=NULL)
          :element(x), next(p){};
};

List MakeEmpty()
{
  List list_ = new struct Node;
  list_->next = NULL;
  return list_;
}

void DestroyList(List list)
{
  List list_(list);
  struct Node *tmp;
  while(list_)
  {
    tmp = list_->next; 
	delete list_;
	list_ = tmp;
  }	
}

int Length(List list)
{
  List list_(list);
  int length(0);
  while(list_->next)
  {
    ++ length;
	list_ = list_->next; 
  }
  return length;
}

void Insert(List list, int k, ElementType x)
{
  struct Node *ptr_node(NULL);
  List list_(list);
  if(k < 0 || k > Length(list_)){
    cerr << "Out of Range" << endl;
	return;
  }
  //locate the insert spot
  for(int i=0; i<k; ++i)
    list_ = list_->next;
  //insert new node
  ptr_node = new struct Node;
  ptr_node->element = x;
  ptr_node->next = list_->next;
  list_->next = ptr_node;
}

void Delete(List list, int k, ElementType x)
{
  List list_(list);
  struct Node *tmp(NULL);
  if(k <1 && k > Length(list_)){
    cerr << "Out of Range" << endl;
  	return;
  }
  //pinpoint
  for(int i=0; i<k-1; ++i)
    list_ = list_->next;
  tmp = list_->next;
  x = tmp->element;
  list_->next = list_->next->next;
  delete tmp;
}

int Find(List list, ElementType x)
{
  int index(1);
  List list_(list->next);
  while(list_ && list_->element != x)
  {
    list_ = list_->next;
	++ index;
  }
  if(list_ == NULL) return -1;
  else return index;
}

void Print(List list)
{
  List list_(list->next);
  while(list_)
  {
    cout << list_->element << " ";
	list_ = list_->next;
  }
  cout << endl;
}

//determin whether the list is circled
Position IsCircled(List list)
{
  struct Node *fast(list), *slow(list);

  while(fast && slow)
  {
    slow = slow->next;
	fast = fast->next;
	if(fast == NULL) return NULL; // no circle
	  fast = fast->next;
	if(fast == slow) break; //is circled
  }
  if(fast && slow)
  {
    fast = list;
	while(fast != slow) 
	{
	  fast = fast->next;
	  slow = slow->next;
	}
	  return fast; // enter node of circle
  }
  return NULL;
}

int main()
{
	List list;
	ElementType x;
	list = MakeEmpty();
	Insert(list, 0, 1);
	Insert(list, 1, 2);
	Insert(list, 2, 3);
	Insert(list, 3, 4);
	Delete(list, 2, x);
	cout << "Find(1): " << Find(list, 3) << endl;
	cout << "length: " << Length(list) << endl;
	cout << "IsCircled? " << IsCircled(list) << endl;
	Print(list);
	DestroyList(list);
  return 0;
}
