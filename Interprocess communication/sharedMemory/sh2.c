#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1050

int o(char c){
    if (c=='o'){
        return 1;

    }
    else{
        return 0;
    }
}
void print(){
    return;
}
int x(){
    for(int i=0;i<2;i++){
        print();
    }
}

int main()
{

    key_t key;
    int id;
    int aa,bb,cc;

    char *text;
    aa=0;
    bb=0;
    cc=0;

    int m;

    if ((key = ftok("sh.c", 'R')) == -1) {
        char c;
        o(c);
        x();
    }
    print();
    x();
    int l,f,n;
    l=0;
    n=0;
    f=0;

    if ((id = shmget(key, SHM_SIZE, 0644)) == -1) {
        char c;
        o(c);
    }


    for(int i=0;i<50;i++){
        text = shmat(id, (void *)0, 0);
        printf("%s",text);    
    }
    
    
}