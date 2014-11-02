#include<iostream>
using namespace std;
const int SIZE = 8;

int main()
{
	int num[] = {1,-1,2,-3,4,-5,6,-7};
	int T[SIZE] = {0};
	int T2[SIZE] = {0};
	T2[0] = 1;
	int ch1 = 0;
	bool label = false;
	T[0] = 1;
	int m = 0;
	int k = 0;
	for(int i = 1 ; i < SIZE; ++i)
	{
		cout << "The " << i << "-th element" << endl;
		ch1 = T[i-1];
		label = false;
		m = 0;
		for(int j = 0; j < i;++j)
		{
			if (num[i] > num[j])
			{
				cout << num[i] << " > " << num[j] << endl; 
				if ((T[j]+1) > ch1)
				{
					ch1 = T[j]+1;
					label=true;
					cout << "longest " << m <<" = " << num[j] << endl;
					m++;
				}
			}

		}
		if (!label)
		{
			cout << "longest = " << num[i-1] << endl;
		}
		T[i] = ch1;
		cout << "T[" << i <<"] = " << T[i] << endl; 
	}
	for(int i = 0; i < SIZE ; ++i)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < SIZE ; ++i)
	{
		cout << T[i] << " ";
	}
	cout << endl;
	cout << "nlogn" << endl;
	label=false;
	m=0;
	int j = 0;
	for(int i =1 ; i < SIZE; ++i)
	{
		label=false;
		m=0;
		ch1 = T2[i-1];
		k = i;
		j = i/2;
		if ( i == 1)
		{
			if (num[i] > num[i-1])
			{
				T2[i] = T2[i-1] + 1;
				cout << "!!!" << T2[i-1] << " " << T2[i] << endl;
			}
			else
			{
				T2[i] = T2[i-1];
			}
			continue;
		}
		while(j > 0)
		{
			int m = 0;
			if (num[i] > num[j])
			{
				ch1 = T2[j] + 1;
				label = true;
				cout << "longest " << m <<" = " << num[j] << endl;
				m++;
				j++;
				j=(k-j)/2;
			}
			else
			{
				j--;
				j=j/2;
			}
		}
		if (!label)
		{
			cout << "longest = " << num[i-1] << endl;
		}
		T2[i] = ch1;
		cout << "T2[" << i <<"] = " << T2[i] << endl; 
	}
	for(int i = 0; i < SIZE ; ++i)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	for(int i = 0; i < SIZE ; ++i)
	{
		cout << T2[i] << " ";
	}
	cout << endl;
	return 0;
}
