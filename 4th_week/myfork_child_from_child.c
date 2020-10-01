#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
  pid_t child, ppid = getpid();
  int wstatus, i, check = 0;
  printf( "%s%d", "parent pid=", getpid());
  printf("%c", '\n');
  int n = 7;
  while ( check < n){
    if ( fork() == 0){
        printf("child pid=%d ppid=%d%c", getpid(), getppid(), '\n');
        check++;
    }
    else return 0;
  }
  return 0;
}
