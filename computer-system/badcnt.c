// Last Update:2014-08-01 10:40:41
/**
 * @file badcnt.c
 * @brief 
 * @author L.J.SHOU shoulinjun@126.com
 * @version 0.1.00
 * @date 2014-08-01
 */

#include "csapp.h"

/* Global shared variable */
volatile int cnt = 0; /* counter */
sem_t mutex; /* Semaphore that protects counter */

/* Thread routine */
void *thread(void *vargp)
{
  int i, n = *((int*)vargp);

  for(i=0; i<n; ++i) {
    P(&mutex);
    ++cnt;
    V(&mutex);
  }

  return NULL;
}


int main(int argc, char **argv) 
{
  int n;
  pthread_t tid1, tid2;


  /* Check input argument */
  if (argc != 2) {
    printf("usage: %s <n>\n", argv[0]);
    exit(0);
  }
  n = atoi(argv[1]);

  Sem_init(&mutex, 0, 1); /* mutex = 1 */

  /* Create threads and wait for them to finish */
  Pthread_create(&tid1, NULL, thread, &n);
  Pthread_create(&tid2, NULL, thread, &n);
  Pthread_join(tid1, NULL);
  Pthread_join(tid2, NULL);

  /* Check result */
  if (cnt != (2*n))
    printf("Boom! cnt = %d\n", cnt);
  else 
    printf("OK cnt = %d\n", cnt);

  exit(0);
}
