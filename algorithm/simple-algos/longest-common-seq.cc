// copyright @ L.J.SHOU Mar.05, 2014
// Longest Common Sub-sequence of two strings

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <climits>
using namespace std;

enum direction{ LEFT=0, LEFTUP=1, UP=2 };

// print common sub-sequence
void PrintLCS(const vector<vector<int> >& b, const string &x, int i, int j)
{
  if(i < 1 || j < 1) return; //exit

  if(b[i][j] == LEFTUP){
    PrintLCS(b, x, i-1, j-1);
	cout << x[i-1];
  }
  else if(b[i][j] == LEFT){
    PrintLCS(b, x, i, j-1);
  }
  else{
    PrintLCS(b, x, i-1, j);
  }
}

// print all common sub-sequences
void PrintAllLCS(const vector<vector<int> >& a, const string &x, const string &y, 
                 int i, int j, string &path)
{
  if(i < 1 || j < 1){ 
	copy(path.rbegin(), path.rend(), ostream_iterator<int>(cout,""));
	cout << endl;
    return; // exit
  }

  if(a[i][j] == a[i-1][j-1] + 1 && x[i-1] == y[j-1]){
    path += x[i-1];
    PrintAllLCS(a, x, y, i-1, j-1, path);
	path.erase(path.end()-1);
  }
  // 不能是 else if, 每个 if 都必须判断
  if(a[i][j] == a[i-1][j]){
    PrintAllLCS(a, x, y, i-1, j, path);
  }
  if(a[i][j] == a[i][j-1]){
    PrintAllLCS(a, x, y, i, j-1, path);
  }
}

void LCS(const string & x, const string & y)
{
  int m(x.size()+1), n(y.size()+1);
  vector<vector<int> > a(m, vector<int>(n, 0));
  vector<vector<int> > b(m, vector<int>(n, 0));

  for(size_t i=1; i<m; ++i)
   for(size_t j=1; j<n; ++j)
   {
     if(x[i-1] == y[j-1]){
	   a[i][j] = a[i-1][j-1] + 1; 
	   b[i][j] = LEFTUP; 
	 }
	 else if(a[i-1][j] >= a[i][j-1]){ 
	   a[i][j] = a[i-1][j]; 
	   b[i][j] = UP;
	 }
	 else{  
	   a[i][j] = a[i][j-1]; 
	   b[i][j]=LEFT;
	 }
   }

  cout << "**********REUSLT****using Method 1*************" << endl;
  cout << x << endl;
  cout << y << endl;
  cout << "Longest Common Sequence # is: " << a[m-1][n-1] << endl;
  string path;
  
  for(int i=0; i<a.size(); ++i)
  {
    for(int j=0; j<a[0].size(); ++j)
	  cout << a[i][j] << " ";
	cout << endl;
  }

  PrintAllLCS(a, x, y, m-1, n-1, path);
  cout << endl;
}

int LookUp(const string &x, const string &y, vector<vector<int> >& a, vector<vector<int> >& b, int i, int j)
{
  if(i==0 || j==0){ //exit
    a[i][j] = 0;
	return a[i][j];
  }
  if(a[i][j] != INT_MAX) 
    return a[i][j];
  else if(x[i-1]==y[j-1]){
    a[i][j] = LookUp(x,y,a,b,i-1,j-1)+1;
	b[i][j] = LEFTUP;
  }
  else{
    int lhs(LookUp(x,y,a,b,i-1,j)), rhs(LookUp(x,y,a,b,i,j-1));
	if(lhs >= rhs){
	  a[i][j] = lhs;
	  b[i][j] = UP;
	}
	else{
	  a[i][j] = rhs;
	  b[i][j] = LEFT;
	}
  }
  return a[i][j];
}

void LCS_memo(const string & x, const string & y)
{
  int m(x.size()+1), n(y.size()+1);
  vector<vector<int> > a(m, vector<int>(n, INT_MAX));
  vector<vector<int> > b(m, vector<int>(n, 0));

  cout << "**********REUSLT*****using method 2************" << endl;
  cout << x << endl;
  cout << y << endl;
  cout << "Longest Common Sequence # is: " << LookUp(x,y,a,b,m-1,n-1) << endl;
  PrintLCS(b, x, m-1, n-1);
  cout << endl;
}

int main()
{
  string x, y;
  cout << "Please input two strings: " << endl;
  cin >> x >> y;
  LCS(x, y);
  LCS_memo(x, y);
  return 0;
}
