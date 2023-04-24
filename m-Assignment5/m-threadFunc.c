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
    void *ret;
    pthread_create(&weave, NULL, &sayHi, NULL);
    printf("prints before thread ends\n");
    pthread_join(weave, ret);

    if(pthread_equal(weave, pthread_self())){
        printf("Same thread!\n");
    }
    else{
        printf("not same thread :(\n");
    }
    pthread_exit(NULL);
}
