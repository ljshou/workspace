/* dis-joint-set implemented by L.J. in Nov.11, 2013 */
/* union by height */
#include "disjointset.h"
#include <iostream>
using namespace std;

void Initialize(DisJointSet s)
{
  for(int i=NumSets; i>0; --i)
    s[i] = 0;
}

//Assume root1 and root2 are roots
void SetUnion(DisJointSet s, SetType root1, SetType root2)
{
  if(s[root1] <= s[root2])//roo1 is deeper than root2
  {
    if(s[root1] == s[root2])
	  s[root1] --;
    s[root2] = root1;
  }
  else
  {
    s[root1] = root2;
  }
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


int main()
{
  DisJointSet s;
  Initialize(s);
  Print(s);
  SetUnion(s, 5, 6);
  SetUnion(s, 7, 8);
  SetUnion(s, 5, 7);
  SetUnion(s, 4, 5);
  Print(s);
  return 0;
}
