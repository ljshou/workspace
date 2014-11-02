#ifndef SimChain_
#define SimChain_
#include<iostream>
#include<cstdlib>
#include"xcept.h"
#include"SimSpace.h"
using namespace std;

template<class T>
class SimChain {
public:
	SimChain() {first = -1;}
	~SimChain() {Destroy();}
	void Destroy(); // 使表为空
	int Length() const;
	bool Find(int k, T& x) const;
	int Search(const T& x) const;
	SimChain<T>& Delete(int k, T& x);
	SimChain<T>& Insert(int k, const T& x);
	void Output(ostream& out) const;
private:
	int first; // 第一个节点的索引
	static SimSpace<T> S;
};

template<class T>
void SimChain<T>::Output(ostream& out) const
{
	int p = S.first;
	while(p!=-1)
	{
		out<<S.node[p].data<<" ";
		p=S.node[p].link;
	}
	out<<endl;
}
template<class T>
ostream& operator<<(ostream& out, const SimChain<T>& x)
{ x.Output(out); return out;}

template<class T>
void SimChain<T>::Destroy()
{// 释放链表节点
	int next;
	while (first != -1) {
		next = S.node[first].link;
		S.Deallocate(first);
		first = next;
	}
}

template<class T>
bool SimChain<T>::Find(int k, T& x) const
{// 取第k个元素至x
//如果不存在第 k个元素,函数返回 false,否则返回 true
	if (k < 1) return false;
	int current = first, // 链节点的当前位置
	index = 1;
//当前节点的索引
//移动current至第k个节点
	while (index < k && current != -1) {
		current = S.node[current].link;
		index++;
	}
//验证是否到达了第 k个节点
	if (current != -1) {x = S.node[current].data; return true;}
	return false; // 不存在第k个元素
}

template<class T>
SimChain<T>& SimChain<T>::Delete(int k, T& x)
{
	if (k < 1 || first == -1)
		throw OutOfBounds(); // 不存在第 k个元素
// p 最终将指向第 k个节点
	int p = first;
//将p移动至第 k个节点,并从链表中删除该节点
	if (k == 1) // p已经指向第 k个节点
		first = S.node[first].link; // 从链表中删除
	else { // 使用q指向第k-1个元素
		int q = first;
		for (int index = 1; index < k - 1 && q != -1; index++)
			q = S.node[q].link;
// 验证第k个元素的存在性
		if (q == -1 || S.node[q].link == -1)
			throw OutOfBounds(); // 不存在第k个元素
//使p指向第k个元素
		p = S.node[q].link;
//从链表中删除第k个元素
		S.node[q].link = S.node[p].link;
	}
//保存第k个元素并释放节点 p
	x = S.node[p] .data;
	S.Deallocate(p);
	return *this;
}

template<class T>
SimChain<T>& SimChain<T>::Insert(int k, const T& x)
{//在第k个元素之后插入 x
//如果不存在第 k个元素,则引发异常 OutOfBounds
//如果没有足够的空间,则传递 NoMem异常
	if (k < 0) throw OutOfBounds();
//定义一个指针 p,p最终将指向第 k个节点
	int p = first;
//将p移向第k个节点
	for (int index = 1; index < k && p != -1; index++)
		p = S.node[p].link;
// 验证第k个节点的存在性
	if (k > 0 && p == -1)
		throw OutOfBounds();
// 为插入操作分配一个新节点
	int y = S.Allocate();
	S.node[y].data = x;
//向链表中插入新节点
// 首先检查新节点是否要插到链表的首部
	if (k) {//在p之后插入
		S.node[y].link = S.node[p].link; S.node[p].link = y;}
	else {// 作为链表首节点
		S.node[y].link = first; first = y;}
	return *this;
}

template<class T>
int SimChain<T>::Length() const
{// 返回链表的长度
	int current = first;//链节点的当前位置
	int len = 0;
//元素计数
	while (current != -1) {
		current = S.node[current].link;
		len++;
	}
	return len;
}



#endif
