/**
 * @file 2965.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-28
 */

#include <iostream>
#include <queue>
#define MAX 65535
#define For(i, n) for(int i=0; i<(n); ++i)
using namespace std;

bool visited[MAX];
pair<int, int> father[MAX];
int s;

//backtrack from 0 to s
void Path()
{
  vector<int> path;
  int t = 0;
  while(t != s) {
    path.push_back(father[t].second);
    t = father[t].first;
  }
  for(vector<int>::reverse_iterator it= path.rbegin(); it!=path.rend(); ++it) {
    cout << *it / 4 + 1 << " " << *it%4 + 1 << endl;
  }
}

void solve() 
{
  s = 0;
  char c;
  For(i, 4)
    For(j, 4)
    {
      cin >> c;
      s <<= 1;
      if(c == '+') s += 1;
    }
  int x = 0;
  For(i, 16) {
    x <<= 1;
    if(s &0x1) x += 1;
    s >>= 1;
  }
  s = x;
  if(s == 0) {
    cout << 0 << endl;
    return;
  }

  //BFS
  int count = 1;
  int id, temp;
  queue<int> cur, next;
  cur.push(s); visited[s] = true;
  while(!cur.empty()) {
    id = cur.front(); cur.pop();
    For(i, 4) {
      For(j, 4) {
        temp = id;
        //flip (i, j)
        temp ^= 1 << (i*4 + j);
        For(k, 4) temp ^= 1 << (i*4 + k);
        For(k, 4) temp ^= 1 << (k*4 + j);
        if(!visited[temp]) {
          father[temp] = make_pair(id, i*4+j);
          visited[temp] = true;
          next.push(temp);
        }
        if(temp == 0) {
          cout << count << endl;
          Path();
          return;
        }
      }
    }
          
    if(cur.empty()) {
      ++count;
      swap(cur, next);
    }
  }

}

int main(void)
{
  solve();
  return 0;
}
