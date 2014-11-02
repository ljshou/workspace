// copyright @ L.J.SHOU Dec.03, 2013
// replace space with '%02'
#include <iostream>
using namespace std;

int DeleteSpace(char *str, int length)
{
  int num_of_space(0), new_length, i, j;
  //count # of spaces
  for(i=0; i<length; ++i)
    if(str[i] == ' ')
	  ++ num_of_space;
  new_length = length + 2*num_of_space;
  str[new_length] = '\0';

  i = new_length -1;
  j = length - 1;
  while(i>=0)
  {
    if(str[j] != ' ')
	  str[i--] = str[j--];
	else
	{
	  str[i--]='0'; str[i--]='2'; str[i--]='%';
	  j--;
	}
  }
  return new_length;
}

int main(void)
{ 
  int length(13);
  char str[100]={'M','r',' ','J','o','h','n',' ','S','m','i','t','h', '\0'};
  cout << str << endl;

  length = DeleteSpace(str, 13);
  cout << str << endl;
  return 0;
}
