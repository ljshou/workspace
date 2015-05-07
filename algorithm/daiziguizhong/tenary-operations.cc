/**
 * @file tenary-operations.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-06
 */

#include <iostream>
using namespace std;

struct TreeNode {
    string str;
    TreeNode *left, *right;
    TreeNode(const string &s):
        str(s), left(nullptr), right(nullptr) {}
};

TreeNode* Convert(int first, int last, const string &str)
{
    if(first == last) return nullptr;
    int left_index = -1, right_index = -1;
    int left_count = 0;
    for(int i=first; i<last; ++i) {
        if(str[i] == '?') {
            if(left_index == -1) 
                left_index = i;
            ++left_count;
        }
        else if(str[i] == ':') {
            --left_count;
            if(left_count == 0) {
                right_index = i;
                break;
            }
        }
    }
    if(left_index == -1) {
        return new TreeNode(str.substr(first, last-first));
    }
    else {
        TreeNode *root = new TreeNode(str.substr(first, left_index-first));
        root->left = Convert(left_index+1, right_index, str);
        root->right = Convert(right_index+1, last, str);
        return root;
    }
}

TreeNode* Convert(const string &str)
{
    return Convert(0, str.size(), str);
}

void PostOrder(TreeNode *root)
{
    if(!root) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->str;
}

void PreOrder(TreeNode *root)
{
    if(!root) return;
    cout << root->str;
    PreOrder(root->left);
    PreOrder(root->right);
}

void Test()
{
    string str("a?b?c:d:e?f:g");
    cout << str << endl;
    TreeNode *root = Convert(str);
    PostOrder(root);
    cout << endl;

    PreOrder(root);
    cout << endl;
}

int main(void)
{
    Test();
    return 0;
}
