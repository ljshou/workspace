/**
 * @file print-most-frequent-words.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-03
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

struct TrieNode {
    bool flag;
    int heap_index;
    int count;
    TrieNode *children[26];

    TrieNode(): flag(false), heap_index(-1), count(0) {
        fill_n(children, 26, nullptr);
    }
};

TrieNode* Destroy(TrieNode *root)
{
    if(!root) return nullptr;
    for(int i=0; i<26; ++i)
        root->children[i] = Destroy(root->children[i]);
    delete  root;
    return nullptr;
}

struct MinHeapNode {
    int count;
    string str;
    TrieNode *root;
    MinHeapNode(int c=0, const string s="", TrieNode *r=nullptr):
        count(c), str(s), root(r) {}
    bool operator<(const MinHeapNode &rhs) const{
        return count < rhs.count;
    }
};

class MinHeap {
public:
    MinHeap(int k=10)
        : capacity(k), size(0) {
        array = new MinHeapNode[k+1];
        //sentinel
        array[0].count = INT_MIN;
    }
    ~MinHeap() {
        delete [] array;
    }
    
    void Insert(TrieNode *root, const string &str) {
        if(IsFull()) return;
        int x = root->count;
        int i = ++size;
        for(; array[i/2].count > x; i/=2) {
            array[i] = array[i/2];
            SetHeapIndex(i);
        }
        array[i] = MinHeapNode(x, str, root);
        SetHeapIndex(i);
    }

    void Pop() {
        assert(!IsEmpty());
        swap(array[1], array[size]);
        SetHeapIndex(1);
        array[size].root->heap_index = -1;
        --size;
        MinHeapify(1);
    }
    int Top() const { assert(!IsEmpty()); return array[1].count; }
    bool IsFull() const {return capacity == size;}
    bool IsEmpty() const {return size == 0;}
    void IncreaseKey(int index, int val) {
        array[index].count += val;
        MinHeapify(index);
    }
    void Display() const {
        for(int i=1; i<=size; ++i)
            cout << array[i].str << ": " << array[i].count << endl;
    }

private:
    MinHeapNode *array;
    int size, capacity;

    void SetHeapIndex(int i) {
        array[i].root->heap_index = i;
    }

    void MinHeapify(int index) {
        MinHeapNode node = array[index];

        int child;
        for(; 2*index<=size; index=child) {
            child = 2*index;
            if(child+1 <= size && array[child+1].count 
                                < array[child].count)
                ++child;

            if(node.count <= array[child].count)
                break;

            array[index] = array[child];
            SetHeapIndex(index);
        }
        array[index] = node;
        SetHeapIndex(index);
    }

    //copy not allowed
    MinHeap(const MinHeap &);
    MinHeap& operator=(const MinHeap&);
};

void Insert(TrieNode *root, MinHeap &min_heap, const string &str)
{
    assert(root != nullptr);
    TrieNode *p = root;
    //insert into trie
    for(auto c : str) {
        int index = tolower(c) - 'a';
        if(p->children[index] == nullptr)
            p->children[index] = new TrieNode();
        p = p->children[index];
    }
    p->flag = true;
    ++p->count;

    if(p->heap_index != -1) {
        min_heap.IncreaseKey(p->heap_index, 1);
    }
    else {
        if(min_heap.IsFull()) {
            if(min_heap.Top() < p->count) {
                min_heap.Pop();
                min_heap.Insert(p, str);
            }
        }
        else {
            min_heap.Insert(p, str);
        }
    }
}

void PrintMostFreqWords(const string &file, int k)
{
    if(k < 1) return;
    ifstream in(file.c_str());
    string word;

    TrieNode *root = new TrieNode();
    MinHeap min_heap(k);

    while(in >> word) {
        Insert(root, min_heap, word);
    }
    min_heap.Display();
    root = Destroy(root);
}

int main(void)
{
    PrintMostFreqWords("input", 5);
    return 0;
}
