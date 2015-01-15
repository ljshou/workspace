/**
 * @file random-pop-set.cc
 * @brief set supporting random pop
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-01-12
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>
using namespace std;

class Set {
public:
    Set(){}
    ~Set() { clear(); }
    void insert(int x);
    void remove(int x);
    int randomPop();
    int size() const {return vec.size();}
private:
    unordered_map<int, int> hash;
    vector<int> vec;

    void clear() {
        vec.clear();
        hash.clear();
    }

    //no copy allowed
    Set(const Set&rhs);
    Set& operator=(const Set& rhs);
};

void Set::insert(int x) {
    if(hash.find(x) == hash.end()) {
        hash[x] = vec.size();
        vec.push_back(x);
    }
}

void Set::remove(int x) {
    if(hash.find(x) != hash.end()) {
        int index = hash[x];
        hash[vec.back()] = index;
        swap(vec[index], vec[vec.size()-1]);
        vec.resize(vec.size()-1);
        hash.erase(x);
    }
}

int Set::randomPop() {
    if(vec.empty()) throw runtime_error("empty");
    int index = rand() % vec.size();
    return vec[index];
}

void Test() {
    Set s;
    for(int i=1; i<=5; ++i)
        s.insert(i);
    assert(s.size() == 5);
    s.remove(0);
    assert(s.size() == 5);
    s.remove(3);
    assert(s.size() == 4);
    s.remove(3);
    assert(s.size() == 4);
    s.remove(4);
    assert(s.size() == 3);
    s.insert(4);
    assert(s.size() == 4);
    s.insert(400);
    assert(s.size() == 5);

    srand(time(0));
    for(int i=0; i<10; ++i) 
        cout << s.randomPop() << " ";
    cout << endl;
}

int main(void)
{
    Test();
    return 0;
}
