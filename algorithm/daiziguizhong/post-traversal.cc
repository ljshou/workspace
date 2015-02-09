/**
 * @file post-traversal.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-26
 */

#include <iostream>
#include <stack>
#include <vector>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int x=0): val(x) {}
};

TreeNode* Destroy(TreeNode *root)
{
    if(!root) return nullptr;
    for(auto &node : root->children) {
        node = Destroy(node);
    }
    delete root;
    return nullptr;
}

bool NoChild(TreeNode *root)
{
    if(!root) return true;
    return root->children.empty();
}

TreeNode* LastChild(TreeNode *root)
{
    assert(!root->children.empty());
    return root->children.back();
}

void PostOrder(TreeNode *root)
{
    if(!root) return;
    TreeNode *prev = nullptr;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        root = s.top();
        if(NoChild(root) || prev == LastChild(root)) {
            //visit node
            prev = root;
            cout << root->val << " ";
            s.pop();
        }
        else {
            //push children in reverse order
            for(auto it=root->children.rbegin(); it!=root->children.rend(); ++it) {
                s.push(*it);
            }
        }
    }
    cout << endl;
}

void Test()
{
    TreeNode *root = new TreeNode(7);
    root->children.push_back(new TreeNode(4));
    root->children.push_back(new TreeNode(5));
    root->children.push_back(new TreeNode(6));
    root->children[0]->children.push_back(new TreeNode(1));
    root->children[0]->children.push_back(new TreeNode(2));
    root->children[1]->children.push_back(new TreeNode(3));

    PostOrder(root);

    root = Destroy(root);
}

int main(void)
{
    Test();
    return 0;
}
