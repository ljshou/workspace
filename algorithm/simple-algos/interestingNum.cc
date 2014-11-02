/**
 * @file interestingNum.cc
 * @brief interesting number
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-11
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class InterestingNumber
{
public:
  string isInteresting(string x)
  {
    const size_t n = x.length();
    if(n % 2 != 0) 
      return string("Not interesting");
    bool a[n];
    for(size_t i=0; i!=n; ++i)
      a[i] = true;

    for(size_t i=0; i!=n; ++i)
    {
      if(a[i]){
        if(i+x[i]-'0'+1 >= n || a[i+x[i]-'0'+1] == false || a[i] != a[i+x[i]-'0'+1])
          return string("Not interesting");
        a[i] = a[i+x[i]-'0'+1] = false;
      }
    }
    return string("Interesting");
  }
};

int main(void)
{
  string str("631413164");

  InterestingNumber num;
  cout << num.isInteresting(str) << endl;

  return 0;
}
