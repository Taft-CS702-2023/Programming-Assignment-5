#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
  
void* thread_func(void* arg)
{
  pthread_detach(pthread_self()); 
  printf("Inside the thread\n");
  pthread_exit(NULL);
}
 
int main()
{
  pthread_t id;
  pthread_create(&ptid, NULL, &thread_func, NULL);
  printf("This line may be printed before thread terminates\n");


  if(pthread_equal(id, pthread_self()))
  {
    printf("Threads are equal\n");
  }
  else
  {
    printf("Threads are not equal\n");
  }
  pthread_join(id, NULL);
  printf("This line will be printed after thread ends\n");
  pthread_exit(NULL);
  return 0;
}

