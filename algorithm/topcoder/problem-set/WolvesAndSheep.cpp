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
class WolvesAndSheep
{
public:
int getmin(vector <string> field)
{
  int n = field.size();
  vector<bool> row(n-1, false); 
  vector<bool> col(n-1, false); 
  int count(0);

  for(size_t i=0; i<n; ++i)
  {
    for(size_t j=0; j<field[i].size(); ++j)
    {
      if(field[i][j] == 'S')
      {
        //left
        if(i>0 && field[i][j] == "W"){
          if(row == false){
            row[i] =true;
            ++ count;
          }
        }
        //right
        if(i<n && field[i][j] == "W"){
          if(row == false){
            row[i] =true;
            ++ count;
          }
        }

      }
    }
  }
  return int(count) ;
}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"W.WSS",
 "WW.S.",
 ".SSS.",
 "SSS.S",
 ".SS.S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arr0[] = {".....",
 ".....",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arr0[] = {".SS",
 "...",
 "S..",
 "W.W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arr0[] = {"WWWSWWSSWWW",
 "WWSWW.SSWWW",
 "WS.WSWWWWS."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arr0[] = {".W.S.W.W",
 "W.W.S.W.",
 ".S.S.W.W",
 "S.S.S.W.",
 ".S.W.W.S",
 "S.S.W.W.",
 ".W.W.W.S",
 "W.W.S.S."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arr0[] = {"W.SSWWSSSW.SS",
 ".SSSSW.SSWWWW",
 ".WWWWS.WSSWWS",
 "SS.WSS..W.WWS",
 "WSSS.SSWS.W.S",
 "WSS.WS...WWWS",
 "S.WW.S.SWWWSW",
 "WSSSS.SSW...S",
 "S.WWSW.WWSWSW",
 ".WSSS.WWSWWWS",
 "..SSSS.WWWSSS",
 "SSWSWWS.W.SSW",
 "S.WSWS..WSSS.",
 "WS....W..WSS."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(5, Arg1, getmin(Arg0)); }
	void test_case_6() { string Arr0[] = {"WW..SS",
 "WW..SS",
 "......",
 "......",
 "SS..WW",
 "SS..WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(6, Arg1, getmin(Arg0)); }

// END CUT HERE

};// BEGIN CUT HERE
int main(){
WolvesAndSheep ___test;
___test.run_test(-1);
//getch() ;
return 0;
}
// END CUT HERE 
