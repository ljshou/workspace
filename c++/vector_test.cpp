#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> ivec(10);
	int i = 0;
	for(vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
	{
		*iter = (i++);
		cout << *iter << ' ';
	}
	cout << endl;
	cout << *(ivec.begin() + ivec.size()/2) << endl;
//	cout << *((ivec.begin() + ivec.end())/2) << endl; //error!!!

	return 0;


}

