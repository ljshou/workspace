// Last Update:2014-07-27 00:04:18
/**
 * @file test.c
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-27
 */

#include "csapp.h"

int main()
{
  int fd1, fd2;
  char c;

  fd1 = Open("foobar.txt", O_RDONLY, 0);
  fd2 = Open("foobar.txt", O_RDONLY, 0);
  Read(fd1, &c, 1);
  Read(fd2, &c, 1);
  printf("c = %c\n", c);
  exit(0);
}
