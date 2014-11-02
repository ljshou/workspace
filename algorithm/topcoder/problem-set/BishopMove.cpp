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
#include <bits/stdc++.h>
using namespace std ;
#define For(i , n) for(int i = 0 ; i < (n) ; ++i)
#define SZ(x)  (int)((x).size())
typedef long long lint ;
const int maxint = -1u>>2 ;
const double eps = 1e-6 ; 
class BishopMove
{
public:
int howManyMoves(int r1, int c1, int r2, int c2)
{
  int x = abs(r2 - r1);
  int y = abs(c2 - c1);
  if(x == 0 && y == 0) return 0;
  if(x == y) return 1;
  if(((x+y) & 1) == 0) return 2;
  if((abs(x-y) & 1) == 0) return 2;
  return -1;
}


/*
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 7; int Arg3 = 3; int Arg4 = 1; verify_case(0, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 2; int Arg3 = 5; int Arg4 = 0; verify_case(1, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 5; int Arg3 = 5; int Arg4 = 2; verify_case(2, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 7; int Arg3 = 4; int Arg4 = -1; verify_case(3, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
*/
};// BEGIN CUT HERE
/*
int main(){
BishopMove ___test;
___test.run_test(-1);
//getch() ;
return 0;
}
// END CUT HERE 
*/
