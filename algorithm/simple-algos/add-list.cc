/**
 * @file add-list.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-02
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  ListNode(int x=0)
    :val(x), next(nullptr) {}
  int val;
  ListNode *next;
};

int Length(ListNode *list)
{
  int len(0);
  while(list) {
    ++len; 
    list = list->next;
  }
  return len;
}


/**
 * precondition: lhs and rhs have the same length
 * 12345 is stored as 1->2->3->4->5->nullptr
 */
ListNode* AddList(ListNode *lhs, ListNode *rhs)
{
  if(lhs == nullptr) return nullptr;
  ListNode dummy(-1), *node(nullptr);
  ListNode *prev(&dummy), *rear(&dummy);

  while(lhs && rhs) {
    node = new ListNode(lhs->val + rhs->val);
    rear->next = node;
    rear = node;

    if(node->val < 10) {
      if(node->val < 9) prev = rear;
      //prev = prev->next; //wrong
    }
    else {
      //deal with carry
      node->val %= 10;
      if(prev == &dummy) {
        //add a new node at head
        ListNode *temp = new ListNode(0);
        temp->next = prev->next;
        prev->next = temp;
        prev = prev->next;
      }
      ++ prev->val;
      for(prev=prev->next; prev!=rear; prev=prev->next) prev->val = 0;
    }
    lhs = lhs->next;
    rhs = rhs->next;
  }
  return dummy.next;
}

void PrintList(ListNode *list)
{
  while(list) {
    cout << list->val;
    list = list->next;
  }
  cout << endl;
}

ListNode* DeleteList(ListNode *list)
{
  ListNode *next(nullptr);
  while(list) {
    next = list->next;
    delete list;
    list = next;
  }
  return nullptr;
}

ListNode* buildList(const vector<int> &num)
{
  ListNode dummy(-1), *rear(&dummy);
  for(auto x: num) {
    rear->next = new ListNode(x);
    rear = rear->next;
  }
  return dummy.next;
}

void Sum(const vector<int> &lhs, const vector<int> &rhs)
{
  int num1(0), num2(0);
  for(auto x : lhs) {
    num1 = num1*10 + x;
  }
  for(auto x : rhs) {
    num2 = num2*10 + x;
  }
  cout << num1 + num2 << "\t";
}


const int N = 5;

int main(void)
{
  srand(time(0));
  vector<int> num1(N), num2(N);
  for(int i=0; i<N; ++i) {
    num1[i] = rand() % 10;
    num2[i] = rand() % 10;
  }
  /*
  cout << "num1: ";
  copy(num1.begin(), num1.end(), ostream_iterator<int>(cout, ""));
  cout << endl;
  cout << "num2: ";
  copy(num2.begin(), num2.end(), ostream_iterator<int>(cout, ""));
  cout << endl;
  */

  ListNode *lhs = buildList(num1);
  ListNode *rhs = buildList(num2);

  ListNode *sum = AddList(lhs, rhs);
  Sum(num1, num2);
  PrintList(sum);
  
  lhs = DeleteList(lhs);
  rhs = DeleteList(rhs);
  sum = DeleteList(sum);
  return 0;
}
