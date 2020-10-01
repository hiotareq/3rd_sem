#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int i, check = 0;
  printf( "%s%d", "parent pid=", getpid());
  printf("%c", '\n');
  int n = atoi(argv[1]);
  while ( check < n){
    if ( fork() == 0){
        printf("child pid=%d ppid=%d%c", getpid(), getppid(), '\n');
        check++;
    }
    else return 0;
  }
  return 0;
}
