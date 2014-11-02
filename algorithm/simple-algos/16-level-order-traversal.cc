// copyright @ L.J.SHOU Mar.10, 2014
// level order traversal 

void LevelOrder(TreeNode *root)
{
  if(root == NULL) return;
  queue<TreeNode*> q;
  TreeNode *node(NULL);

  q.push(root);
  while(!q.empty())
  {
    node = q.front(); q.pop();
	cout << node->val << " ";
	if(node->left) q.push(node->left);
	if(node->right) q.push(node->right);
  }
  cout << endl;
}


