/* List using simpulated pointer by L.J.SHOU, Feb.21, 2013 */
/* 模拟指针 */
#ifndef SimSpace_
#define SimSpace_
#include<iostream>
#include"xcept.h"
#include<cstdlib>
#include"SimChain.h"
using namespace std;

template <class T>
class SimNode {
public:
	T data;
	int link;
};

template <class T>
class SimChain;

template <class T>
class SimSpace {
	friend class SimChain<T>;
public:
	SimSpace (int MaxSpaceSize = 100);
	~SimSpace() {delete [] node;}
	int Allocate(); //分配一个节点
	void Deallocate (int& i) ; //释放节点i
private:
	int NumberOfNodes, first;
	SimNode<T> *node;//节点数组
};

template<class T>
SimSpace<T>::SimSpace(int MaxSpaceSize)
{//构造函数
	NumberOfNodes = MaxSpaceSize;
	node = new SimNode<T> [NumberOfNodes];
//初始化可用空间表
//创建一个节点链表
	for(int i = 0; i < NumberOfNodes-1; i++)
		node[i].link = i+1;
//链表的最后一个节点
	node[NumberOfNodes-1].link = -1;
//链表的第一个节点
	first = 0;
}

template<class T>
int SimSpace<T>::Allocate()
{// 分配一个自由节点
	if (first == -1) throw NoMem();
	int i = first; //分配第一个节点
	first = node[i].link; //first指向下一个自由节点
	return i;
}

template<class T>
void SimSpace<T>::Deallocate(int& i)
{// 释放节点i.
//使 i 成为可用空间表的第一个节点
	node[i].link = first;
	first = i;
	i = -1;
}




























#endif
