#include <iostream>
#include <stdexcept>
#include <assert.h>
#include <stack>

#include <stdlib.h>

using namespace std;
/*
//implement stack with the singly list
template <typename T>
struct DuListNode
{
    T val;
    DuListNode *next;
	DuLinkNode *prev;
    DuListNode(T x):val(x),next(NULL),prev(NULL) {}
};

template <typename T>
class Stack
{
private:
    ListNode<T> *head;
    void destoryList();

public:
    Stack();
    ~Stack();
    Stack & operator=(const Stack &rhs);

    bool empty() const;
    void clear();

    void push(const T &val);
    void pop();
    T& top();
    void reverse();
    void swap(Stack &rhs)
    {
        std::swap(rhs.head, head);
    }
    void print() const;
};

template <typename T>
Stack<T>::Stack():head(NULL)
{
    //to do
}

template <typename T>
void Stack<T>::reverse()
{
    ListNode<T> *new_head = NULL;
    ListNode<T> *temp = NULL;

    while(head)
    {
        temp = head->next;

        head->next = new_head;
        new_head = head;

        head = temp;
    }
    head = new_head;
}

template <typename T>
void Stack<T>::destoryList()
{
    if(head == NULL)
        return;
    while(head)
    {
        ListNode<T> *temp = head->next;
        delete head;
        head = NULL;
        head = temp;
    }
}
template <typename T>
Stack<T>::~Stack()
{
    destoryList();
}

template <typename T>
Stack<T> & Stack<T>::operator= (const Stack<T> &rhs)
{
    if(!empty())
    {
        destoryList();
        head = NULL;
    }
    if(rhs.empty())
    {
        return *this;
    }

    ListNode<T> *temp = rhs.head;
    ListNode<T> *ret_temp = NULL;
    ListNode<T> *elem = new ListNode<T>(temp->val);
    head = elem;
    ret_temp = head;
	temp = temp->next;

    while(temp)
    {
        elem = new ListNode<T>(temp->val);
        ret_temp->next = elem;
        ret_temp = elem;
        temp = temp->next;
    }
    return *this;
}

template <typename T>
void Stack<T>::push(const T & val)
{
    ListNode<T> *node = new ListNode<T>(val);
    node->next = head;
    head = node;
}

template <typename T>
bool Stack<T>::empty() const
{
    return head == NULL;
}

template <typename T>
void Stack<T>::clear()
{
    destoryList();
}

template <typename T>
void Stack<T>::pop()
{
    if(this->empty())
    {
        throw runtime_error("Stack is empty, pop operation failed!!!");
        exit(1);
    }
    ListNode<T> *temp = head->next;

    delete head;
    head = NULL;

    head = temp;
}

template <typename T>
T& Stack<T>::top()
{
    if(this->empty())
    {
        throw runtime_error("Stack is empty, top operation failed!!!");
        exit(1);
    }
    return head->val;
}

template <typename T>
void Stack<T>::print() const
{
    ListNode<T> *t = head;
    while(t)
    {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
}
*/

template<typename T>
class immutable_queue
{
private:
    stack<T> s_push;
    stack<T> s_pop;
    int count;

public:
    immutable_queue();
//    immutable_queue(bool, T& elem);

    ~immutable_queue();
    immutable_queue<T> enqueue(const T &element);
    immutable_queue<T> dequeue();
    T peek() ;
    int size() const;
    bool empty() const;
    //void print() const;
};

template <typename T>
immutable_queue<T>::immutable_queue():count(0)
{
    //to do
}

template <typename T>
immutable_queue<T>::~immutable_queue()
{
}

template <typename T>
bool immutable_queue<T>::empty() const
{
    return (s_push.empty() && s_pop.empty());
}

template <typename T>
immutable_queue<T> immutable_queue<T>::enqueue(const T &element)
{
    immutable_queue<T> ret;
	ret.s_push = s_push;
	ret.s_pop = s_pop;

    ret.count = count+1;
    ret.s_push.push(element);

    return ret;
}

template <typename T>
immutable_queue<T> immutable_queue<T>::dequeue()
{
    immutable_queue<T> ret;

	if(s_pop.empty())
	{
		while(!s_push.empty())
		{
			s_pop.push(s_push.top());
			s_push.pop();
		}
	}
    ret.s_push = s_push;
    ret.s_pop = s_pop;
    ret.count = count-1;
    (ret.s_pop).pop();

    return ret;
}


template <typename T>
T immutable_queue<T>::peek()
{
    if(empty())
    {
        throw range_error("Out of range!!!");
        exit(1);
    }

    if(s_pop.empty())
	{
		while(!s_push.empty())
		{
			s_pop.push(s_push.top());
			s_push.pop();
		}
	}

    return s_pop.top();
}


template <typename T>
int immutable_queue<T>::size() const
{
    return count;
}

/*
template <typename T>
void immutable_queue<T>::print() const
{
    cout << "push : ";
    s_push.print();

    cout << "pop : ";
    s_pop.print();
}
*/



/*
int main()
{
    immutable_queue<int> p; 
    assert(p.size() ==  0);
    p = p.enqueue(2);
	//p.print();
    assert(p.size() ==  1);
    p = p.enqueue(9);
	//p.print();
    assert(p.peek() ==  2);
    assert(p.size() ==  2);
    p = p.dequeue();
	//p.print();
    assert(p.peek() == 9);
    p = p.enqueue(10);
    assert(p.peek() ==  9);
    p = p.dequeue();
    assert(p.peek() ==  10);
    p = p.dequeue();
    assert(p.size() == 0);
    immutable_queue<int> q;
    immutable_queue<int> q1 = q.enqueue(1);
    immutable_queue<int> q12 = q1.enqueue(2);

    immutable_queue<int> q123 = q1.dequeue();

    q.print();
    q1.print();
    q12.print();
    cout << "print q123..." << endl;
    q123.print();
	cout << "peek : " << q123.peek() << endl;

	
    if(q.empty())
        cout << "q is empty..." << endl;

    assert(!q1.empty());
    assert(!q12.empty());
    assert(!q123.empty());

    return 0;
}
*/
