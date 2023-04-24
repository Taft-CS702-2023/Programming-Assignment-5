#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//to execute this type of file, use cc -pthread name.c instead of ./name
//compile as normal though

int thingy = 0;

void* sayHi(void* arg){
    int *thid = (int*)arg;
    int mabob = 0;
    ++thingy; ++mabob;
    printf("from %d, thingy is %d and mabob is %d\n", *thid, ++thingy, ++mabob);
}


void main(){
    pthread_t weave;

    for(int i = 0; i < 4; i++){
        pthread_create(&weave, NULL, &sayHi, (void *)&weave);
    }
    pthread_exit(NULL);
}
