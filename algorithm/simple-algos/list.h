#include "list.h"
#include <iostream>
using namespace std;

const int N = 10;
struct Node
{
  ElementType element;
  Position next;
};

int Length(List list)
{
  int length(0);
  Position p = list;
  while(p)
  {
    p = p->next;
	++ length;
  }
  return length;
}

bool IsEmpty(List list)
{
  return list == NULL;
}

bool IsLast(Position p, List list)
{
  return p->next == NULL;
}

Position Find(ElementType x, List list)
{
   Position p = list;
   while(p && x != p->element) 
     p = p->next;
   return p;
}

ElementType Retrieve(Position p)
{
  if(p == NULL)
  {
    cerr << "NULL pointer" << endl;
	return -1;
  }
  return p->element;
}

Position FindPrevious(ElementType x, List list)
{
  Position p = list, q = p;
  while(p && p->element != x)
  {
    q = p;
    p = p->next;
  }
  if(p == NULL) return NULL;
  else
    return q;
}

void Insert(int k, ElementType x, List &list)
{//在第k个元素之后插入
  Position p = list;
  if(k < 0) cerr << "Out of Bounds" << endl;
  for(int index=1; index<k && p; ++index)
    p = p->next;
  if(p == NULL && k > 0) cerr << "Out of Bounds" << endl;
  struct Node *y = new struct Node;
  y->element = x;
  if(k)
  {//insert after p
    y->next = p->next;
	p->next = y;
  }
  else
  {//insert as the first node
    y->next = list;
	list = y;
  }
}

void Delete(int k, ElementType &x, List &list)
{
  Position p = list, q;
  if(list == NULL || k<1) cerr << "Out of Bounds" << endl;
  if(k == 1)
  {
	q = list;
    list = list->next;
	x = q->element;
	delete q;
  }
  else
  {
    for(int i=1; i<k-1 && p; ++i)
	  p = p->next; 
	if(p == NULL) cerr << "Out of Bounds" << endl;
	else
	{
	  q = p->next;
	  p->next = p->next->next;
	  x = q->element;
	  delete q;
	}
  }
}

void DeleteList(List &list)
{
  struct Node *current(list), *p;
  while(current)
  {
	p = current->next;
	delete current;
	current = p;
  }
  list = NULL;
}

void PrintList(List list)
{
  Position p = list;
  while(p)
  {
    cout << p->element << " ";
	p = p->next;
  }
  cout << endl;
}

bool IsListCircle(struct Node *first, Position &p)
{
  Position slow(first), fast(first);
  while(fast && slow)
  {
    fast = fast->next;
	  slow = slow->next;
		if(fast == NULL) break;
		fast = fast->next;
	  if(slow == fast) break;
  }
  if(fast == NULL || slow == NULL)
  {
    p = NULL;
	  return false;
  }
  else
  {
    slow = first;
	  while(fast != slow)
  	{
	    fast = fast->next;
	    slow = slow->next;
	  }
	  p = fast; //the enter point
	  return true;
  } 
}

int main()
{
  List list(NULL);
  Position p;
  ElementType x;
  for(int i=0; i<N; i++)
    Insert(i, i+1, list);
  cout << "the length of List: " << Length(list) << endl;
  PrintList(list);
  cout << "The previous one is: " << FindPrevious(3, list)->element << endl;
  Delete(2, x, list);
  PrintList(list);
  cout << "Does List have a circle: " << IsListCircle(list, p) << endl;
  Find(N, list)->next = Find(5, list);
  cout << "Does List have a circle: " << IsListCircle(list, p) << endl;
  cout << "The enter point is: " << p->element << endl;
  Find(N, list)->next = NULL;
  DeleteList(list);
  return 0;
}
