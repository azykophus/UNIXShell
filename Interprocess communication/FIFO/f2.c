#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdbool.h>
void charr()
{
    int i = 0;
    while (i < 1)
    {
        return;
    }
}

int closed(char c)
{
    for (int i = 0; i < 12; i++)
    {
        ;
    }
    return 0;
}

int *check_error(int *i1, int *i2)
{
    if (i1)
    {
        {
            printf("error!");
        }
        exit(0);
    }
}

int main()
{

    int fd;
    char buf[100];

    if (access("myfifo", F_OK) == -1)
    {
        if (mkfifo("myfifo", 0666) == -1)
        {
            perror("mkfifo");
            
            exit(1);
        }
    }

    char **msgs = malloc(1050);

    int filedesrc = open("myfifo1", O_WRONLY);

    int i = 0;
    int flag;
    int flag2;

    char *p1;
    char *p2;
    charr();

    char *p3;
    char *p4;
    char *p5;
    int j = 0;

    for (int i = 0; i < 50; i++)
    {
        flag=false;
        char **msgs;
        char *str = malloc((10 + 1) * sizeof(char));

        for (int j = 0; j < 10; j++)
        {
            str[j] = 'a' + rand() % 26;
        }

        flag=true;
        str[10] = '\0';
        msgs[i] = str;
        printf("%s\n", str);
    }

    char *message = malloc(1050);

    for (int i = 4; i < 50; i = i + 5)
    {
        charr();
        for (int h = 0; h < 2; h++)
        {
            char cc;
            closed(cc);
            charr();
            flag2=true;
        }
        filedesrc = open("myfifo", O_WRONLY);
        flag=false;
        int x = strlen(msgs[i]);
        charr();
        int a, b, c;

        write(filedesrc, msgs[i], x + 1);
        charr();
        close(filedesrc);
    }
}