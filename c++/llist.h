//Linear List by L.J.SHOU
#ifndef LinearList_  //Currency_为标志符, 防止该头文件被重复#include
#define LinearList_  

#include<iostream>
#include<cstdlib>
#include"xcept.h"
#include<cerrno>
#include<stdexcept>
using namespace std;
template<class T>
class LinearList {
public:
	LinearList(int MaxListSize = 10); //构造函数
	~LinearList() {delete [] element;} //析构函数
	bool IsEmpty() const {return length == 0;}
	int Length() const {return length;}
	bool Find(int k, T& x) const; //返回第k个元素至 x中
	int Search(const T& x) const; // 返回x所在位置
	LinearList<T>& Delete(int k, T& x); // 删除第k个元素并将它返回至 x中
	LinearList<T>& Insert(int k, const T& x); // 在第k个元素之后插入 x
	void Output(ostream& out) const;

private:
	int length;
	int MaxSize;
	T *element; // 一维动态数组
};

template <class T>
LinearList<T>::LinearList(int MaxListSize)
{// 基于公式的线性表的构造函数
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}

template<class T>
bool LinearList<T>::Find(int k, T& x) const
{//把第k个元素取至 x中
//如果不存在第 k个元素则返回 false,否则返回 true
	if (k < 1 || k > length) return false; // 不存在第k个元素
	x = element[k - 1];
	return true;
}

template<class T>
int LinearList<T>::Search(const T& x) const
{// 查找x,如果找到,则返回 x所在的位置
// 如果x不在表中,则返回 0
	for (int i = 0; i < length; i++)
		if (element[i] == x) return ++i;
	return 0;
}

template<class T>
LinearList<T>& LinearList<T>::Delete(int k, T& x)
{// 把第k个元素放入 x中,然后删除第 k个元素
// 如果不存在第 k个元素,则引发异常 OutOfBounds
if (Find(k, x))
{// 把元素 k+l, ...向前移动一个位置
	for (int i = k; i < length; i++)
		element[i-1] = element[i];
	length--;
	return *this;
}
else 
	throw OutOfBounds();
}

template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{// 在第k个元素之后插入 x
// 如果不存在第 k个元素,则引发异常 OutOfBounds
// 如果表已经满,则引发异常 NoMem
	if (k < 0 || k > length) throw OutOfBounds();
	if (length == MaxSize) throw NoMem();
//向后移动一个位置
	for (int i = length-1; i >= k; i--)
		element[i+1] = element[i];
	element[k] = x;
	length++;
	return *this;
}

template<class T>
void LinearList<T>::Output(ostream& out) const
{//把表输送至输出流
	for (int i = 0; i < length; i++)
		out << element[i] << " ";
}

// 重载 <<
template <class T>
ostream& operator<<(ostream& out, const LinearList<T>& x)
{
	x.Output(out); 
	return out;
}



#endif
