// copyright @ L.J.SHOU Dec.03, 2013
// reverse a string
#include <cstring>
#include <iostream>
using namespace std;

void Reverse(char *str)
{
  for(int i=0, j=strlen(str)-1; i<j; ++i, --j)
    swap(str[i], str[j]);
}

void Reverse2(char *str)
{
  char *end(str);
  char temp;
  if(str)
  {
    while(*end)
	  end++;
  }
  end--;
  while(str < end)
  {
    temp = *str;
	*str++ = *end;
	*end-- = temp;
  }
}

int main(void)
{
  char str[] = "shoulinjun";
  Reverse2(str);
  for(int i=0; i<strlen(str); ++i)
    cout << str[i] << " ";
  cout << endl;
  return 0;
}
