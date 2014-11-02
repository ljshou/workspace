// copyright @ L.J.SHOU Jan.16, 2014
// a fancy binary tree printer
#ifndef BINARY_TREE_PRINTER_H_
#define BINARY_TREE_PRINTER_H_

#include <cmath>
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::max;

void PrintBinaryTree(TreeNode *root);

struct TreeNode
{
  TreeNode *left;
  TreeNode *right;
  int val;
  TreeNode(int x=0)
   : val(x), left(NULL), right(NULL){}
};

static int MaxLevel(TreeNode *root)
{
  if(root == NULL) return 0;
  return max(MaxLevel(root->left), MaxLevel(root->right)) + 1;
}

// test whether all elements in vector are NULL
static bool IsAllElementsNULL(const vector<TreeNode*> &nodes)
{
  vector<TreeNode*>::const_iterator it = nodes.begin();

  while(it != nodes.end()){
    if(*it) return false; 
	++it;
  }
  return true;
}

static void PrintWhiteSpaces(int num)
{
  for(int i=0; i<num; ++i)
    cout << " ";
}

void PrintNode(vector<TreeNode*> &nodes, int level, int max_level)
{
  if(nodes.empty() || IsAllElementsNULL(nodes)) return; // exit

  int floor = max_level - level;
  int endge_lines = 1 << (max(floor-1, 0));
  int first_spaces = (1 << floor) - 1;
  int between_spaces = (1 << (floor+1)) - 1;

  PrintWhiteSpaces(first_spaces);

  // print the 'level' level 
  vector<TreeNode*> new_nodes;
  vector<TreeNode*>::const_iterator it = nodes.begin();
  for(; it != nodes.end(); ++it){
    if(*it != NULL){
	  cout << (*it)->val;
	  new_nodes.push_back((*it)->left);
	  new_nodes.push_back((*it)->right);
	}
	else{
	  new_nodes.push_back(NULL);
	  new_nodes.push_back(NULL);
	  cout << " ";
	}
    PrintWhiteSpaces(between_spaces);
  }
  cout << endl;

  // print the following /s and \s
  for(int i=1; i<= endge_lines; ++i){
    for(int j=0; j<nodes.size(); ++j){
	  PrintWhiteSpaces(first_spaces - i);
	  if(nodes[j] == NULL){
	    PrintWhiteSpaces(endge_lines + endge_lines + i + 1);
		continue;
	  }
	  if(nodes[j]->left != NULL)
	    cout << "/";
	  else
	    PrintWhiteSpaces(1);

	  PrintWhiteSpaces(i+i-1);
	  
	  if(nodes[j]->right != NULL)
	    cout << "\\";
	  else
	    PrintWhiteSpaces(1);

	  PrintWhiteSpaces(endge_lines + endge_lines - i);
	}
	cout << endl;
  }

  PrintNode(new_nodes, level+1, max_level);

}

// wrapper function
void PrintBinaryTree(TreeNode *root)
{
  int max_level = MaxLevel(root);
  vector<TreeNode*> nodes;
  
  nodes.push_back(root);
 
  PrintNode(nodes, 1, max_level);
}

#endif

#if 0
int main(void)
{
  TreeNode *root(NULL);
  
  root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  root->left->left = new TreeNode(4);
  root->right->right = new TreeNode(7);

  root->left->left->left = new TreeNode(8);
  root->left->left->right = new TreeNode(9);
  PrintBinaryTree(root);

  root = Destroy(root);
  return 0;
}
#endif

