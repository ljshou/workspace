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
class ConundrumReloaded
{
public:
int minimumLiars(string answers)
{
  if(answers.empty()) return 0;
  int res(-1);
  dfs(0, 0, true, true, answers, res);
  dfs(0, 0, false, false, answers, res);
  return res;
}
private:
void dfs(int cur, int count, bool curFlag, bool IniFlag, string &answers, int &res) {
  if(curFlag == false) ++count; //liar number
  if(res != -1 && count >= res) return;
  if(cur == answers.size()-1) {
    if(answers[cur] == '?') {
      res = res == -1 ? count : min(res, count);
      return;
    }
    if(curFlag) { //Honest
      if(answers[cur] == 'H') {
        if(IniFlag)
          res = res == -1 ? count : min(res, count);
      }
      else {
        if(!IniFlag) 
          res = res == -1 ? count : min(res, count);
      }
    }
    else {
      if(answers[cur] == 'H') {
        if(!IniFlag) 
          res = res == -1 ? count : min(res, count);
      }
      else {
        if(IniFlag) 
          res = res == -1 ? count : min(res, count);
      }

    }
    return;
  }

  if(answers[cur] == '?') {
    dfs(cur+1, count, true, IniFlag, answers, res);
    dfs(cur+1, count, false, IniFlag, answers, res);
  }
  else if(answers[cur] == 'L') {
    if(curFlag)
      dfs(cur+1, count, false, IniFlag, answers, res);
    else
      dfs(cur+1, count, true, IniFlag, answers, res);
  }
  else {
    if(curFlag)
      dfs(cur+1, count, true, IniFlag, answers, res);
    else
      dfs(cur+1, count, false, IniFlag, answers, res);
  }
}

/*
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLH"; int Arg1 = 1; verify_case(0, Arg1, minimumLiars(Arg0)); }
	void test_case_1() { string Arg0 = "?????"; int Arg1 = 0; verify_case(1, Arg1, minimumLiars(Arg0)); }
	void test_case_2() { string Arg0 = "LHLH?"; int Arg1 = 2; verify_case(2, Arg1, minimumLiars(Arg0)); }
	void test_case_3() { string Arg0 = "??LLLLLL??"; int Arg1 = 3; verify_case(3, Arg1, minimumLiars(Arg0)); }
	void test_case_4() { string Arg0 = "LLL"; int Arg1 = -1; verify_case(4, Arg1, minimumLiars(Arg0)); }

// END CUT HERE
*/
};// BEGIN CUT HERE
/*
int main(){
ConundrumReloaded ___test;
___test.run_test(-1);
//getch() ;
return 0;
}
// END CUT HERE 
*/
