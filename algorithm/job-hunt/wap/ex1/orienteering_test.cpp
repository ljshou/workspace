#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <utility>
#include <fstream>
#include <cassert>
#include <climits>
using namespace std;

class Orienteering {
public:
  void main();
private:
  int count; // num of (S, @, G)
  map<int, int> old2new;
  int new2old[20];
  int distance[20][20]; // new map

  /**
   * compute all the shortest path between arbitrary two nodes in (S, @, G)
   * convert the old map to a new map
   * return false, if there exists no solution
   */
  bool PreProcess(int &width, int &height, char map[][100]) 
  {
    // input and record [S, @, G]
    ifstream ifile("ex1_examples.txt");

    int num;
    ifile >> num;
    for(int i=0; i<num; ++i)
    {
      old2new.clear();
      ifile >> width >> height;
      assert(1 <= width && width <= 100);
      assert(1 <= height && height <= 100);

      int new_index(1); //index of @
      bool flag1(false), flag2(false);
      count = 0;

      for(int i=0; i<height; ++i)
      {
        for(int j=0; j<width; ++j)
        {
          ifile >> map[i][j];
          if(map[i][j] != '#' && map[i][j] != '.') 
          {
            ++ count;
            if(map[i][j] == '@') {
              old2new[i*width+j] = new_index;
              new2old[new_index++] = i*width + j;
            }
            else if(map[i][j] == 'S') {
              old2new[i*width+j] = 0;
              new2old[0] = i * width + j;
              flag1 = true;
            }
            else {
              new2old[20-1] = i * width + j;
              flag2 = true;
            }
          }
        }
      }

      if(count > 20 || !(flag1 && flag2)) {
        cout <<  -1 << endl;
        continue;
      }
      new2old[count-1] = new2old[20-1];
      old2new[new2old[count-1]] = count-1;

      assert(old2new.size() == count);

      // compute distance 
      // bfs from every [S,@,G] node
      fill_n(&distance[0][0], 20*20, INT_MAX);

      for(int i=0; i<count; ++i)
        bfs(new2old[i]/width, new2old[i]%width, map, width, height);

      bool flag(false);
      for(int j=1; j<count; ++j) {
        if(distance[0][j] == INT_MAX)
        {
          flag = true;
          break;
        }
      }
      if(flag) {
        cout << -1 << endl;
        continue;
      }

      MinDistance();
   }
   ifile.close();
}

  //bfs from source map[i][j] to compute distance to [s, @, G]
  void bfs(int i, int j, char map[][100], int width, int height)
  {
    queue<pair<int, int> > cur, next;
    int s = old2new[i * width + j];
    int step(1);

    bool visited[100][100] = {false};
    cur.push(make_pair(i, j));
    distance[s][s] = 0;
    visited[i][j] = true; //visited
    while(!cur.empty())
    {
      i = cur.front().first; j = cur.front().second; cur.pop();
      //left
      if(j-1 >= 0 && map[i][j-1] != '#' && !visited[i][j-1]) {
        if(map[i][j-1] != '.') distance[s][old2new[i*width + j-1]] = step;
        next.push(make_pair(i, j-1));
        visited[i][j-1] = true; //visited
      }
      //right
      if(j+1 < width && map[i][j+1] != '#' && !visited[i][j+1]) {
        if(map[i][j+1] != '.') distance[s][old2new[i*width + j+1]] = step;
        next.push(make_pair(i, j+1));
        visited[i][j+1] = true; //visited
      }
      //up
      if(i-1 >= 0 && map[i-1][j] != '#' && !visited[i-1][j]) {
        if(map[i-1][j] != '.') distance[s][old2new[(i-1)*width + j]] = step;
        next.push(make_pair(i-1, j));
        visited[i-1][j] = true; //visited
      } 
      //down
      if(i+1 < height && map[i+1][j] != '#' && !visited[i+1][j]) {
        if(map[i+1][j] != '.') distance[s][old2new[(i+1)*width + j]] = step;
        next.push(make_pair(i+1, j));
        visited[i+1][j] = true; //visited
      }
      
      if(cur.empty()) {
        cur.swap(next);
        ++ step;
      }
    }
  }

  void MinDistance()
  {
    const int n = count-2;
    int f[n+2][1 << n];
    fill_n(&f[0][0], (n+2)*(1 << n), 0xffffff);

    f[0][0] = 0;
    for(int j=0; j<(1 << n); ++j)
    {
      for(int i=0; i<count; ++i)
      {
        for(int k=0; k<n; ++k)
        {
          if(j & (1 << k)) {
            f[i][j] = min(f[i][j], f[k+1][j & ~(1 << k)] + distance[i][k+1]);
          }
        }
        f[i][j] = min(f[i][j], f[0][j] + distance[i][0]); //S
        f[i][j] = min(f[i][j], f[count-1][j] + distance[i][count-1]); //G
      }
    }

    cout << f[count-1][(1 << n) - 1] << endl;
  }
};

void Orienteering::main() {
  int width(0), height(0);
  char map[100][100];

  // convert old map to new map
  if(!PreProcess(width, height, map)) {
    return;
  }
  // DP in new map
  //MinDistance();
}



int main(int argc, char* argv[])
{
  Orienteering o;
  clock_t start = clock();
  o.main();
  clock_t end = clock();
  cout << end - start << endl;
  return 0;
}
