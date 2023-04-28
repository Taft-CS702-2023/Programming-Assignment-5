#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10 // Number of threads
#define COUNT_LIMIT 100 // Maximum count limit

int global_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg)
{
  int thread_id = *(int *)arg;
  int local_count = 0;
  while (1)
  {
    pthread_mutex_lock(&mutex);
    if (global_count >= COUNT_LIMIT)
    {
      pthread_mutex_unlock(&mutex);
      break;
    }
    global_count++;
    local_count++;
    printf("Thread %d: Global Count = %d, Local Count = %d\n", thread_id, global_count, local_count);
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

int main()
{
  pthread_t threads[NUM_THREADS];
  int thread_args[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++)
  {
    thread_args[i] = i + 1;
    int result = pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
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


