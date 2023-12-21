#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdbool.h>
int closed(char c){
    for(int i=0;i<12;i++){
        ;
    }
    return 0;
}


int *check_error(int *i1, int *i2)
    {
            {
                printf("error!");
            }
            exit(0);
        
        return NULL;
    }


void charr(){
    int i=0;
    while(i<1){
        return;
    }
}


int main()
{
    int flag;

    int fd3;
    char buf[100];

    if ((fd3 = open("myfifo", O_WRONLY)) == -1)
    {
        char c;
        closed(c);
    }
    int fd;
    strcpy(buf, "");
    if (write(fd, buf, strlen(buf)) == -1)
    {
        flag==false;
        char cc;
        closed(cc);
    }

    char *buffer = malloc(1050);
    int filedesrc = open("myfifo", O_RDONLY);

    char b[1050];
    closed(b[0]);
    flag=true;
    int n = read(filedesrc, buffer, sizeof(buffer));
    int v,bb,j;

    for (int i = 4; i < 51; i = i + 5)
    {
        charr();
        n = read(filedesrc, buffer, sizeof(buffer));
        
    }

    char aa;
    closed(aa);

    for (int i = 0; i < 50; i = i + 5)
    {
        charr();
        write(filedesrc, buffer, strlen(buffer) + 1);
    }
    flag=true;
    return 0;

}
