/**
 * @file big-int.cc
 * @brief  class for Big Integer 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-11-02
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct BigInt;
BigInt operator+(const BigInt &lhs, const BigInt &rhs); 

struct BigInt {
  BigInt(long long num = 0) { 
	*this = num;
  }
  BigInt(const string &str) {
	*this = str;
  }
  BigInt operator=(long long num) {
	s.clear();
	do {
	  s.push_back(num % BASE);
	  num /= BASE;
	}while(num);

	return *this;
  }
  BigInt operator=(const string &str) {
	s.clear();
	if(str.empty()) {
	  s.push_back(0);
	  return *this;
	}
	int start = 0;
	for(int i=str.size(); i>0; i-=RADIX) {
	  start = max(0, i - RADIX);
	  s.push_back(atoi(str.substr(start, i-start).c_str()));
	}

	return *this;
  }

  BigInt& operator+=(const BigInt &rhs) {
	*this = *this + rhs;
	return *this;
  }

  static const int BASE = 100000000;
  static const int RADIX = 8;
  vector<int> s;
};

ostream& operator<<(ostream& out, const BigInt &num) {
  out << num.s.back();
  char buf[20];
  for(int i=num.s.size()-2; i>=0; --i) { //also print heading 0s
	sprintf(buf, "%08d", num.s[i]);
	out << buf;
  }
  return out;
}

istream& operator>>(istream &out, BigInt &num) {
  string s;
  if(!(cin >> s)) return out; 
  num = s;
  return out;
}

BigInt operator+(const BigInt &lhs, const BigInt &rhs) {
  BigInt res;
  res.s.clear(); //do not leave this statement
  int x, carry = 0, i = 0;
  while(i < lhs.s.size() || i < rhs.s.size() || carry) {
	x = carry;
	if(i < lhs.s.size()) x += lhs.s[i];
	if(i < rhs.s.size()) x += rhs.s[i];
	carry = x / BigInt::BASE;
	res.s.push_back(x % BigInt::BASE);
	++i;
  }
  return res;
}

int main(void)
{
  BigInt res;
  string str;
  while(cin >> str) {
	if(str.size() == 1 && str[0] == '0') break;
	res += BigInt(str);
  }
  cout << res << endl;

  return 0;
}
