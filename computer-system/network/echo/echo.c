// Last Update:2014-07-26 16:24:19
/**
 * @file echo.c
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-07-26
 */

#include "csapp.h"

void echo(int connfd) {
  size_t n;
  char buf[MAXLINE];
  rio_t rio;

  Rio_readinitb(&rio, connfd); 
  while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
    printf("server received %d bytes\n", n);
    printf("%s", buf);
    Fgets(buf, MAXLINE, stdin);
    Rio_writen(connfd, buf, sizeof(buf));
  }
}
