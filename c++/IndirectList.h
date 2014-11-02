#ifndef IndirectList_
#define IndirectList_
#include<iostream>
#include<cstdlib>
#include"xcept.h"
using namespace std;
template<class T>
class IndirectList {
public:
	IndirectList(int MaxListSize = 10);
	~IndirectList();
	bool IsEmpty() const {return length == 0;}
	int Length() const {return length;}
	bool Find(int k, T& x) const;
	int Search(const T& x) const;
	IndirectList<T>& Delete(int k, T& x);
	IndirectList<T>& Insert(int k, const T& x);
	void Output(ostream& out) const;
private:
	T **table; // 一维T类型指针数组
	int length, MaxSize;
};

template<class T>
IndirectList<T>::IndirectList(int MaxListSize)
{// 构造函数
	MaxSize = MaxListSize;
	table = new T *[MaxSize];
	length = 0;
}
template<class T>
IndirectList<T>::~ IndirectList()
{// 删除表
	for (int i = 0; i < length; i++)
		delete table[i];
	delete [ ] table;
}

template<class T>
bool IndirectList<T>::Find(int k, T& x) const
{//取第k个元素至 x
//如果不存在第 k个元素,函数返回 false,否则返回 true
	if (k < 1 || k > length) return false; // 不存在第k个元素
	x = *table[k - 1];
	return true;
}

template<class T>
int IndirectList<T>::Search(const T& x) const
{
	for(int i=0; i<length; i++)
		if( x == *table[i] ) return ++i;
	return 0;
}
template<class T>
IndirectList<T>& IndirectList<T>::Delete(int k, T& x)
{
	if(Find(k,x))
	{
		for( int i = k; i < length; i++ )
			*table[i-1]=*table[i];
		--length;
		return *this;
	}
	else
		throw OutOfBounds();
			
}

template<class T>
IndirectList<T>& IndirectList<T>::Insert(int k, const T& x)
{//在第k个元素之后插入 x
//如果不存在第 k个元素,则引发异常 OutOfBounds
//如果没有足够的空间,则传递 NoMem异常
	if (k < 0 || k > length) throw OutOfBounds();
	if (length == MaxSize) throw NoMem();
//向后移动一个位置
	for (int i = length-1; i >= k; i--)
		table[i+1] = table[i];
	table[k] = new T;
	*table[k] = x;
	length++;
	return *this;
}

template<class T>
void IndirectList<T>::Output(ostream& out) const
{
	for(int i=0; i < length; i++)
		out << *table[i] << " ";
	out << endl;
}

template<class T>
ostream& operator<<(ostream& out, const IndirectList<T>& x)
{
	x.Output(out);
	return out;
}










#endif
