#include<iostream>
#include<string>
using namespace std;

//string::size_type find_char(string &s, char &c)  //这样有错
string::size_type find_char(const string &s, const char &c)
{
	string::size_type i=0;
	while(i != s.size() && s[i] != c)
		++i;
	return i;
}
int main()
{
	if(find_char("Hello world", 'c'))
		cout<<" character found!"<<endl;
	return 0;
}

