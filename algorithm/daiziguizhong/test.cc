/**
 * @file test.cc
 * @brief 
 * @author L.J.SHOU, shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-12-30
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

int main(void)
{
    ofstream out("test.out");
    out << "hello world" << endl;
    out.close();
    return 0;
}
