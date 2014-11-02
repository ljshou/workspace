#include <bits/stdc++.h>
using namespace std;

struct LinkNode {
  LinkNode *next, *prev;
  int val;
  LinkNode(int x=0):val(x), next(nullptr), prev(nullptr) {}
};

struct LinkNode * head;
void remove( struct LinkNode * todelete )
{
  assert(todelete != nullptr && head != nullptr);
  LinkNode dummy(-1); 
  dummy.next = head;
  head->prev = &dummy;

  todelete->prev->next = todelete->next;
  if(todelete->next != nullptr) {
    todelete->next->prev = todelete->prev;
  }
  head = dummy.next;
  if(head && head->prev == &dummy) head->prev = nullptr; //if todelete is the first node
  delete todelete;
}

void insert(int x) {
}

void print() {
  LinkNode *p = head;
  while(p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}

int main(void)
{
  head = new LinkNode(1);
  LinkNode *node2 = new LinkNode(2);
  LinkNode *node3 = new LinkNode(3);
  head->next = node2;
  node2->prev = head;
  node2->next = node3;
  node3->prev = node2;
  print();
  remove(head);
  print();
  return 0;
}
