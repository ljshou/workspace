/* copyright @ L.J.SHOU Nov.28, 2013
   check the system: Big-endian or Little-endian
*/
#include <iostream>
using namespace std;

int CheckSystem(void)
{
  union Check
  {
    char ch;
	int i;
  }c;
  c.i = 1;
  return (c.ch == 1);
}

int main(void)
{
  int flag;
  flag = CheckSystem();
  if(flag == 1)
  {
    cout << "System is Little-endian" << endl;
  }
  else
  {
    cout << "System is Big-endian" << endl;
  }
  return 0;
}
