#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>


/*
 * In here a single process creates several other processes.
 * The processes distinguish among others in their "process identifier" or
 * for short "pid".
 * Processes are created through calling the function `fork()`,
 * so go and read the output of the command `man 2 fork` typed in
 * your shell/terminal/console.
 * Once a process is created from another process, they do not wait for each
 * other without further instructions.
 * "Semaphores" are a method to block and continue a process, so again
 * go ahead reading `man 7 sem_overview`.
 * The command `apropos sem_` typed in your shell should display all names
 * of things you can use with `man`.
 * So if `aporpos sem_` outputs
 *  ┌─────────────────────────────────────────────────────────────┐
 *  │sem_init (3)         - initialize an unnamed semaphore       │
 *  │sem_open (3)         - initialize and open a named semaphore │
 *  │sem_overview (7)     - overview of POSIX semaphores          │
 *  └─────────────────────────────────────────────────────────────┘
 * each of lines in the following box opens the manual page for the named thing
 * that was outputted by `apropos sem_`
 *  ┌───────────────────┐
 *  │man 3 sem_init     │
 *  │man 3 sem_open     │
 *  │man 7 sem_overview │
 */ └───────────────────┘


// TODO if it is a two digit number you migth need to change
//    `char i_string[2];` to `char i_string[3];`
#define COUNT_CHILD 6

int main()
{
  // Create semaphores and initializes each to 0 (locked)
  sem_t * const sem_child[COUNT_CHILD];
  char sem_name_prefix[6] = "/sem_";
  for (int i = 0; i < COUNT_CHILD; i++)
  {
    char i_string[2];
    snprintf(i_string, 2, "%d", i); // e.g. 'i_string' saves '1\0' so the digit one ('1') and the null character ('\0')

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
    if(fork() == 0) // `fork` creates a child proess, for further information read the output of `man 2 fork` in your shell
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
