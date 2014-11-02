#include<iostream>
#include"chain.h"
using namespace std;
int main()
{
	Chain<int> chain;
	int y;
	cout<<chain.Length()<<endl;
	for(int i = 0; i < 10; i++)
		chain.Insert(i,i+1);
	cout<<chain;
	chain.Delete(1,y);
	cout<<chain;
	return -1;
}
