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
class BubbleSortWithReversals
{
public:
int getMinSwaps(vector <int> A, int K)
{
  if(A.empty()) return 0;

  const int n = A.size();
  int f[51][51] = {INT_MAX};
  for(int i=0; i<=K; ++i)
    f[n][i] = 0; //initialization

  for(int i=n-1; i>=0; --i) {
    for(int k=0; k<=K; ++k) {
      //case 1: do not reverse A[i]
      vector<int> B(A.begin(), A.begin() + i + 1);
      f[i][k] = f[i+1][k] + CountInversions(B, i);

      //case 2: reverse [A[i], ..., A[j]]
      if(k > 0) {
        for(int j=i; j<n; ++j) {
          vector<int> B(A.begin(), A.begin() + j + 1);
          reverse(B.begin()+i, B.end());
          f[i][k] = min(f[i][k], f[j+1][k-1] + CountInversions(B, i));
        }
      }
    }
  }

  return f[0][K];
}

private:
  int CountInversions(vector<int> &B, int x) {
    int c(0);
    for(int i=x; i<B.size(); ++i) {
      for(int j=0; j<i; ++j) {
        if(B[j] > B[i]) ++c;
      }
    }
    return c;
  }

/*
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,8,8,7,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(0, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {7,2,2,13,5,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {12,5,1,10,12,6,6,10,6,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 12; verify_case(2, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(3, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {482,619,619,601,660,660,691,691,77,77,96,77}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 22; verify_case(4, Arg2, getMinSwaps(Arg0, Arg1)); }

// END CUT HERE
*/
};// BEGIN CUT HERE
/*
int main(){
BubbleSortWithReversals ___test;
___test.run_test(-1);
//getch() ;
return 0;
}
*/
// END CUT HERE 
