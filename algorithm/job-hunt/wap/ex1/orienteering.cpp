// copyright @ L.J.SHOU May.26, 2014
#include <bits/stdc++.h>
using namespace std;

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
            if(!flag1) flag1 = true;
            else return false;
          }
          else if(map[i][j] == 'G') {
            new2old[20-1] = i * width + j;
            if(!flag2) flag2 = true;
            else return false;
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
    
    // bfs from s and g
    bfs(new2old[0]/width, new2old[0]%width);
    bfs(new2old[count-1]/width, new2old[count-1]%width);

    bool reachable = false;
    for(int j=1; j<count; ++j) {
      if(distance[0][j] != MAX_DISTANCE) {
        reachable = true;
        break;
      }
    }

    /*
    cout << "distance: " << endl;
    for(int i=0; i<count; ++i)
    {
      for(int j=0; j<count; ++j)
        cout << distance[i][j] << " ";
      cout << endl;
    }
    cout << endl;
    */
    return reachable;
  }

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
        if(map[i][j-1] == '@') {
          distance[s][old2new[i*width + j-1]] = step;
          distance[old2new[i*width + j-1]][s] = step;
        }
        else { // G and .
            next.push(std::make_pair(i, j-1));
        }
      }
      //right
      if(j+1 < width && map[i][j+1] != '#' && !visited[i][j+1]) {
        visited[i][j+1] = true; //visited
        if(map[i][j+1] == '@') {
          distance[s][old2new[i*width + j+1]] = step;
          distance[old2new[i*width + j+1]][s] = step;
        }
        else {
            next.push(std::make_pair(i, j+1));
        }
      }
      //up
      if(i-1 >= 0 && map[i-1][j] != '#' && !visited[i-1][j]) {
        visited[i-1][j] = true; //visited
        if(map[i-1][j] == '@') {
          distance[s][old2new[(i-1)*width + j]] = step;
          distance[old2new[(i-1)*width + j]][s] = step;
        }
        else {
            next.push(std::make_pair(i-1, j));
        }
      } 
      //down
      if(i+1 < height && map[i+1][j] != '#' && !visited[i+1][j]) {
        visited[i+1][j] = true; //visited
        if(map[i+1][j] == '@') {
          distance[s][old2new[(i+1)*width + j]] = step;
          distance[old2new[(i+1)*width + j]][s] = step;
        }
        else {
            next.push(std::make_pair(i+1, j));
        }
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
    vector<vector<long long> > f(n+2, vector<long long>(1 << n, MAX_DISTANCE));

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

void minDistance2()
{
  long long dis(MAX_DISTANCE);
  for(int i=1; i<count-1; ++i)
  {
    if(distance[0][i] != MAX_DISTANCE && distance[i][count-1] != MAX_DISTANCE)
      dis = min(dis, distance[0][i] + distance[i][count-1]);
  }
  if(dis != MAX_DISTANCE) cout << dis << endl;
  else cout << "-1" << endl;
}
};


void Orienteering::main() {
    if(!PreProcess()) {
      std::cout << -1 << std::endl;
      return;
    }
    minDistance2();
}

int main(int argc, char* argv[])
{
  Orienteering o;
  o.main();
  return 0;
}
