/**
 * @file protected-member.cc
 * @brief test usage of protected member
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-03-19
 */
#include <iostream>
using namespace std;

class Base{
public:
    Base(int x=0): pro(x){}
protected:
    int pro;
};

class Derivative : public Base{
public:
    Derivative(int x=0): Base(x) {}
    void Print(Derivative &d, Base &b){
        cout << "this->protected: " << pro << endl;
        cout << "d.protected: " << d.pro << endl;

        // error
        // cout << "b.protected: " << b.pro << endl;
    }
};

int main(void)
{
    Base b(0);
    Derivative d1(1), d2(2);

    d1.Print(d2, b);

    // error
    // cout << b.pro << endl;
    // cout << d1.pro << endl;

    return 0;
}

