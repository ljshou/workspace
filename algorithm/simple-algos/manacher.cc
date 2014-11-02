//copyright @ L.J.SHOU Feb.16, 2014
//manacher algorithm 
//find the longest palindromic sub-string
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// First Method: O(N^2)
string expandFromCenter(string s, int c1, int c2)
{
  int l(c1), r(c2);
  while(l >= 0 && r < s.size() && s[l] == s[r]){
    -- l;
	++ r;
  }
  return s.substr(l+1, r-l-1);
}

// start from center
string longestPalindrome(string s)
{
  if(s.size() < 2) return s;
  string longest;
  string p;

  for(int i=0; i<s.size()-1; ++i){
    //palindrome is odd
    p = expandFromCenter(s, i, i);
	if(p.size() > longest.size())
	  longest = p;

	//palindrome is even
    p = expandFromCenter(s, i, i+1);
	if(p.size() > longest.size())
	  longest = p;
  }

  return longest;
}

// Manacher algorithm

// Transform S into T
// For example, S = "abba", T = "^#a#b#b#a#$"
// ^ and $ signs are sentinels appended to each string
// to avoid bound checking
string preProcess(string s)
{
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; ++i)
    ret += "#" + s.substr(i, 1);
  ret += "#$";
  return ret;
}

string longestPalindromeManacher(string s)
{
  string T = preProcess(s);
  int n = T.length();
  vector<int> p(n, 0);
  int C = 0, R = 0;
  for (int i = 1; i < n-1; ++i){
    int i_mirror = 2*C-i;

	p[i] = (i < R) ? min(R-i, p[i_mirror]) : 0; 

	// attempt to expand palindrome centered at i
	while(T[i + 1 + p[i]] == T[i - 1 - p[i]])
	  ++ p[i];

	// If palindrome centered at i expand past R,
	// adjust center based on expanded palindrome,
	if(p[i] + i > R){
	  C = i;
	  R = i + p[i];
	}
  }

  // Find the maximum element in p
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; ++i){
    if(p[i] > maxLen){
	  maxLen = p[i];
	  centerIndex = i;
	}
  }
  return s.substr((centerIndex - 1 - maxLen)/2 , maxLen);
}

int main(void)
{
  string s;
  cout << "Please input a string" << endl;
  cin >> s;
  cout << longestPalindromeManacher(s) << endl;

  return 0;
}
