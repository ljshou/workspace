/**
 * @file test.cc
 * @brief 
 * @author shoulinjun@126.com ljshou.gitcafe.com
 * @version 0.1.00
 * @date 2014-12-12
 */

#include <iostream>
using namespace std;

class A
{
public:
};

class B : public A
{
public:
    void func2() {
        cout << "func2 called" << endl;
    }
};

int main(void)
{
    A* p = new B();
    p->func2();
    delete p;
    return 0;
}
