#ifndef Node_
#define Node_
#include<iostream>
#include"../xcept.h"
#include"../chain.h"
using namespace std;
class Node {
friend ostream& operator<<(ostream&, const Node &);
friend void BinSort(Chain<Node>& X, int range);
public:
	int operator !=(Node x) const
	{return (score != x.score|| name[0] != x.name[0]);}
	operator int() const {return score;}
private:
	int score;
	char *name;
};

ostream& operator<<(ostream& out, const Node& x)
{
	out << x.score << ' ' << x.name[0] << ' ';
	return out;
}

void BinSort(Chain<Node>& X, int range)
{// 按分数排序
	int len = X.Length();
	Node x;
	Chain<Node> *bin;
	bin = new Chain<Node> [range + 1];
//分配到每个箱子中
	for (int i = 1; i <= len; i++) {
		X,Delete(1,x);
		bin[x.score].Insert(0,x);
	}
//从箱子中收集各元素
	for (int j = range; j >= 0; j--)
		while (!bin[j].IsEmpty()) {
			bin[j].Delete(1,x);
			X.Insert(0,x);
		}
	delete [ ] bin;
}








#endif
