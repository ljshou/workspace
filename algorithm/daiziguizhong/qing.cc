/**
 * @file qing.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-27
 */

#include <iostream>
using namespace std;

struct Node
{
    double val;
    Node *prev, *next;
    Node(int _val = 0 )
        :val(_val),prev(nullptr),next(nullptr){}
};

struct Set
{
private:
    //copy not allowed
    Set(const Set &rhs);
    Set& operator=(const Set &rhs);
    
    Node *head, *cur;
    int K;
    double sum;
    int size;
public:
    Set(const int _K = 10)
        :K(_K),sum(0),size(0)
    {
        cur = head = new Node[K];
        Node *tmp = head;
        for(int i=1;i<K;++i)
        {
            tmp->next = (head+i);
            tmp->next->prev = (head + i);
            tmp = tmp->next;
        }
        (head + (K-1))->next = head;
        head->prev = (head + (K-1));
    }
    
    ~Set() {
        delete [] head;
    }
    void Insert(double x);
    double Mean();
};

void Set::Insert(double x)
{
    sum -= cur->val;
    sum += x;
    cur->val = x;
    cur = cur->next;
    if(size < K) ++size;
}
double Set::Mean()
{
    return sum/size;
}

int main(void)
{
    Set l(3);
    l.Insert(1);
    cout << l.Mean() << endl;
    l.Insert(2);
    cout << l.Mean() << endl;
    l.Insert(3);
    cout << l.Mean() << endl;
    l.Insert(4);
    cout << l.Mean() << endl;
    return 0;
}
