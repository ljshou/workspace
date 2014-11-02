#include <iostream>
#include<cstdio>
#include<cstdlib>
#include "curr1.h"
using namespace std;
int main (void)
{
	Currency g, h(plus1, 3, 50), i, j;
	g.Set(minus1, 2, 25);
	i.Set(-6.45);
	j = h.Add(g);
	j.Output(); cout << endl;
	i.Increment(h);
	i.Output(); cout << endl;
	j = i.Add(g).Add(h);
	j.Output(); cout << endl;
	j = i.Increment(g).Add(h);
	j.Output(); cout << endl;
	i.Output(); cout << endl;
	return -1;
}

