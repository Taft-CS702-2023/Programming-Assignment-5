#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define NUM_THREADS 5 // Number of threads


void *thread_func(void *arg)
{
  int thread_id = *(int *)arg;
  printf("Thread %d: Hello, World!\n", thread_id);
  pthread_exit(NULL);
}


int main()
{
  pthread_t threads[NUM_THREADS];
  int thread_args[NUM_THREADS];


  for (int i = 0; i < NUM_THREADS; i++)
  {
    thread_args[i] = i + 1;
    int result = pthread_create(&threads[i], NULL, thread_func, 
    &thread_args[i]);
    if (result != 0)
    {
      printf("Failed to create thread: %d\n", result);
      exit(EXIT_FAILURE);
    }
  }
 
  for (int i = 0; i < NUM_THREADS; i++)
  {
    pthread_join(threads[i], NULL);
  }
  printf("All threads have terminated.\n");
  return 0;
}

