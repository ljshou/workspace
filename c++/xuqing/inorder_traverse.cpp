#include<iostream>
#include<vector>
//指针作为函数参数，当作传入参数之后，指针在函数内的操作仅仅是形参的操作，实参并没有修改
//如果要在函数内部修改指针的指向的话，应该使用指针的地址或者引用
using namespace std;

struct BSTreeNode
{
	int m_nValue; // value of node
	BSTreeNode *m_pLeft; // left child of node
	BSTreeNode *m_pRight; // right child of node
};

void inOrder_traverse(BSTreeNode *);
void addTreeNode(BSTreeNode* &tree, int value)
{
	cout << "add node " << value << endl;
	BSTreeNode *pNode = new BSTreeNode;
	if (NULL == pNode)
	{
		cout << "new error!!" << endl;
	}
	pNode->m_nValue = value;
	pNode->m_pLeft = NULL;
	pNode->m_pRight = NULL;
	cout << "new a new node" << pNode->m_nValue << endl;
	
	if ( NULL == tree)
	{
		tree = pNode;
		cout << "add node " << value << " " << tree << " " << pNode << endl;
		if (NULL == tree)
		{
			cout << "WHY TREE EMPTY!!!" << endl;
		}
		return;
	}
	else
	{

		BSTreeNode *p = tree;
		if (p->m_nValue > value)
		{
			addTreeNode(tree->m_pLeft,value);
		}
		else if (p->m_nValue < value)
		{
			addTreeNode(tree->m_pRight,value);
		}
		else
		{
			cout << "repeat node!!!" << endl;
		}
	}
	cout << "tree..." << endl;
	//inOrder_traverse(tree);
}

void build_tree(vector<int> nodeList,BSTreeNode* &tree)
{
	cout << "begin build tree..." << endl;
	for(vector<int>::size_type it = 0; it != nodeList.size(); ++it)
	{
		addTreeNode(tree,nodeList[it]);
		if (NULL == tree)
		{
			cout << "add " << nodeList[it] << " error!!! , tree empty" << endl;
		}
	}
}

void inOrder_traverse(BSTreeNode *tree)
{
	if ( NULL == tree)
	{
		//cout << "empty tree..." << endl;
		return;
	}
	inOrder_traverse(tree->m_pLeft);
	cout << tree->m_nValue << endl;
	inOrder_traverse(tree->m_pRight);
}
int main()
{
	vector<int> nodeList;
	BSTreeNode *tree = NULL;
	int number;
	cout << "input node , return <ctrl + D>" << endl;
	while(cin >> number)
	{
		nodeList.push_back(number);
	}
	cout << "nodeList.size() = "  << nodeList.size() << endl;
	build_tree(nodeList,tree);
	if (NULL == tree)
	{
		cout << "build tree error!!!" << endl;
	}
	cout << "print tree..." << endl;
	inOrder_traverse(tree);



	return 0;
}
