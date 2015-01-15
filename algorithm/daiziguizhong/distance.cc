/**
 * @file distance.cc
 * @brief 模糊距离 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-14
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int height;
    TreeNode *left, *right;
    TreeNode(int h=0):
        height(h), left(nullptr), right(nullptr) {}
};

TreeNode* Destroy(TreeNode *root)
{
    if(!root) return nullptr;
    root->left = Destroy(root->left);
    root->right = Destroy(root->right);
    delete root;
    return nullptr;
}

int Height(TreeNode *root)
{
    if(!root) return 0;
    int left = Height(root->left);
    int right = Height(root->right);
    return root->height = max(left, right) + 1;
}

class Trie {
public:
    Trie(): root(new TreeNode()) {}
    ~Trie() { root = Destroy(root); }
    void insert(const string &str);
    void compute_height();
    int max_distance() const;
private:
    TreeNode *root;
    //no copy allowed
    Trie(const Trie&);
    Trie& operator=(const Trie&);
    int helper(TreeNode *p) const {
        if(!p) return 0;
        int left = helper(p->left);
        int right = helper(p->right);
        int d = 0;
        if(p->left) d += p->left->height;
        if(p->right) d += p->right->height;
        return max(d, max(left, right));
    }
};

void Trie::insert(const string &str)
{
    TreeNode *p = root;
    for(auto c : str) {
        if(c == '0') {
            if(p->left == nullptr)
                p->left = new TreeNode();
            p = p->left;
        }
        else if(c == '1') {
            if(p->right == nullptr)
                p->right = new TreeNode();
            p = p->right;
        }
        else {
            return;
        }
    }
}

void Trie::compute_height() {
    Height(root);
}

int Trie::max_distance() const {
    return helper(root);
}

int Distance(const vector<string> &vec)
{
    Trie trie;
    for(auto str : vec)
        trie.insert(str);
    trie.compute_height();
    return trie.max_distance();
}

int main(void)
{
    vector<string> vec{"101", "1100", "10"};
    cout << Distance(vec) << endl;
    return 0;
}
