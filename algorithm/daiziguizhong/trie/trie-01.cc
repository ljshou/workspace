/**
 * @file trie-01.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-09
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    bool flag;
    TreeNode *left, *right;
    TreeNode(bool f=false):
        flag(f), left(nullptr), right(nullptr) {}
};

TreeNode* Destroy(TreeNode* root)
{
    if(root == nullptr) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}

class Trie {
public:
    Trie(const string &str) {
        root = new TreeNode(false);
        auto p = root;
        for(auto c : str) {
            if(c == '0')  p = p->left  = new TreeNode();
            else if(c == '1') p = p->right = new TreeNode();
            else break;
        }
        p->flag = true;
    }
    ~Trie() {
        root = Destroy(root);
    }
    void insert(const string &str);
    string lca() const;
private:
    TreeNode *root;
    // no copy allowed
    Trie(const Trie&);
    Trie& operator=(const Trie&);
};

void Trie::insert(const string &str)
{
    TreeNode *p = root;
    for(auto c : str) {
        if(p->flag) return;
        if(c == '1') {
            if(p->left != nullptr) {
                break;
            }
            else {
                p  = p->right;
            }
        }
        else if(c == '0') {
            if(p->right != nullptr) {
                break;
            }
            else {
                p  = p->left;
            }
        }
        else break;
    }
    p->flag = true;
}

string Trie::lca() const {
    string str;
    auto p = root;
    while(p && !p->flag) {
        if(p->left) {
            str += '0';
            p = p->left;
        }
        else {
            str += '1';
            p = p->right;
        }
    }
    return str;
}

string LCA(const vector<string> &vec)
{
    if(vec.empty()) return "";
    Trie tree(vec.front());
    for(auto str : vec) {
        tree.insert(str);
    }
    return tree.lca();
}

void Test()
{
    vector<string> vec{"100000", "10", "100"};
    cout << LCA(vec) << endl;
}

int main(void)
{
    Test();
    return 0;
}
