// copyright @ L.J.SHOU May.26, 2014
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <utility>
#include <cassert>
#include <ctime>
#include <cstring>

class Orienteering {
public:
  void main();
private:
  char  map[100][100];
  int height, width;
  const long long MAX_DISTANCE = 0xffffffff;

  int count; // num of (S, @, G)
  std::unordered_map<int, int> old2new;
  int new2old[20];
  long long distance[20][20]; // new map
  bool visited[100][100];

  /**
   * compute all the shortest path between arbitrary two nodes in (S, @, G)
   * convert the old map to a new map
   * return false, if there exists no solution
   */
  bool PreProcess()
  {
    // input and record [S, @, G]
    old2new.clear();
    std::cin >> width >> height;
    if(width < 1 || width > 100 || height < 1 || height > 100)
      return false;

    int new_index(1); //index of @
    bool flag1(false), flag2(false);
    count = 0;

    for(int i=0; i<height; ++i)
    {
      for(int j=0; j<width; ++j)
      {
        std::cin >> map[i][j];
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
          else if(map[i][j] == 'G') {
            new2old[20-1] = i * width + j;
            flag2 = true;
          }
          else {
            // invalid charactor
            return false;
          }
        }
      }
    }
    if(count > 20 || !(flag1 && flag2)) {
      return false;
    }
    new2old[count-1] = new2old[20-1];
    old2new[new2old[count-1]] = count-1;
    assert(old2new.size() == count);

    // compute distance 
    // bfs from every [S,@,G] node
    std::fill_n(&distance[0][0], 20*20, MAX_DISTANCE);
    for(int i=0; i<count; ++i)
      bfs(new2old[i]/width, new2old[i]%width);

    bool reachable = true;
    for(int j=1; j<count; ++j) {
      if(distance[0][j] == MAX_DISTANCE) {
        reachable = false;
        break;
      }
    }
    return reachable;
  }

  //bfs from source map[i][j] to compute distance to [s, @, G]
  void bfs(int i, int j)
  {
    std::queue<std::pair<int, int> > cur, next;
    int s = old2new[i * width + j];
    long long step(1);

    std::fill_n(&visited[0][0], 100*100, false);

    cur.push(std::make_pair(i, j));
    distance[s][s] = 0;
    visited[i][j] = true; //visited

    while(!cur.empty())
    {
      i = cur.front().first; j = cur.front().second; cur.pop();
      //left
      if(j-1 >= 0 && map[i][j-1] != '#' && !visited[i][j-1]) {
        visited[i][j-1] = true; //visited
        if(map[i][j-1] != '.') {
          distance[s][old2new[i*width + j-1]] = step;
        }
        next.push(std::make_pair(i, j-1));
      }
      //right
      if(j+1 < width && map[i][j+1] != '#' && !visited[i][j+1]) {
        visited[i][j+1] = true; //visited
        if(map[i][j+1] != '.') {
          distance[s][old2new[i*width + j+1]] = step;
        }
        next.push(std::make_pair(i, j+1));
      }
      //up
      if(i-1 >= 0 && map[i-1][j] != '#' && !visited[i-1][j]) {
        visited[i-1][j] = true; //visited
        if(map[i-1][j] != '.') {
          distance[s][old2new[(i-1)*width + j]] = step;
        }
        next.push(std::make_pair(i-1, j));
      } 
      //down
      if(i+1 < height && map[i+1][j] != '#' && !visited[i+1][j]) {
        visited[i+1][j] = true; //visited
        if(map[i+1][j] != '.') {
          distance[s][old2new[(i+1)*width + j]] = step;
        }
        next.push(std::make_pair(i+1, j));
      }
      
      if(cur.empty()) {
        cur.swap(next);
        ++ step;
      }
    }
  }

  void minDistance()
  {
    const int n = count-2;
    long long f[n+2][1 << n];
    std::fill_n(&f[0][0], (n+2)*(1 << n), MAX_DISTANCE);

    f[0][0] = 0;
    for(int j=0; j<(1 << n); ++j)
    {
      for(int i=0; i<count; ++i)
      {
        for(int k=0; k<n; ++k)
        {
          if(j & (1 << k)) {
            f[i][j] = std::min(f[i][j], f[k+1][j & ~(1 << k)] + distance[i][k+1]);
          }
        }
        f[i][j] = std::min(f[i][j], f[0][j] + distance[i][0]); //S
        f[i][j] = std::min(f[i][j], f[count-1][j] + distance[i][count-1]); //G
      }
    }

    std::cout << f[count-1][(1 << n) - 1] << std::endl;
  }
};

void Orienteering::main() {
    if(!PreProcess()) {
      std::cout << -1 << std::endl;
      return;
    }
    minDistance();
}

/*
int main(int argc, char* argv[])
{
  Orienteering o;

  clock_t start = clock();
  int cas;
  std::cin>>cas;
  for (int i = 1; i <= cas; ++i) {
    o.main();
  }
  clock_t end = clock();

  std::cout << end - start << std::endl;
  return 0;
}
*/
