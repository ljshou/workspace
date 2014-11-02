#include<iostream>
#include"Node.h"
using namespace std;
int main()
{
	Chain<Node> chain;
	Node a(3, "A"),b(2,"B"),c(5,"C");
	chain.Insert(0,a);
	chain.Insert(1,b);
	chain.Insert(2,c);
	cout<<chain;
//	BinSort(chain,3);
	cout<<chain;	
	return -1;
}
