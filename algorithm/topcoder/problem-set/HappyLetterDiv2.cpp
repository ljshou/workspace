// BEGIN CUT HERE

//#include <conio.h>
#include <sstream>
/*
*/
#define debuging
#ifdef debuging
#define FIN  {freopen("new.in" , "r" , stdin) ;}
#define FOUT {freopen("new.out" , "w" , stdout) ;}
#define OUT(x)  {cout<< #x << "  : " << x <<endl ;}
#define ERR(x)  {cout<<"#error: "<< x ; while(1) ;}
#endif
// END CUT HERE
#ifndef debuging
#define FIN  ;
#define FOUT ;
#define OUT(x)  ;
#define ERR(x)  ;
#endif
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class HappyLetterDiv2
{
public:
  char getHappyLetter(string s)
  {
    if(s.empty()) return '.';
    int w[26] = {0};
    for(auto x : s) ++w[x-'a'];
    for(int i=0; i<26; ++i) {
      if(w[i] > s.size()/2) return 'a'+i;
    }
    return '.';
  }


  /*
  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const char &Expected, const char &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "aacaaa"; char Arg1 = 'a'; verify_case(0, Arg1, getHappyLetter(Arg0)); }
  void test_case_1() { string Arg0 = "dcdjx"; char Arg1 = '.'; verify_case(1, Arg1, getHappyLetter(Arg0)); }
  void test_case_2() { string Arg0 = "bcbbbbba"; char Arg1 = 'b'; verify_case(2, Arg1, getHappyLetter(Arg0)); }
  void test_case_3() { string Arg0 = "aabc"; char Arg1 = '.'; verify_case(3, Arg1, getHappyLetter(Arg0)); }

  // END CUT HERE
  */

};// BEGIN CUT HERE
/*
int main(){
  HappyLetterDiv2 ___test;
  ___test.run_test(-1);
  //getch() ;
  return 0;
}
// END CUT HERE 
*/
