#include "skip-list.h"
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

template<class E, class K>
SkipList<E,K>::SkipList(K large, int MaxE, double p)
{//constructor
    TailKey = large;
    MaxLevel = static_cast<int>(ceil(log(MaxE) / log(1/p)) - 1);
    CutOffs = static_cast<int>(p * RAND_MAX); 
    Levels = 0;
    srand(time(0));

    head = new SkipNode<E,K>(MaxLevel+1);
    tail = new SkipNode<E,K>(1);
    last = new SkipNode<E,K>*[MaxLevel+1];
    tail->data = TailKey;

    for(int i=0; i<=MaxLevel; ++i)
        head->link[i] = tail;
}

template<class E, class K>
SkipList<E,K>::~SkipList()
{//destructor
    SkipNode<E,K> *next;

    //delete all nodes through 0 level chain
    while(head!= tail)
    {
        next = head->link[0];
        delete head;
        head = next;
    }
    delete tail;

    delete [] last;
}

template<class E, class K>
bool SkipList<E,K>::Search(const K & k, E & e)const
{//search for element matching k, set e = this elem
    //if there's not, return false
    int i;
    if(k >= TailKey)
    {
        cerr << " key is too large" << endl;
        return false;
    }
    SkipNode<E,K> *ptr = head;
    for(i=MaxLevel; i>=0; --i)
    {
        while(ptr->link[i]->data < k)
        {
            ptr = ptr->link[i];
        }
    }
    e = ptr->link[0]->data;
    return (e == k);//overide operator ==
}

    template<class E, class K>
SkipNode<E,K>* SkipList<E,K>::SaveSearch(const K & k)
{
    int i;
    SkipNode<E,K> *ptr = head;
    for(i=Levels; i>=0; --i)
    {
        while(ptr->link[i]->data < k)
        {
            ptr = ptr->link[i];
        }
        last[i] = ptr;
    }
    return ptr->link[0];
}

    template<class E, class K>
int SkipList<E,K>::Level()
{
    int level(0);
    while(rand() <= CutOffs)
        ++level;
    return (level>MaxLevel) ? MaxLevel:level;
}

    template<class E, class K>
SkipList<E,K>& SkipList<E,K>::Insert(const E & e)
{//TODO
    K k = e;
    if(k >=TailKey) 
    {
        cerr << "key is too large" << endl;
        return *this;
    }

    //check whether in the list already
    SkipNode<E,K> *p = SaveSearch(k);
    if(p->data == e){
        cerr << "key already in the list" << endl;
        return *this;
    }

    int lev = Level();
    //fix lev to be <= Levels+1
    if(lev > Levels){
        lev = ++Levels;
        last[lev] = head;
    }
    SkipNode<E,K> *ptr = new SkipNode<E,K>(lev+1);
    ptr->data = e;
    for(int i=0; i<=lev; ++i){
        ptr->link[i] = last[i]->link[i];
        last[i]->link[i] = ptr;
    }

    return *this;
}

    template<class E, class K>
SkipList<E,K>& SkipList<E,K>::Delete(const K & k, E & e)
{//TODO
    if(k > TailKey){
        cerr << " key is too large" << endl;
        return *this;
    }

    SkipNode<E,K> *p = SaveSearch(k); 
    if(p->data != k){
        cerr << "element not exist" << endl;
        return *this;
    }
    for(int i=0; i<=Levels && last[i]->link[i] == p; ++i)
        last[i]->link[i] = p->link[i];

    //modify levels
    while(Levels > 0 && head->link[Levels] == tail)
        -- Levels;

    e = p->data;
    delete p;
    return *this;
}

    template<class E, class K>
void SkipList<E,K>::PrintSkipList()
{
    SkipNode<E,K> *ptr(head->link[0]);
    while(ptr != tail)
    {
        cout << ptr->data.key << " ";
        ptr = ptr->link[0];
    }
    cout << endl;
}

class Element
{
public:
    operator long()const {return key;}//bug
    Element& operator=(long k) {key=k; return *this; }
    int data;
    long key;
};

int main()
{
    SkipList<Element, long> skip_list(0x7FFFFFF);
    Element elem;
    for(int i=0; i<10; ++i)
    {
        elem.data = i;
        elem.key = i*i;
        skip_list.Insert(elem);
    }
    skip_list.Delete(9, elem);
    cout << "Search for 25: " << skip_list.Search(25, elem) << endl;
    skip_list.Delete(25, elem);
    cout << "Search for 25: " << skip_list.Search(25, elem) << endl;
    skip_list.PrintSkipList();
    return 0;
}
