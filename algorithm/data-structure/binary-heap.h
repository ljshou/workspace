#ifndef _BINARYHEAP_H_
#define _BINARYHEAP_H_
struct Heap;
typedef int ElementType;

Heap* Initialize(int max_elements);
void Destroy(Heap* h);
void MakeEmpty(Heap* h);
void Insert(ElementType x, Heap* h);
ElementType DeleteMin(Heap* h);
ElementType FindMin(Heap* h);
bool IsEmpty(Heap* h);
bool IsFull(Heap* h);
void PercolateUp(Heap* h, int i);
void PercolateDown(Heap* h, int i);
void DeceaseKey(Heap* h, int delta, int i);
void InceaseKey(Heap* h, int delta, int i);
void Delete(Heap* h, int i);
Heap* BuildHeap(int *element, int length); 
#endif
