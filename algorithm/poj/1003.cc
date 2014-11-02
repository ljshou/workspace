#include <iostream>
using namespace std;

int main(void)
{
  double len, val;
  int i;

  while(cin >> len && len)
  {
    val = 0.0;
	for(i=1; val < len; ++i)
	  val += 1.0/(i+1.0);
	cout << i-1 << " card(s)" << endl;
  }

  return 0;
}

