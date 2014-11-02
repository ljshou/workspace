//copyright @ L.J.SHOU Feb.14, 2014
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;

//A and B have the same size K
vector<int> TopKSum(vector<int> &A, vector<int> &B)
{
  vector<int> result;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q; 

  /* sort */
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  for(int i=0; i<A.size(); ++i)
    Q.push(make_pair(A[i] + B[0], 0)); /* 0 denotes index in B */

  for(int i=0; i<A.size(); ++i)
  {
    pair<int, int> e = Q.top(); Q.pop();
	result.push_back(e.first);
	/* push next element back into heap */
	if(i < A.size()-1)/* 避免 B[e.second+1]越界 */
	{ 
	  e.first = e.first - B[e.second] + B[e.second+1];
	  e.second ++;
	  Q.push(e);
	}
  }

  return result;
}

int main(void)
{
  vector<int> A, B, sum;
  A.push_back(1);
  A.push_back(2);
  A.push_back(3);

  B.push_back(2);
  B.push_back(4);
  B.push_back(4);

  sum = TopKSum(A, B); 
  /* print vector */
  copy(sum.begin(), sum.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  
  return 0;
}



