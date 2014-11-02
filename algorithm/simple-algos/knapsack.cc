/* 0-1 knapsack */
/* implemented by L.J. in Oct.30, 2013 */
#include <iostream>
#include <algorithm>
using namespace std;

const int kN=10; //k means const
const int kV=10;

struct node
{
  int volume; 
  int value;
}g_item[kN]; //global variable starting with g_

int g_s[kV+1] = {0}; 

void ZeroOnePack(int cost, int kV, int weight)
{
  for(int v=kV; v>=cost; --v)
  {
    g_s[v] = max(g_s[v], g_s[v-cost] + weight);
  }
}


int main()
{
  int n, i, j, last, ret;
  while(cin >> n)
  {
    ret = 0;
    memset(g_s, 0, sizeof(g_s)); // set s[n] to 0s
    for(i=0; i<n; ++i)
	{
	  g_item[i].volume = rand() % kV;
	  g_item[i].value = rand() % kN;
	}

	for(i=0; i<n; ++i)
	{ 
	  cout << "volume:" << g_item[i].volume << " value:" 
	       << g_item[i].value << endl; 
	  ZeroOnePack(g_item[i].volume, kV, g_item[i].value);
	}

	for(i=0; i<=kV; ++i)
	{
	  if(g_s[i] > ret)
	    ret = g_s[i];
	}
	cout << "Optimal value: " << ret << endl;
  }
  return 0;
}
