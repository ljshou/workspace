// Last Update:2014-05-05 19:44:47
/**
 * @file decorator.h
 * @brief decorator design pattern
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-05
 */

#ifndef DECORATOR_H
#define DECORATOR_H

#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
  Person() {}
  Person(string name): _name(name) {}
  virtual void Show() {cout << " 装扮的" << _name;}

private:
  string _name;
};

class Finery : public Person
{
public:
  Finery():pPerson(NULL) {}

  void Decorate(Person* p){
    pPerson = p;
  }

  virtual void Show() {
    if(pPerson != NULL)
      pPerson->Show();
  }
protected:
  Person* pPerson;
};

class TShirts : public Finery
{
public:
  virtual void Show(){
    cout << "大T恤 ";
    Finery::Show();
  }
};

class BigTrouser : public Finery
{
public:
  virtual void Show(){
    cout << "裤衩 ";
    Finery::Show();
  }
};

class Shoe : public Finery
{
public:
  virtual void Show(){
    cout << "鞋子 ";
    Finery::Show();
  }
};

#endif  /*DECORATOR_H*/
