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
class HappyLetterDiv1
{
public:
  //my version
  string getHappyLetters2(string letters)
  {
    if(letters.empty()) return "";
    int count[26] = {0};
    for(auto x : letters) ++ count[x - 'a'];

    int len = letters.size();
    string res;
    bool flag(true);

    for(int i=0; i<26; ++i) {
      if(count[i] == 0) continue; 
      flag = true;
      for(int j=0; j<26; ++j) {
        if(j == i || count[j] == 0) continue;
        //len is odd
        if(len & 1) {
          if(count[j] > (len-1)/2) {
            flag = false;
            break;
          }
        } 
        //even
        else {
          if(count[i] == 1) {
            flag = false;
            break;
          }
          else {
            if(count[j] > (len-2)/2) {
              flag = false;
              break;
            }
          }
        }
      }
      if(flag) res.push_back('a' + i);
    }
    return res;
  }
  
  //ACRush 's version
  bool solve(string w, char c, int k) {
    int d[256];
    memset(d, 0, sizeof(d));
    for(int i=0; i<w.size(); ++i) d[w[i]]++;
    if(d[c] < k) return false;
    d[c] -= k;
    int s(0), m(0);
    for(int i=0; i<256; ++i) s+=d[i], m=max(m, d[i]);
    return s%2==0 && m<=s/2;
  }

  string getHappyLetters(string letters)
  {
    string r;
    for(char c='a'; c<='z'; ++c) 
      for(int k=1; k<=letters.size(); ++k) 
        if(solve(letters,c,k)) {
          r+=c; break;
        }
    return r;
  }


  // BEGIN CUT HERE
public:
  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
  void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
  void test_case_0() { string Arg0 = "aabbacccc"; string Arg1 = "abc"; verify_case(0, Arg1, getHappyLetters(Arg0)); }
  void test_case_1() { string Arg0 = "aaaaaaaccdd"; string Arg1 = "a"; verify_case(1, Arg1, getHappyLetters(Arg0)); }
  void test_case_2() { string Arg0 = "ddabccadb"; string Arg1 = "abcd"; verify_case(2, Arg1, getHappyLetters(Arg0)); }
  void test_case_3() { string Arg0 = "aaabbb"; string Arg1 = ""; verify_case(3, Arg1, getHappyLetters(Arg0)); }
  void test_case_4() { string Arg0 = "rdokcogscosn"; string Arg1 = "cos"; verify_case(4, Arg1, getHappyLetters(Arg0)); }

  // END CUT HERE

};// BEGIN CUT HERE
int main(){
  HappyLetterDiv1 ___test;
  ___test.run_test(-1);
  //getch() ;
  return 0;
}
// END CUT HERE 

