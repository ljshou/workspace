/**
 * @file 2.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-18
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int g_s[100000] = {0}; 

void ZeroOnePack(int cost, int kV, int weight)
{
  for(int v=kV; v>=cost; --v)
  {
    g_s[v] = max(g_s[v], g_s[v-cost] + weight);
  }
}


int main(void)
{
  int N, V;
  int volume, value;
  cin >> N >> V;
  for(int i=0; i<N; ++i)
  { 
    cin >> volume >> value;
    ZeroOnePack(volume, V, value);
  }
  cout << *max_element(g_s, g_s+V) << endl;

  return 0;
}
