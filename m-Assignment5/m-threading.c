#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//to execute this type of file, use cc -pthread name.c instead of ./name
//compile as normal though

void* sayHi(void* arg){
    printf("hi!\n");
}


void main(){
    pthread_t weave;
    pthread_create(&weave, NULL, &sayHi, NULL);
    printf("prints before thread ends\n");
    pthread_exit(NULL);
}
