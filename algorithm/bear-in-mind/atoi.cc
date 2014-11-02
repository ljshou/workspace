//copyright @ L.J.SHOU Dec.2rd, 2013
//type num: 2 
#include <iostream>
#include <climits>
using namespace std;

int atoi(char const *str)
{
  int value(0), n, neg(0);
	while(isspace(*str)) ++str; //skip whitespaces
	if(*str == '+') ++str;
	else if(*str == '-'){
	  neg = 1;
		++str;
	}
	while(isdigit(*str))
	{
	  n = *(str++) - '0';
	  if(value > INT_MAX/10 || (value == INT_MAX/10 && n > INT_MAX%10))
	    return neg?INT_MIN:INT_MAX;
	  value = value * 10 + n;
	}
	return neg?-value:value;
}

int main()
{
  char const *s="-2147483647";
  cout << atoi(s) << endl;
  return 0;
}
