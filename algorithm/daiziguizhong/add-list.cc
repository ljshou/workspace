/**
 * @file add-list.cc
 * @brief add two lists
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-30
 */
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x=0): val(x), next(nullptr) {}
};

ListNode *BuildList(const vector<int> &vec)
{
    ListNode dummy(-1), *rear(&dummy);
    for(auto x : vec) {
        rear->next = new ListNode(x);
        rear = rear->next;
    }
    return dummy.next;
}

void PrintList(const ListNode *head)
{
    for(; head; head=head->next) {
        cout << head->val << "";
    }
    cout << endl;
}

ListNode *Destroy(ListNode *head)
{
    ListNode *next(nullptr);
    while(head) {
        next = head->next;
        delete head;
        head = next;
    }
    return nullptr;
}

ListNode * addList(ListNode *lhs, ListNode *rhs)
{
    int num(0), carry(0);
    ListNode dummy(-1), *rear(&dummy), *node(nullptr);
    while(lhs || rhs) {
        if(lhs) {
            num += lhs->val;
            lhs = lhs->next;
        }
        if(rhs) {
            num += rhs->val;
            rhs = rhs->next;
        }
        num += carry;
        carry = num / 10;
        num %= 10;
        node = new ListNode(num);
        num = 0;
        rear->next = node;
        rear = rear->next;
    }
    if(carry != 0) rear->next = new ListNode(1);
    return dummy.next;
}

ListNode* addList2(ListNode *lhs, ListNode *rhs)
{
    ListNode dummy(-1), *rear(&dummy);
    ListNode *p(&dummy), *q(nullptr);
    int num(0);

    while(lhs && rhs) {
        //add a new node
        num = lhs->val + rhs->val;
        q = new ListNode(num % 10);
        rear->next = q;
        rear = rear->next;

        //deal with carry
        if(num < 9) {
            p = q;
        }
        else if(num > 9) {
            if(p == &dummy) {
                //add a heading node
                ListNode *node = new ListNode(0);
                node->next = dummy.next;
                dummy.next = node;
                p = node;
            }
            ++p->val;
            for(p=p->next; p!=q; p=p->next) p->val = 0;
            assert(p == q); //p points to the node before 9999s
        }

        lhs = lhs->next;
        rhs = rhs->next;
    }
    return dummy.next;
}

ListNode *helper(ListNode *lhs, ListNode *rhs, int &carry)
{
    if(lhs == nullptr && rhs == nullptr) return nullptr;
    ListNode *ret = helper(lhs->next,rhs->next,carry);
    int cur = lhs->val + rhs->val + carry;
    carry = cur/10;
    cur = cur - 10 *carry;
    ListNode *node = new ListNode(cur);
    node->next = ret;
    ret = node;
    return ret;
}
ListNode *addList3(ListNode *lhs, ListNode *rhs)
{
    //ListNode dummy(0), *ret = &dummy;
    
    int carry = 0 ;
    ListNode *ret = helper(lhs,rhs,carry);
    if(carry)
    {
        ListNode *node = new ListNode(carry);
        node->next = ret;
        ret = node;
    }
    return ret;
}


int main(void)
{
    vector<int> vec1{9,9,2,2,7,9}, vec2{0,0,7,7,2,1};
    ListNode *lhs = BuildList(vec1);
    ListNode *rhs = BuildList(vec2);
    PrintList(lhs);
    PrintList(rhs);
    ListNode *sum = addList2(lhs, rhs);
    PrintList(sum);
    ListNode *sum2 = addList3(lhs, rhs);
    PrintList(sum2);

    lhs = Destroy(lhs);
    rhs = Destroy(rhs);
    sum = Destroy(sum);
    return 0;
}
