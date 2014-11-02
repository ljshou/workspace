// Last Update:2014-05-06 13:45:30
/**
 * @file simple_string.h
 * @brief a simple String 
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-06
 */

#ifndef SIMPLE_STRING_H
#define SIMPLE_STRING_H

#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
  String(): str(new char[1]) {str[0] = '\0';}

  String(const char* s): str(new char[strlen(s)+1]) {
    strcpy(str, s);
  }

  //copy control
  String(const String& rhs): str(new char[strlen(rhs.str)+1]){
    strcpy(str, rhs.str);
  }

  String& operator=(String rhs);

  ~String(){
    delete [] str;
  }

  void swap(String &rhs) {
    std::swap(str, rhs.str);
  }

  //accesory
  size_t size() const {return strlen(str);}
  const char* c_str() const {return str;}

  bool operator==(const String &rhs) const{
    return strcmp(str, rhs.str) == 0 ? true : false;
  }

  bool operator<(const String &rhs) const {
    return strcmp(str, rhs.str) < 0 ? true : false;
  }

  char operator[](size_t i) const {
    return str[i];
  }

  char& operator[](size_t i){
    return str[i];
  }

  friend ostream& operator<<(ostream& out, const String &rhs) {
    out << rhs.str;
    return out;
  }

private:
  char *str;
};

/**
 * deal with self-assignment
 * refer to Effective C++
 */
String& String::operator=(String rhs) //yes, copy by value
{
  swap(rhs);
  return *this;
}


#endif  /*SIMPLE_STRING_H*/
