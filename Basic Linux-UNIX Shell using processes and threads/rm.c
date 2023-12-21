#include <stdio.h>
#include <dirent.h>

int  main(int argc, const char *argv[]){
    if (argc==1){
        struct dirent *d;
        DIR *dir;
        char buf[256];
        dir = opendir("mydir");
        while(d = readdir(dir)){               
            sprintf(buf, "%s/%s", "mydir", d->d_name);
            remove(buf);
        }
    }
    else if (argc==2){
        if (argv[1][1]=="i"){
            printf("Are you sure you want to delete? (Y/N)");
            char *option;
            scanf("%c",&option);
            if (option=="Y"){
                struct dirent *d;
                DIR *dir;
                char buf[256];
                dir = opendir("mydir");
                while(d = readdir(dir)){               
                    sprintf(buf, "%s/%s", "mydir", d->d_name);
                    remove(buf);
                }
            }
            else{
                printf("Aborted");
            }
        }
        else if (argv[1][2]=="f"){
            struct dirent *d;
            DIR *dir;
            char buf[256];
            dir = opendir("mydir");
            while(d = readdir(dir)){               
                sprintf(buf, "%s/%s", "mydir", d->d_name);
                remove(buf);
            }
        }
    }
    return 0;

}