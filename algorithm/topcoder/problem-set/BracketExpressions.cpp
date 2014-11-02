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
class BracketExpressions
{
public:
string ifPossible(string expression)
{
  stack<char> s;
  if(dfs(0, s, expression))
    return "possible";
  else 
    return "impossible";
}
private:
bool dfs(int cur, stack<char> &s, string &expression) {
  if(cur == expression.size()) {
    return s.empty();
  }
  char c = expression[cur];
  if(c == 'X') {
    s.push('(');
    if(dfs(cur+1, s, expression)) return true;
    assert(!s.empty());
    s.pop();

    s.push('[');
    if(dfs(cur+1, s, expression)) return true;
    assert(!s.empty());
    s.pop();

    s.push('{');
    if(dfs(cur+1, s, expression)) return true;
    assert(!s.empty());
    s.pop();

    if(!s.empty()) {
      char temp = s.top();
      s.pop();
      if(dfs(cur+1, s, expression)) return true;
      s.push(temp);
    }
    return false;
  }
  else 
  {
    if(c == '[' || c == '(' || c == '{') {
      s.push(c);
      if(dfs(cur+1, s, expression)) return true;
      assert(!s.empty());
      s.pop();
    }
    else 
    {
      if(s.empty()) return false;
      assert(!s.empty());
      if((s.top()  == '[' && c == ']') 
         || (s.top() == '(' && c == ')')
         || (s.top() == '{' && c == '}')) {
        char temp = s.top();
        s.pop();
        if(dfs(cur+1, s, expression)) return true;
        s.push(temp);
      }
      else {
        return false;
      }
    }
  }
  return false;
}

/*
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "([]{})"; string Arg1 = "possible"; verify_case(0, Arg1, ifPossible(Arg0)); }
	void test_case_1() { string Arg0 = "(())[]"; string Arg1 = "possible"; verify_case(1, Arg1, ifPossible(Arg0)); }
	void test_case_2() { string Arg0 = "({])"; string Arg1 = "impossible"; verify_case(2, Arg1, ifPossible(Arg0)); }
	void test_case_3() { string Arg0 = "[]X"; string Arg1 = "impossible"; verify_case(3, Arg1, ifPossible(Arg0)); }
	void test_case_4() { string Arg0 = "([]X()[()]XX}[])X{{}}]"; string Arg1 = "possible"; verify_case(4, Arg1, ifPossible(Arg0)); }

// END CUT HERE
*/
};// BEGIN CUT HERE
/*
int main(){
BracketExpressions ___test;
___test.run_test(-1);
//getch() ;
return 0;
}
// END CUT HERE 
*/
/*
int main() {
  BracketExpressions test;
  cout << test.ifPossible("{(XX{}[[}") << endl;
  return 0;
}
*/
