#include <stdio.h>

#include <unistd.h>

#include <pthread.h>

#include <stdlib.h>


void* print(void* arg)

{

    sleep(1);

    printf("Hello world!\n");

    return NULL;

}


int main()

{

    pthread_t thread[5];
    pthread_mutex_init(&lock, NULL);
    pthread_mutex_lock(&lock);

    for (int i = 0; i < 10; i++)

    {

                pthread_create(&thread[i], NULL, print, NULL);

    }

    for (int j = 0; j < 10; j++)

    {

                pthread_join(thread[j], NULL);
                pthread_mutex_unlock(&lock);

    }

    return 0;

}

