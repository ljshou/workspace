/**
 * @file glip-game.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-28
 */

#include <iostream>
#include <queue>
using namespace std;

#define MAX 65535
#define For(i, n) for(int i=0; i<(n); ++i)

bool visited[MAX];
int step[MAX];

void Solve() 
{
  char c;
  int id = 0;
  For(i, 4) {
    For(j, 4) {
      cin >> c;
      id <<= 1;
      if(c == 'b') id |= 1;
    }
  }
  if(id == 0 || id == MAX) {
    cout << 0 << endl;
    return;
  }

  //BFS
  queue<int> cur, next;
  int count = 1, temp;
  cur.push(id); visited[id] = true; step[id] = 0;
  while(!cur.empty()) {
    id = cur.front(); cur.pop();
    temp = id;
    For(i, 4) {
      For(j, 4) {
        //16 cases
        id = temp;
        int index = 15 - i*4 - j;
        id ^= 1 << (index);
        if(i == 0) {
          id ^= 1 << (index-4);
        }
        else if(i == 3){
          id ^= 1 << (index+4);
        }
        else {
          id ^= 1 << (index-4);
          id ^= 1 << (index+4);
        }

        if(j == 0) {
          id ^= 1 << (index-1);
        }
        else if(j == 3) {
          id ^= 1 << (index+1);
        }
        else {
          id ^= 1 << (index-1);
          id ^= 1 << (index+1);
        }

        if(visited[id]) continue;
        next.push(id); visited[id] = true;
        step[id] = count;
        if(id == 0 || id == MAX) {
          cout << count << endl;
          return;
        }
      }
    }
    if(cur.empty()) {
      swap(cur, next);
      ++ count;
    }
  }
  cout << "Impossible" << endl;
}

int main(void)
{
  Solve();
  return 0;
}
