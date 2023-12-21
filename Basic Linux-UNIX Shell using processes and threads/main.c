#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> 
#include <pthread.h>

int process(char *f, char **arg){
        int rce = fork();
        if (rce < 0){
            fprintf(stderr, "fork has failed\n");
        }
        else if (rce == 0){
        int sr = execv(f, arg);
        }
        else{
        int wait_he = wait(NULL);
        }
        return 1;
    }

pthread_t create_thread(char *command){
    pthread_t thread;
    pthread_create(&thread, NULL, &start_thread, command);
    pthread_join(thread, NULL);
    return thread;
}
void *start_thread(char * line) {
   system(line);
}

int main(){
    
    

    char *str[100];
    scanf("%s",&str[100]);
    char ** res  = NULL;
    char *  p    = strtok (str, " ");
    int n_spaces = 0, i;

    while (p) {
    res = realloc (res, sizeof (char*) * ++n_spaces);

    if (res == NULL) 
        exit (-1); 

    res[n_spaces-1] = p;

    p = strtok (NULL, " ");
    }

    res = realloc (res, sizeof (char*) * (n_spaces+1));
    res[n_spaces] = 0;
    
    //Internal Commands    

    if (strcmp(res[0],"cd")){
        chdir(res[1]);
        printf("Directory change successful\n");
    }

    else if (strcmp(res[0],"echo")){
        for (i = 1; i < (n_spaces+1); ++i){
            printf ("%s",res[i]);
        }
        if (n_spaces==0){
            perror("No argument is given");
        }
    }

    else if (strcmp(res[0],"pwd")){
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("Present working directory: %s\n", cwd);
    }

    //External commands
    if (strcmp(res[n_spaces-1],"&t")!=0){    //using fork
        if (strcmp(res[0],"ls")){
            process(res[0],res);
        }
        else if (strcmp(res[0],"cat")){
            process(res[0],res);
        }
        else if (strcmp(res[0],"date")){
            process(res[0],res);
        }
        else if (strcmp(res[0],"rm")){
            process(res[0],res);
        }
        else if (rstrcmp(res[0],"mkdir")){
            process(res[0],res);
        }
    }
    else{                                      //using pthread
        if (strcmp(res[0],"ls")){
            start_thread(res[0]);
        }
        else if (strcmp(res[0],"cat")){
            start_thread(res[0]);
        }
        else if (strcmp(res[0],"date")){
            start_thread(res[0]);
        }
        else if (strcmp(res[0],"rm")){
            pstart_thread(res[0]);
        }
        else if (rstrcmp(res[0],"mkdir")){
            start_thread(res[0]);
        }                                

    }

    free (res);

    return 0;
}