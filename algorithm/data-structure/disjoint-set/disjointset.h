#ifndef DISJOINTSET_H_
#define DISJOINTSET_H_

const   int NumSets = 8;
typedef int DisJointSet[ NumSets + 1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisJointSet s);
void SetUnion(DisJointSet x, SetType root1, SetType root2);
SetType Find(ElementType x, DisJointSet s);
#endif
