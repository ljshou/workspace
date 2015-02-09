/**
 * @file reverse-addition-chain.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-27
 */

#include <iostream>
#include <string>
using namespace std;

const int CHARS = 11;

struct TrieNode {
    bool flag;
    string url;
    TrieNode *children[CHARS];
    TrieNode(): flag(false) {
        fill(children, children+CHARS, nullptr);
    }
};

TrieNode* Destroy(TrieNode *root)
{
    if(!root) return nullptr;
    for(int i=0; i<CHARS; ++i) {
        root->children[i] = Destroy(root->children[i]);
    }
    delete root;
    return nullptr;
}

class Trie {
public:
    Trie(): root(new TrieNode()) {}
    ~Trie() { root = Destroy(root); }
    void Insert(const string &ip, const string &url);
    string Search(const string &ip);
private:
    TrieNode *root;
    //no copy allowed
    Trie(const Trie &t);
    Trie& operator=(const Trie &t);
};

int GetIndex(char c) 
{
    return c == '.' ? 10 : (c - '0');
}

void Trie::Insert(const string &ip, const string &url)
{
    //validate ip first
    if(validateIP(ip) == false) return;

    auto cur = root;
    int index = 0;
    for(auto c : ip) {
        index = GetIndex(c);
        if(cur->children[index] == nullptr)
            cur->children[index] = new TrieNode();
        cur = cur->children[index];
    }
    if(cur->flag == false) {
        cur->flag = true;
        cur->url = url;
    }
}

string Trie::Search(const string &ip)
{
    auto cur = root;
    int index = 0;
    for(auto c : ip) {
        index = GetIndex(c);
        if(cur->children[index] == nullptr)
            return "";
        cur = cur->children[index];
    }
    return cur->flag ? cur->url : "";
}

void Test()
{
    Trie trie;
    char ipAdd[][20] = {"107.108.11.123", "107.109.123.255",
        "74.125.200.106"};
    char URL[][50] = {"www.samsung.com", "www.samsung.net",
        "www.google.in"};
    for(int i=0; i<3; ++i) {
        trie.Insert(ipAdd[i], URL[i]);
    }
    cout << trie.Search("107.108.11.123") << endl;
    cout << trie.Search("107.109.123.255") << endl;
    cout << trie.Search("74.125.200.106") << endl;
}

int main(void)
{
    Test();
    return 0;
}
