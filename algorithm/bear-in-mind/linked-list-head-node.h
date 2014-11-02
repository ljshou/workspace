#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
typedef int ElementType;
struct  Node;
typedef struct Node* Position;
typedef struct Node* List;

List MakeEmpty();
void DestroyList(List list);
int  Length(List list);
void Insert(List list, int k, ElementType x);
void Insert(List list, ElementType x);
void Delete(List list, int k, ElementType x);
void Delete(List list, ElementType x);
void Print(List list);
int  Find(List list, ElementType);
Position IsCircled(List list);
#endif
