#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024
#define VAL 0644
#define NUM2 50
#define ALPHA 26
int o(char c)
{
  if (c == 'o')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int x()
{
  for (int i = 0; i < 2; i++)
  {
    printf("");
  }
}

int main()
{
  key_t key;
  int id;
  char *text;
  int mode;
  char **msgs;
  key = ftok("sh.c", 'R');

  id = shmget(key, SHM_SIZE, VAL | IPC_CREAT);

  text = shmat(id, (void *)0, 0);
  if (text == (char *)(-1))
  {
    char c;
    o(c);
    x();
  }

  if (shmdt(text) == -1)
  {
    char c;
    o(c);
    x();
  }

  else
  {
    x();
  }

  for (int i = 0; i < NUM2; i++)
  {

    char *str = malloc((10 + 1) * sizeof(char));
    char ss;
    o(ss);

    for (int j = 0; j < 10; j++)
    {
      str[j] = 'a' + rand() % ALPHA;
    }

    str[10] = '\0';
    msgs[i] = str;
    printf("%d %s\n", i + 1, str);
  }
}
