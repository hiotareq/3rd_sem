#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[]){
    struct timespec* StartTime, FinishTIme;
    clock_t ClockToMyNano = clock();
    int wstatus;
    char* ToCat = argv[1];
    char BinaryPath[1000] = "/bin/";
    strcat(BinaryPath, ToCat);
    if (fork() == 0){//do exec stuff
        //do something
        if ( argc == 2){
            int check = execl( BinaryPath, argv[1], NULL);
            if ( check == -1) perror("Problems with calling exec");
        }else{
            argv[argc] = NULL;
            argv = argv + 1;
            int check = execv(BinaryPath, argv);
            if ( check == -1) perror("Problems with calling exec");
        }
    }else{//check time of child process
        wait( &wstatus);
        printf("%f\n", difftime(/*Здесь что-то будет*/));
        return 0;
    }
}