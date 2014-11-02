#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;
class SlimeXSlimonadeTycoon
{
public:
int sell(vector <int> morning, vector <int> customers, int stale_limit)
{
  if(morning.empty()) return 0;

  int que[100000];
  int front = 0, rear = 0;
  int count(0);
  for(int i=0; i<morning.size(); ++i)
  {
    if(front - rear == stale_limit) ++rear;
    que[front++] = morning[i];

    while(rear < front && customers[i] > 0)
    {
      if(que[rear] > customers[i]){
        count += customers[i];
        que[rear] -= customers[i];
        break;
      }
      else{
        count += que[rear];
        customers[i] -= que[rear];
        ++rear;
      }
    }
  }
return int(count) ;
}
};

