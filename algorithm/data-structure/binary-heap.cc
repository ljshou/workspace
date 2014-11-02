// copyright @ L.J.SHOU Nov.14, 2013
#include "binary-heap.h"
#include <iostream>
using namespace std;

struct Heap
{
  int capacity;
  int size;
  ElementType *element;
};

Heap* Initialize(int max_elements)
{//start from index 1
  Heap* q = new struct Heap;
  q->element = new ElementType[max_elements + 1];
  q->capacity = max_elements;
  q->size = 0;
  q->element[0] = -0x7FFFFFF;
  return q;
}

void Destroy(Heap* q)
{
  delete [] q->element;
  delete q;
}

void MakeEmpty(Heap* q)
{
  q->size = 0;
}

void PercolateUp(Heap* q, int index)
{
  int i;
  ElementType x;
  x = q->element[index];
  for(i=index; x < q->element[i/2]; i/=2)
    q->element[i] = q->element[i/2];
  q->element[i] = x;
}

void PercolateDown(Heap* q, int index)
{
  int i, child; 
  ElementType x;
  x = q->element[index];
  for(i=index; 2*i<=q->size; i=child)
  {//find smaller child
    child = 2*i;//left child
	if(child != q->size && q->element[child+1] < q->element[child])
	  ++ child;
	if(x > q->element[child])
	  q->element[i] = q->element[child];
	else
	  break;
  }
  q->element[i] = x;
}

void Insert(ElementType x, Heap* q)
{//percolate up, if < parent
  if(IsFull(q)){
    cerr << "Heap* is full" << endl;
	return;
  }
  int i;
  for(i = ++q->size; x < q->element[i/2]; i/=2)
	q->element[i] = q->element[i/2]; 
  q->element[i] = x;
}

ElementType DeleteMin(Heap* q)
{//percolate down, find the smaller one of childen
  if(IsEmpty(q)){
    cerr << "Heap* is empty" << endl;
	return q->element[0];
  }
  ElementType last, min;
  int i, child;
  last = q->element[q->size --];
  min  = q->element[1];
  for(i=1; 2*i <= q->size; i = child)
  {//find the smaller child
    child = 2*i;//left child 
	if(child != q->size && q->element[child+1] < q->element[child])
	  ++ child;
	if(last > q->element[child])
	  q->element[i] = q->element[child];
	else
	  break;
  }
  q->element[i] = last;
  return min;
}

ElementType FindMin(Heap* q)
{
  if(IsEmpty(q)){
    cerr << "Heap* is empty" << endl;
	return q->element[0];
  }
  else
    return q->element[1];
}

bool IsEmpty(Heap* q)
{
  return (q->size == 0);
}

bool IsFull(Heap* q)
{
  return (q->size == q->capacity);
}

void DecreaseKey(Heap* q, int delta, int index)
{//Percolate up
  if(index < 1 || index > q->size){
    cerr << "index is out of range" << endl;
	return;
  }
  if(delta < 0){
    cerr << "delta must be positive" << endl;
	return;
  }
  q->element[index] -= delta;
  PercolateUp(q, index);
}

void IncreaseKey(Heap* q, int delta, int index)
{//Percolate down
  if(index < 1 || index > q->size){
    cerr << "index is out of range" << endl;
	return;
  }
  if(delta < 0)
  {
    cerr << "delta must be positive" << endl;
	return;
  }
  q->element[index] += delta;
  PercolateDown(q, index);
}

void Delete(Heap* q, int index)
{//DecreaseKey to infinity, and DeleteMin
  DecreaseKey(q, 0x7FFF, index);
  DeleteMin(q);
}

Heap* BuildHeap(int *element, int length)
{
  Heap* q = new struct Heap;
  q->element = element;
  q->capacity = q->size = length;
  for(int i=q->size/2; i>0; --i)
    PercolateDown(q, i);
  return q;
}

int main()
{
  int a[]={11,10,9,8,7,6,5,4,3,2,1};
  Heap* queue; 
  queue = BuildHeap(a, sizeof(a)/sizeof(int) - 1);
  while(queue->size)
    cout << DeleteMin(queue) << " ";
  cout << endl;
  delete queue;
  return 0;
}
