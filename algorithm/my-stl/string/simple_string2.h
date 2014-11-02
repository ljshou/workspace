// Last Update:2014-05-07 10:40:19
/**
 * @file simple_string2.h
 * @brief 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-07
 */

#ifndef SIMPLE_STRING2_H
#define SIMPLE_STRING2_H

#include <iostream>
#include <cstring>
using namespace std;

class String
{
  friend ostream& operator<<(ostream& out, const String &s){
    out << s.str;
    return out;
  }
public:
  String() :len(0), str(new char[1]) {
    str[0] = '\0';
  }

  String(const char *s) : len(strlen(s)), str(NULL){
    str = new char[len + 1];
    strcpy(str, s);
  }
  
  ~String() {
    delete [] str;
  }

  //copycontrol
  String(const String &rhs): len(rhs.len), str(new char[rhs.len+1])
  {
    strcpy(str, rhs.str);
  }

  String& operator=(String rhs){ //yes, copy by value
    swap(rhs);
    return *this;
  }

  void swap(String &rhs){
    std::swap(str, rhs.str);
    std::swap(len, rhs.len);
  }

  const char* c_str() const {
    return str;
  }

  size_t size() const{
    return len;
  }

  bool operator==(const String &rhs) const{
    return strcmp(str, rhs.str) == 0 ? true : false;
  }

  bool operator<(const String &rhs) const{
    return strcmp(str, rhs.str) < 0 ? true : false;
  }

  char operator[](size_t i) const{
    return str[i];
  }

  char& operator[](size_t i){
    return str[i];
  }

private:
  size_t len;
  char *str;
};


#endif  /*SIMPLE_STRING2_H*/
