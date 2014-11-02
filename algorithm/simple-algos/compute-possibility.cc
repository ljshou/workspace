/**
 * @file compute-possibility.cc
 * @brief 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-07
 */

#include <iostream>
using namespace std;

//number[i]表示和为i的数目
int number[100];

void dfs(int cur, int count, int sum, int n)
{
  if(count == 8){
    ++ number[sum];
    return;
  }
  else if(cur > n){
    return;
  }
  //5种选择
  dfs(cur+1, count, sum, n);
  dfs(cur+1, count+1, sum+cur, n);
  dfs(cur+1, count+2, sum+2*cur, n);
  dfs(cur+1, count+3, sum+3*cur, n);
  dfs(cur+1, count+4, sum+4*cur, n);
}

int main(void)
{
  dfs(1, 0, 0, 13);
  for(int i=12; i<=100; ++i)
  {
    cout << i << " " << number[i] << endl;
  }

  return 0;
}
