//test program of class IndirectList by L.J.SHOU
#include<iostream>
#include"IndirectList.h"
#include"xcept.h"
using namespace std;
int main()
{
	IndirectList<int> x;
	int y;
	cout<< x.IsEmpty()<<endl;
	for(int i =0; i<10;i++)
		x.Insert(i,i+1);
	cout << x;
	x.Delete(1, y);
	cout << x;
	x.Insert(0,99);
	cout<< x;
	return -1;
}	
