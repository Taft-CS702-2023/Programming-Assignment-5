#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//to execute this type of file, use cc -pthread name.c instead of ./name
//compile as normal though

pthread_mutex_t lock;
int thount;

void* sayHi(void* arg){
    thount++;
    pthread_mutex_lock(&lock);
    printf("hi! Count = %d\n", thount);
    pthread_mutex_unlock(&lock);
}

void main(){
    pthread_t weave[10];
    pthread_mutex_init(&lock, NULL);

    for(int i = 0; i < 10; i++){
        pthread_create(&weave[i], NULL, &sayHi, NULL);
    }

    for(int i = 0; i < 10; i++){
        pthread_join(weave[i], NULL);
    }
    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
}
