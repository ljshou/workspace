/**
 * @file death-island.cc
 * @brief death island
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-22
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

#define For(i, n) for(int i=0; i<(n); ++i)

const int MAX = 10000;
const double epshion = 1e-10;
double f[MAX][MAX][MAX];

double dfs(int x, int y, int N, int n)
{
    if(x < 0 || x >= N || y < 0 || y >= N)
        return 1.0; //die
    if(n == 0) return 0.0; //survive
    if(f[x][y][n] >= -1*epshion) return f[x][y][n];

    f[x][y][n] = 0;
    f[x][y][n] += dfs(x-1, y, N, n-1);
    f[x][y][n] += dfs(x+1, y, N, n-1);
    f[x][y][n] += dfs(x, y-1, N, n-1);
    f[x][y][n] += dfs(x, y+1, N, n-1);
    f[x][y][n] /= 4;

    return f[x][y][n];
}

double SurvivePossibility(int N, int steps, int x, int y)
{
    //initialization
    For(i, N) {
        For(j, N) {
            For(k, steps+1) {
                f[i][j][k] = -1;
            }
        }
    }
    return dfs(x, y, N, steps);
}

void Test()
{
    assert(SurvivePossibility(1, 1, 0, 0) == 1.0);
    assert(SurvivePossibility(2, 1, 0, 0) == 0.5);
    assert(SurvivePossibility(2, 2, 0, 0) == 0.75);
}

int main(void)
{
    Test();
    return 0;
}
