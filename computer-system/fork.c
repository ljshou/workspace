// Last Update:2014-07-31 09:47:20
/**
 * @file fork.c
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-31
 */

#include "csapp.h"

int main(void)
{
  pid_t pid;
  int x = 1;

  pid = Fork();
  if (pid == 0) {
    printf("child: x = %d\n", ++x);
    exit(0);
  }

  /* Parent */
  printf("parent: x = %d\n", --x);
  exit(0);
}

