// Last Update:2014-07-27 00:07:27
/**
 * @file test2.c
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-27
 */

#include "csapp.h"

int main()
{
  int fd;
  char c;

  fd = Open("foobar.txt", O_RDONLY, 0);
  if (Fork() == 0) {
    Read(fd, &c, 1);
    exit(0);
  }
  Wait(NULL);
  Read(fd, &c, 1);
  printf("c = %c\n", c);
  exit(0);
}
