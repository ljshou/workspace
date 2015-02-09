/**
 * @file bitset.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2015-02-04
 */

#include <iostream>
#include <vector>
using namespace std;

class BitSet 
{
public:
    BitSet(int size) {
        bit = new unsigned char[size >> 3];
        memset(bit, 0, sizeof(bit)*sizeof(unsigned char));
    }
    ~BitSet() {
        delete [] bit;
    }
    bool get(int i) {
        return bit[i >> 3] & (1 << (i & 0x7));
    }
    void set(int i) {
        bit[i >> 3] |= (1 << (i & 0x7));
    }
private:
    unsigned char *bit;
    //no copy allowed
    BitSet(const BitSet &);
    BitSet& operator=(const BitSet&);
};

void Test()
{
    vector<int> vec{2,1,3,4,2,4,2,5,6,6,7,10, 7};
    BitSet hash(100);
    for(auto x : vec) {
        if(hash.get(x)) 
            cout << x << " ";
        else
            hash.set(x);
    }
    cout << endl;
}

int main(void)
{
    Test();
    return 0;
}
