// Last Update:2014-07-31 10:28:31
/**
 * @file myecho.c
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-31
 */

#include "csapp.h"

int main(int argc, char *argv[], char *envp[])
{
  int i = 0;
  for(i=0; argv[i] != NULL; ++i) 
    printf("argv[%2d]: %s\n", i, argv[i]);
  printf("\n");

  for(i=0; envp[i] != NULL; ++i) 
    printf("envp[%2d]: %s\n", i, envp[i]);
  exit(0);
}
