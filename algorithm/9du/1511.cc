/**
 * @file 1511.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-28
 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  ListNode *next;
  int val;
};

void ReversePrint(ListNode *list)
{
  stack<int> s;
  while(list)
  {
    s.push(list->val);
    list = list->next;
  }
  while(!s.empty()) {
    cout << s.top() << endl;
    //printf("%d\n", s.top());
    s.pop();
  }
}

void Destroy(ListNode *list)
{
  ListNode *next(NULL);
  while(list)
  {
    next = list->next;
    free(list);
    list = next;
  }
}

int main(void)
{
  ListNode dummy;
  dummy.next = NULL;
  ListNode *rear(&dummy);
  int x;
  while(scanf("%d", &x) != EOF && x != -1)
  {
    rear->next = (ListNode*)malloc(sizeof(ListNode));
    rear = rear->next;
    rear->val = x;
    rear->next = NULL;
  }
  ReversePrint(dummy.next);
  //Destroy(dummy.next);
  return 0;
}
