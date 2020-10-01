#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
  pid_t child, ppid = getpid();
  int wstatus, i, c = 1;
  printf( "%s%d", "parent pid=", getpid());
  printf("%c", '\n');
  int n = atoi( argv[1]);
  for ( i = 0; i < n; i++){ 
    if ( fork() == 0){
    printf("child pid=%d ppid=%d%c", getpid(), getppid(), '\n'); 
    return 0;
      }else wait(&wstatus);
  }
  return 0;
}  
