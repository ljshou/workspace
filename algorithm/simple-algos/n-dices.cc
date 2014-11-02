/**
 * @file n-dices.cc
 * @brief  
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-10-09
 */

#include <bits/stdc++.h>
using namespace std;

// 滚动数组的思想
void PrintProbability(int number)
{
  if(number < 1)
    return;
  vector<int> prob(1+6*number, 0);

  for(int i=1; i<=6; ++i)
    prob[i] = 1;

  for(int i=2; i<=number; ++i)
  {
    for(int j=6*i; j>=i; --j) 
    {
      prob[j] = 0;

      for(int k=1; k<=6 && k<=j; ++k)
        prob[j] += prob[j-k];
    }
    for(int j=i-1; j>=0; --j)
      prob[j] = 0;
  }

  copy(prob.begin(), prob.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

void PrintProbability2(int number)
{
  if(number < 1)
    return;
  vector<int> prob[2];
  prob[0].resize(1+6*number, 0);
  prob[1].resize(1+6*number, 0);

  int flag = 0;
  for(int i=1; i<=6; ++i)
    prob[flag][i] = 1;

  for(int k=2; k<=number; ++k)
  {
    for(int i=0; i<k; ++i)
      prob[1-flag][i] = 0;

    for(int i=k; i<=6*k; ++i) 
    {
      prob[1-flag][i] = 0;
      for(int j=1; j<=6 && j<=i; ++j)
        prob[1-flag][i] += prob[flag][i-j];
    }
    flag = 1 - flag;
  }

  copy(prob[flag].begin(), prob[flag].end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main(void)
{
  int n;
  cin >> n;
  PrintProbability(n);
  PrintProbability2(n);

  return 0;
}
