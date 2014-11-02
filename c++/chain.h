/* chain implemented by L.J.SHOU, Feb.21, 2013*/
#ifndef Chain_
#define Chain_
#include<iostream>
#include"xcept.h"
using namespace std;

template<class T> //类Chain的声明
class Chain;

template <class T>
class ChainNode {
friend class Chain<T>;
private:
	T data;
	ChainNode<T> *link;
};

template<class T>
class Chain {
public:
	Chain() {first = 0;}
	~Chain();
	bool IsEmpty() const {return first == 0;}
	int Length() const;
	bool Find(int k, T& x) const;
	int Search(const T& x) const;
	Chain<T>& Delete(int k, T& x);
	Chain<T>& Insert(int k, const T& x);
	void Output(ostream& out) const;
private:
	ChainNode<T> *first; // 指向第一个节点的指针
};

template<class T>
Chain<T>::~Chain()
{// 链表的析构函数,用于删除链表中的所有节点
	ChainNode<T> *next; // 下一个节点
	while (first) {
		next = first->link;
		delete first;
		first = next;
	}
}

template<class T>
int Chain<T>::Length() const
{// 返回链表中的元素总数
	ChainNode<T> *current = first;
	int len = 0;
	while (current) {
		len++;
		current = current->link;
	}
	return len;
}

template<class T>
bool Chain<T>::Find(int k, T& x) const
{// 寻找链表中的第 k个元素,并将其传送至 x
//如果不存在第 k个元素,则返回false,否则返回 true
	if (k < 1) return false;
	ChainNode<T> *current = first;
	int index = 1; // current的索引
	while (index < k && current) {
		current = current->link;
		index++;
	}
	if (current) {x = current->data; return true;}
	return false; // 不存在第k个元素
}

template<class T>
int Chain<T>::Search(const T& x) const
{// 寻找x,如果发现 x,则返回x的地址
//如果x不在链表中,则返回 0
	ChainNode<T> *current = first;
	int index = 1; // current的索引
	while (current && current->data != x) {
		current = current->link;
		index++;
	}
	if (current) return index;
	return 0;
}

template<class T>
void Chain<T>::Output(ostream& out) const
{// 将链表元素送至输出流
	ChainNode<T> *current;
	for (current = first; current; current = current->link)
		out << current->data << " ";
	out<<endl;
}

//重载<<
template <class T>
ostream& operator<<(ostream& out, const Chain<T>& x)
{x.Output(out); return out;}

template<class T>
Chain<T>& Chain<T>::Delete(int k, T& x)
{// 把第k个元素取至 x,然后从链表中删除第 k个元素
//如果不存在第 k个元素,则引发异常 OutOfBounds
	if (k < 1 || !first)
		throw OutOfBounds(); // 不存在第 k个元素
// p 最终将指向第 k个节点
	ChainNode<T> *p = first;
// 将p移动至第k个元素,并从链表中删除该元素
	if (k == 1) // p已经指向第 k个元素
		first = first->link; // 删除之
	else { // 用q指向第k-1个元素
		ChainNode<T> *q = first;
		for (int index = 1; index < k - 1 && q; index++)
			q = q->link;
		if (!q || !q->link)
			throw OutOfBounds(); //不存在第k个元素
		p = q->link; // 存在第k个元素
		q->link = p->link;} // 从链表中删除该元素
//保存第k个元素并释放节点 p
	x = p->data;
	delete p;
	return *this;
}

template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{// 在第k个元素之后插入 x
//如果不存在第 k个元素,则引发异常 OutOfBounds
// 如果没有足够的空间,则传递 NoMem异常
	if (k < 0) throw OutOfBounds();
// p 最终将指向第 k个节点
	ChainNode<T> *p = first;
//将p移动至第k个元素
	for (int index = 1; index < k && p; index++)
		p = p->link;
	if (k > 0 && !p) throw OutOfBounds(); //不存在第k个元素
// 插入
	ChainNode<T> *y=new ChainNode<T>;
	y->data = x;
	if (k) {// 在p之后插入
		y->link = p->link;
		p->link = y;}
	else {// 作为第一个元素插入
		y->link = first;
		first = y;}
	return *this;
}




#endif
