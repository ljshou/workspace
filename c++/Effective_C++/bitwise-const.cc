#include <cstring>
#include <iostream>
using namespace std;

class CTextBlock{
public:
  size_t Length() const;
private:
  char *p_text_;
  mutable size_t text_length_;
  mutable bool length_valid_;
};

size_t CTextBlock::Length() const
{
  if(!length_valid_)
  {
    text_length_ = strlen(p_text_);
	length_valid_ = true;
  }
  return text_length_;
}

int main(void)
{
  CTextBlock text_block;
  return 0;
}
