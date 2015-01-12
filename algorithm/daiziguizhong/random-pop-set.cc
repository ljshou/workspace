/**
 * @file random-pop-set.cc
 * @brief set supporting random pop
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-12
 */

#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

struct Node {
    Node *pre, *next;
    int val;
    Node(int x=0):
        val(x), pre(this), next(this) {}
};

class Set {
public:
    Set() : size_(0) {}
    ~Set() { clear(); }
    void insert(int x);
    void remove(int x);
    int randomPop();
    int size() const {return size_;}
private:
    int size_;
    Node dummy;
    unordered_map<int, Node*> hash;

    void clear() {
        size_ = 0;
        hash.clear();
        Node *p = dummy.next, *next = nullptr;
        while(p != &dummy) {
            next = p->next;
            delete p;
            p = next;
        }
        dummy.pre = dummy.next = &dummy;
    }

    //no copy allowed
    Set(const Set&rhs);
    Set& operator=(const Set& rhs);
};

void Set::insert(int x) {
    if(hash.find(x) == hash.end()) {
        Node * node = new Node(x);
        //insert front
        node->next = dummy.next;
        node->next->pre = node;
        node->pre = &dummy;
        dummy.next  = node;
        ++size_;
        hash[x] = node;
    }
}

void Set::remove(int x) {
    if(hash.find(x) != hash.end()) {
        Node *node = hash[x];
        node->pre->next = node->next;
        node->next->pre = node->pre;
        hash.erase(hash.find(x));
        --size_;
        delete node;
    }
}

int Set::randomPop() {
    if(size_ == 0) throw runtime_error("empty");
    int index = rand() % size_;
    Node *p = dummy.next;
    for(int i=0; i<index; ++i)
        p = p->next;
    return p->val;
}

void Test() {
    Set s;
    for(int i=1; i<=5; ++i)
        s.insert(i);
    assert(s.size() == 5);
    s.remove(0);
    assert(s.size() == 5);
    s.remove(3);
    assert(s.size() == 4);
    s.remove(3);
    assert(s.size() == 4);
    s.remove(4);
    assert(s.size() == 3);
    s.insert(4);
    assert(s.size() == 4);
    s.insert(400);
    assert(s.size() == 5);

    srand(time(0));
    for(int i=0; i<10; ++i) 
        cout << s.randomPop() << " ";
    cout << endl;
}

int main(void)
{
    Test();
    return 0;
}
