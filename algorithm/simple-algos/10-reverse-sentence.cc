// copyright @ L.J.SHOU Mar.04,2014
// "I am a student" ---->  "student. a am I"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

void reverse(string::iterator first, string::iterator last)
{
  while(first < last){
    swap(*first++, *--last);
  }
}

void reverseSentence(string& str)
{
  string::iterator it = str.begin();
  //reverse words
  while(it != str.end())
  {
	// boundary check
	while(it !=str.end() && *it == ' ') // skip white spaces
	  ++ it;
	string::iterator left = it;
	while(it != str.end() && *it != ' ' )
	  ++ it;

	reverse(left, it);
  }

  reverse(str.begin(), str.end());
}

int main(void)
{
  string str("  I am a student.   ");
  reverseSentence(str);
  cout << str << endl;

  return 0;
}
