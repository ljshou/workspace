/**
 * @file test.cc
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-31
 */

#include "csapp.h" 

int main(void)
{
  Fork();
  Fork();
  Fork();
  printf("hello world\n");
  exit(0);
}
