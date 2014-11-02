// copyright @ L.J.SHOU Feb.24, 2014
// 微软面试第4题
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x)
    :val(x), left(NULL), right(NULL){}
};

vector<vector<int> > result;

void PathSum(TreeNode *root, vector<int>& path, int sum)
{
  if(root == NULL) return;

  path.push_back(root->val);
  // leaf node
  if(root->left == NULL && root->right == NULL){
    if(sum == root->val){
	  result.push_back(path);
	  path.pop_back();
	  return;
	}
  }

  if(root->left){
    PathSum(root->left, path, sum - root->val);
  }

  if(root->right){
    PathSum(root->right, path, sum - root->val);
  }
  
  path.pop_back();
}

TreeNode* Destroy(TreeNode *root)
{
  if(root == NULL) return NULL;
  root->left = Destroy(root->left);
  root->right = Destroy(root->right);
  delete root;
  
  return NULL;
}

int main(void)
{
  TreeNode *root(NULL);
  vector<int> path;

  root = new TreeNode(10);
  root->left = new TreeNode(5);
  root->right = new TreeNode(12);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(7);

  PathSum(root, path, 22);
  for(int i=0; i<result.size(); ++i){
    copy(result[i].begin(), result[i].end(), ostream_iterator<int>(cout, " "));
	cout << endl;
  }

  root = Destroy(root);
  return 0;
}
