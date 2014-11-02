#include <bits/stdc++.h>
using namespace std;

class Orienteering {
public:
  void main();
private:
  typedef long long ll;

  void MinDistance()
  {
      int n, m;
      cin>>m>>n;
      vector<string> _mp(n);
      for (int i = 0; i < n; ++i) cin>>_mp[i];
      vector< vector<int> > mp(n, vector<int>(m));
      int num_route = 0;
      tuple<int, int, int> begin, end;
      for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (_mp[i][j] == '.') mp[i][j] = -1;
        else if(_mp[i][j] == '#') mp[i][j] = -2;
        else { 
          mp[i][j] = num_route++;
          if (_mp[i][j] == 'S') begin = make_tuple(i, j, 1<<(num_route - 1));
          else if (_mp[i][j] == 'G') end = make_tuple(i, j, 0);
        }
      }
      if(num_route > 20) {
        cout << -1 << endl;
        return;
      }
      get<2>(end) = (1<<num_route) - 1;
    
      auto hash = [&n, &m] (const tuple<int, int, int>& state)->ll {
          ll i, j, s;
          tie(i, j, s) = state;
          return (s<<20) + i * m + j;
      };
      queue< tuple<int, int, int> > q;

      unordered_map<ll, int> dist;
      unordered_map<ll, tuple<int, int, int> > pre_state;

      q.push(begin);
      dist[hash(begin)] = 0;


      int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
      bool find = false;
      while (!q.empty() && !find) {
        int cur_i, cur_j, cur_s;
        tie(cur_i, cur_j, cur_s) = q.front();
        auto cur_hash = hash(q.front());
        q.pop();

        for (int k = 0; k < 4; ++k) {
          int next_i = cur_i + d[k][0];
          int next_j = cur_j + d[k][1];

          if (0 <= next_i && next_i < n && 0 <= next_j && next_j < m && mp[next_i][next_j] != -2) 
          {
            int next_s = cur_s; 
            if (mp[next_i][next_j] >= 0) {
                next_s |= (1<<mp[next_i][next_j]);
            }

            auto next_state = make_tuple(next_i, next_j, next_s);
            auto next_hash = hash(next_state);
            if (!dist.count(next_hash)) {
              dist[next_hash] = dist[cur_hash] + 1;
                
              pre_state[next_hash] = make_tuple(cur_i, cur_j, cur_s);

              if (next_state == end)
                find = true;

              q.push(next_state);
            }
          }
        }
      }

      auto end_hash = hash(end);
      cout<<(dist.count(end_hash) ? dist[end_hash] : -1)<<endl;

      auto to_bstr = [&num_route](int val) {
            string s(num_route, '0');
            int i = 0;
            while (val) {
            s[i++] = '0' + (val&1);
             val >>= 1;
          }
        return s;
      };

      /*
      tuple<int, int, int> state = end;
      while (state != begin) {
        int i, j, s;
        tie(i, j, s) = state;
        printf("(%d, %d, %s)\n", i, j, to_bstr(s).c_str());
        state = pre_state[hash(state)];
      }*/
   }
};


void Orienteering::main() {
  MinDistance();
}



int main(int argc, char* argv[])
{
  Orienteering o;
  o.main();
  return 0;
}
