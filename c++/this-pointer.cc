/**
 * @file this-pointer.cc
 * @brief 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-11-05
 */

#include <iostream>
using namespace std;

class A {
public:
    A(int x=0): a(x) {}
    void print() {
        cout << "print ok" << endl;
    }
    void print_int() {
        cout << "int = " << a << endl;
    }
private:
    int a;
};

int main(void)
{
    A *p = NULL;
    p->print();
    p->print_int();

    return 0;
}
