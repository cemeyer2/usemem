#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/signal.h>

char **arr;

void free_n_exit();


int main(int argc, char **argv){
    
    int mbcnt, i;

    if(argc < 2) {
        printf("usage: %s size_in_mb\n", argv[0]);
        exit(1);
    }

    sigset(SIGINT, free_n_exit);

    mbcnt = atoi(argv[1]);

    if(mbcnt <= 0){
        printf("no memory selected\n");
        exit(1);
    }

    printf("using %d mb mem\n", mbcnt);

    arr = (char **)malloc(mbcnt*sizeof(char *));

    for(i = 0; i < mbcnt; i++){
        arr[i] = (char *)malloc(1024*1024);
        memset(arr[i], 0xFF, 1024*1024);
	printf("%d mb mem used...\n",(i+1));
    }
	
    printf("%d mb mem used...\n",mbcnt);	

    while(1) { 
        sleep(60);
    }
}

void free_n_exit(){
    printf("caught SIGINT, cleaning up\n");
    if(arr){
        free(arr);
    }
    exit(0);
}

