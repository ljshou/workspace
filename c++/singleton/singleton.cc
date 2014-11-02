/**
 * @file test.cc
 * @brief 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-04-29
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class  ASingleton 
{ 
public : 
    static  ASingleton *  getInstance() 
    { 
      return   & m_data; 
    } 
    void  do_something() 
    { 
      cout << "ASingleton do_something!" << endl; 
    } 
protected : 
    static  ASingleton m_data;  //static data member 在类中声明，在类外定义 
    ASingleton(); 
    ~ ASingleton() {
      cout << "A destructor called" << endl;
    } 
}; 

class  BSingleton 
{ 
public : 
    static  BSingleton *  getInstance() 
    { 
         return   & m_data; 
    } 
    void  do_something() 
    { 
        cout << "BSingleton do_something!" << endl; 
    } 
protected : 
     static  BSingleton m_data;  //static data member 在类中声明，在类外定义 
    BSingleton(); 
     ~ BSingleton() {
      cout << "B destructor called" << endl;
     } 
}; 

BSingleton BSingleton::m_data; 
ASingleton ASingleton::m_data; 

ASingleton::ASingleton() 
{ 
    cout << "ASingleton constructor!" << endl; 
    BSingleton::getInstance()->do_something(); 
}

BSingleton::BSingleton() 
{ 
    cout << "BSingleton constructor!" << endl; 
}
int main(void)
{
  cout << "entering main: " << endl;
  cout << "leaving main: " << endl;
  return 0;
}

