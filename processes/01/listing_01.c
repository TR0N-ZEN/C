#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

// TODO if it is a two digit number you migth need to change
//    char i_string[2];
#define COUNT_CHILD 2

int main()
{
  // Create semaphores and initializes each to 0 (locked)
  sem_t *sem_child[COUNT_CHILD];
  char sem_name_prefix[6] = "/sem_";
  for (int i = 0; i < COUNT_CHILD; i++)
  {
    char i_string[2];
    snprintf(i_string, 2, "%d", i);

    char sem_name[7];
    strncat(sem_name, i_string, 2);
    sem_child[i] = sem_open(
        sem_name,
        O_CREAT, 0644, 0);
    if (sem_child[i] == SEM_FAILED) {
      perror("semaphore initialization failed");
      return 1;
    }
  }

  for(int i = 0; i < COUNT_CHILD; i++)
  {
    if(fork() == 0)
    // the following block is only executed by child process
    {
      printf("index %d: [son] pid %d from [parent] pid %d will wait now\n", i, getpid(), getppid());
      sem_wait(sem_child[i]);
      sem_close(sem_child[i]);

      printf("index %d: [son] pid %d from [parent] pid %d will was unlocked\n", i, getpid(), getppid());
      sleep(8);
      // to stop the process from further execution of the enclosing
      // loop it so the process exits/terminates
      exit(0);
    }
  }
  // From here a(n arc) parent process would be able to
  // orchestrate locks of processes I think.
  for(int i = COUNT_CHILD-1; i > -1; i--) {
    sem_post(sem_child[i]);
    sleep(4);
  }
  for(int i = 0; i < COUNT_CHILD; i++) {
    sem_close(sem_child[i]);

    char i_string[2];
    char sem_name[7] = "/sem_";
    snprintf(i_string, 2, "%d", i);
    strncat(sem_name, i_string, 2);
    sem_unlink(sem_name);
  }
  wait(NULL);
}
