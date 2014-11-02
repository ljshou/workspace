/* POJ 1007 by L.J. in Oct. 17, 2013 */
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Data
{
  string a;
  int num;
};

int computeInverse(const string & a, int length)
{
  int num(0);
  for(size_t i=0; i<length; ++i)
   for(size_t j=i+1; j<length; ++j)
     if(a[i]>a[j]) ++num;
  return num;
}

int cmp(const void *lhs, const void *rhs)
{
  return ((Data*)lhs)->num - ((Data*)rhs)->num;
}

int main()
{
  int n, m;
  cin >> n >> m;
  Data *dna = new Data[m];
  for(int i=0; i<m; ++i){
    cin >> dna[i].a;
	dna[i].num = computeInverse(dna[i].a, n);
  }
  qsort(dna, m, sizeof(Data), cmp);
  for(int i=0; i<m; ++i)
    cout << dna[i].a << endl;

  delete [] dna;
  return 0;
}
