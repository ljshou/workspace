#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

int main(void)
{
  list<int> coll1;

  // insert elements into the first collection
  for(int i=1; i<=9; ++i){
    coll1.push_back(i);
  }

  // copy the elements of coll1 into coll2 by appending them
  vector<int> coll2;
  copy(coll1.begin(), coll1.end(), back_inserter(coll2));

  deque<int> coll3;
  copy(coll1.begin(), coll1.end(), front_inserter(coll3));

  set<int> coll4;
  copy(coll1.begin(), coll1.end(), inserter(coll4, coll4.begin()));

  return 0;
}
