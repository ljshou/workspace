#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
   vector<string> svec;
   string word;
   svec.push_back("shou");
   svec.push_back("hello");
   while(cin >> word, cin.eof())
   	svec.push_back(word);
   for(vector<string>::iterator iter = svec.begin(); iter != svec.end(); ++iter)
   	cout << *iter << ' ';
   cout << endl;
   return 0;
}
   

