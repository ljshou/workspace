/**
 * @file cash.cc
 * @brief simple test file for cash 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-03-17
 */

#include "cash.h"
#include <iostream>
#include "boost/shared_ptr.hpp"
using namespace std;

int main(void)
{
    CashContext csuper("正常收费");
    cout << csuper.GetResult(300) << endl; 

    csuper = CashContext("打8折");
    cout << csuper.GetResult(300) << endl; 

    csuper = CashContext("满300减100");
    cout << csuper.GetResult(300) << endl; 

    return 0;
}
