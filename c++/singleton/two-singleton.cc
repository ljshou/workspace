#include <bits/stdc++.h>
using namespace std;

class  ASingleton 
{ 
public : 
    static  ASingleton *  getInstance() 
    { 
      static  ASingleton instance; 
      return   & instance; 
    } 
    void  do_something() 
    { 
        cout << "ASingleton do_something!" << endl; 
    } 
protected : 
    struct  Object_Creator 
    { 
        Object_Creator() 
        { 
            ASingleton::getInstance(); 
        } 
    }; 
    static  Object_Creator _object_creator; 
    ASingleton(); 
    ~ ASingleton() {} 
}; 

class  BSingleton 
{ 
public : 
    static  BSingleton *  getInstance() 
    { 
         static  BSingleton instance; 
         return   & instance; 
    } 
    void  do_something() 
    { 
        cout << "BSingleton do_something!" << endl; 
    } 
protected : 
    struct  Object_Creator 
    { 
        Object_Creator() 
        { 
            BSingleton::getInstance(); 
        } 
    }; 
    static  Object_Creator _object_creator; 
    BSingleton(); 
    ~ BSingleton() {} 
}; 

BSingleton::Object_Creator BSingleton::_object_creator; 
ASingleton::Object_Creator ASingleton::_object_creator; 

ASingleton::ASingleton() 
{ 
    cout << "ASingleton constructor!" << endl; 
    BSingleton::getInstance()-> do_something(); 
} 

BSingleton::BSingleton() 
{ 
    cout << "BSingleton constructor!" << endl; 
}

int main(void)
{
  cout << "entering main" << endl;
  return 0;
}
