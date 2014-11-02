#ifndef OFFLINEMINI_H_
#define OFFLINEMINI_H_
#include <iostream>
using std::cout;
using std::endl;

const int NumSets = 7;
typedef int DisJointSet[ NumSets + 1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisJointSet s)
{
  for(int i=NumSets; i>0; --i)
    s[i] = 0;
}

//Assume root1 and root2 are roots
void SetUnion(DisJointSet s, SetType root1, SetType root2)
{
  s[root2] = root1;
}

// return the disjoint set which x belongs to
SetType Find(ElementType x, DisJointSet s)
{
  if(s[x] < 0)
    return x;
  else
    return Find(s[x], s);
}

void Print(DisJointSet s)
{
  for(int i=1; i<=NumSets; ++i)
    cout << s[i] << " ";
  cout << endl;
}
#endif
