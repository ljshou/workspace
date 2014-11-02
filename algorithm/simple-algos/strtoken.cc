/**
 * @file strtoken.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-09-02
 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  char str[] = "129.1.1.1";

  char *p = strtok(str, ".");
  while(p != NULL) {
    cout << p << endl;
    p = strtok(NULL, ".");
  }
  return 0;
}
