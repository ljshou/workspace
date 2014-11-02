// Last Update:2014-05-09 22:07:53
/**
 * @file ref_string.h
 * @brief string class using reference counting
 * @author shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-05-09
 */

#ifndef REF_STRING_H
#define REF_STRING_H

/**
 * simple string class
 * using reference counting
 * COW----copy on write
 */
#include <iostream>
#include <cstring>
using namespace std;

class String
{
  friend ostream& operator<<(ostream &out, const String &str){
    out << str.value->data;
    return out;
  }
public:
  String(const char *str = "\0")
    :value(new StringValue(str)) {}
  String(const String&);
  ~String();
  String& operator=(const String &rhs);

  char& operator[](size_t i);
  char operator[](size_t i) const; 
  size_t size() const {
    return strlen(value->data);
  }
private:
  void destroy() {
    if(--value->ref_count == 0)
      delete value;
  }
  struct StringValue
  {
    StringValue(const char* str)
      :data(new char[strlen(str)+1]), ref_count(1) {
      strcpy(data, str);
    }
    ~StringValue(){
      delete [] data;
    }

    size_t ref_count;
    char *data;
  };
  struct StringValue *value; 
};

String::String(const String& rhs)
{
  ++ rhs.value->ref_count;
  value = rhs.value;
}

String& String::operator=(const String& rhs)
{
  ++ rhs.value->ref_count;
  destroy();
  value = rhs.value;
  return *this;
}

String::~String()
{
  destroy();
}

char& String::operator[](size_t i) 
{
  //copy on write
  if(value->ref_count > 1)
  {
    -- value->ref_count; //do not forget
    value = new StringValue(value->data);
  }
  return value->data[i];
}

char String::operator[](size_t i) const
{
  return value->data[i];
}

#endif  /*REF_STRING_H*/
