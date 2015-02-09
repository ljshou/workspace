/* heap sort implemented by L.J. in Oct. 14, 2013 */
/* Algotithm complexity: O(nlg(n)) */
/* type num: 9 */
#include <iostream>
#include <cassert>
using namespace std;

inline void swap(int& a, int& b)
{
    int temp = a; a = b; b = temp;
}

void PercDownRecur(int *a, int heapSize, int i)
{   //PercolateDown
    //pick the larger one of two children as parent
    int largest, l, r;
    l = 2*i+1;
    r = 2*i+2;
    if(l < heapSize && a[l] > a[i])
        largest = l;
    else 
        largest = i;
    if(r < heapSize && a[r] > a[largest])
        largest = r;

    if(largest != i){
        swap(a[largest], a[i]);
        PercDownRecur(a, heapSize, largest);
    }

}

void PercDown(int *a, int length, int i)
{ //non-recursive
    int child, x;

    x = a[i];
    child = (i<<1) + 1;//left child
    while(child < length)
    {
        if(child+1 < length && a[child+1] > a[child])
            child++;
        if(x >= a[child]) {
            break;
        }
        else{
            a[i] = a[child];
            i = child;
        }
        child = (i<<1) + 1;
    }
    a[i] = x;
}

void buildMaxHeap(int *a, int heapSize)
{
    for(int i=heapSize/2; i>=0; --i){
        PercDown(a, heapSize, i);
    }
}

void heapSort(int *a, int length)
{
    int heapSize = length;
    buildMaxHeap(a, heapSize);
    for(int i=length-1; i>0; --i){
        swap(a[0], a[i]);
        PercDown(a, --heapSize, 0);
    }
}


int main()
{
    int a[10]={10,9,8,7,6,18,8,0,-1,9};
    heapSort(a, 10);
    for(int i=0; i<10; ++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
