// copyright @ L.J.SHOU Mar.13, 2014
// a simple calculator using Factory Design Pattern

#include "operator.h"
#include <iostream>
#include <stdexcept>
#include "boost/shared_ptr.hpp"
using namespace std;

int main(void)
{
  try{
    boost::shared_ptr<Operator> pOper(createOperator("+", 0, 1));
    cout << pOper->GetResult() << endl;

    pOper = boost::shared_ptr<Operator>(createOperator("-", 0, 1));
    cout << pOper->GetResult() << endl;

    pOper = boost::shared_ptr<Operator>(createOperator("*", 2, 3));
    cout << pOper->GetResult() << endl;

    pOper = boost::shared_ptr<Operator>(createOperator("/", 1, 0));
    cout << pOper->GetResult() << endl;
  }
  catch(std::runtime_error err){
    std::cout << err.what() 
              << std::endl;
  }

  return 0;
}
