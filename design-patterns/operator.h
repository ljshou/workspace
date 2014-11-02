// copyright @ L.J.SHOU Mar.13, 2014
// a simple calculator using Factory Design Pattern
#ifndef OPERATOR_H_
#define OPERATOR_H_

#include <string>
#include <iostream>
#include <stdexcept>

// base class
class Operator
{
public:
  // it's good practice to define a default construction function
  Operator(double lhs = 0, double rhs = 0)
    : numberA(lhs), numberB(rhs){}

  virtual double GetResult() = 0;

protected:
  double numberA;
  double numberB;
};


// "+" 
class OperatorAdd : public Operator
{
public:
  OperatorAdd(double lhs, double rhs)
    : Operator(lhs, rhs) { }

  double GetResult() { return numberA + numberB; }
};

// "-"
class OperatorMinus : public Operator
{
public:
  OperatorMinus(double lhs, double rhs)
    : Operator(lhs, rhs) { }
  
  double GetResult() { return numberA - numberB; }
};

// "*"
class OperatorMul : public Operator
{
public:
  OperatorMul(double lhs, double rhs)
    : Operator(lhs, rhs) { }
  
  double GetResult() { return numberA * numberB; }
};

// "/"
class OperatorDiv : public Operator
{
public:
  OperatorDiv(double lhs, double rhs)
    : Operator(lhs, rhs) { }
  
  double GetResult() { 
    if(numberB == 0)
        throw std::runtime_error("divide zero !!!");
    return numberA / numberB; 
  }
};

// factory function
Operator* createOperator(std::string oper, double lhs, double rhs)
{
  Operator* pOper(NULL); 

  if(oper == "+")
  {
    pOper = new OperatorAdd(lhs, rhs);
  }
  else if(oper == "-")
  {
    pOper = new OperatorMinus(lhs, rhs);
  }
  else if(oper == "*")
  {
    pOper = new OperatorMul(lhs, rhs);
  }
  else if(oper == "/")
  {
    pOper = new OperatorDiv(lhs, rhs);
  }
  else
  {
    std::cerr << "not a valid operator" << std::endl;
	return NULL;
  }

  return pOper;
}

#endif
