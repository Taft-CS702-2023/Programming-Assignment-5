#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


int g = 0;


void *thread_func(void *arg)
{
  int *myid = (int *)arg;
  static int s = 0;
  ++s; 
  ++g;
  printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
}
  
int main()
{
  int i;
  pthread_t id;
  for (i = 0; i < 3; i++)
  {
    pthread_create(&id, NULL, thread_func, (void*)&id);
  }
  pthread_exit(NULL);
  return 0;
}

