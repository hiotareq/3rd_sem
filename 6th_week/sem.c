#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>  
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define LADDER_UP 1
#define LADDER_DOWN 0
#define PASS_IN 0
#define CAT_CAP 10
#define CAT_EMPTY 0

int captain(int ladderid, int passinid, int passoutid){
    printf("Captain arrived.\n");

    union semun  {
             int val;
             struct semid_ds *buf;
             ushort *array;
    } arg;
    arg.val = LADDER_DOWN;
    
    int rtrn = semctl(ladderid, 0, SETVAL, arg.val);

    if ( rtrn < 0){
        printf("semctl error in captain\n");
        return errno;
    }
    printf("Ladder is down.\n");

    struct sembuf sops[1];
    sops[0].sem_flg = 0;
    sops[0].sem_num = 0;
    sops[0].sem_op = 0;
    semop(passinid, sops, 1);

    arg.val = LADDER_UP;
    rtrn = semctl(ladderid, 0, SETVAL, arg.val);
    if ( rtrn < 0){
        printf("semctl error in captain\n");
        return errno;
    }
    printf("Ladder is up.\nJourney's begun\n");

    arg.val = CAT_CAP;
    semctl(passinid, 0, SETVAL, arg.val);
    semctl(passoutid, 0, SETVAL, arg.val);

    return 0;
}

void passengerin(int ladderid, int passinid, int passoutid){
    if ( semctl(passinid, 0, GETVAL, 0) == CAT_CAP){
    
        if ( semctl(ladderid, 0, GETVAL, 0) == LADDER_DOWN){
            
            struct sembuf sopsout[1];
            sopsout[0].sem_flg = 0;
            sopsout[0].sem_num = 0;
            sopsout[0].sem_op = 0;
            semop(passoutid, sopsout, 1);
            
            struct sembuf sops[1];
            sops[0].sem_flg = 0;
            sops[0].sem_num = 0;
            sops[0].sem_op = -1;
            while ( semctl(passinid, 0, GETVAL, 0) > 0){
                semop(passinid, sops, 1);
                printf("Пассажир зашёл на борт, теперь пассажиров на борту %d\n", (10-semctl(passinid, 0, GETVAL, 0)));
            }
        }
    }else{
        struct sembuf sops[1];
            sops[0].sem_flg = 0;
            sops[0].sem_num = 0;
            sops[0].sem_op = 0;
            semop(ladderid, sops, 1);
    }
}

void passengerout(int ladderid, int passoutid){
    struct sembuf sops[1];
    sops[0].sem_flg = 0;
    sops[0].sem_num = 0;
    sops[0].sem_op = 0;
    semop(ladderid, sops, 1);//жду, пока опустится трап
    
    struct sembuf sops1[1];
    sops1[0].sem_flg = 0;
    sops1[0].sem_num = 0;
    sops[0].sem_op = -1;
    while ( semctl(passoutid, 0, GETVAL, 0) > 0){
        semop(passoutid, sops, 1);
        printf("Пассажир покинул катер, теперь пассажиров на борту %d\n", semctl(passoutid, 0, GETVAL, 0));
    }
}

int main(int argc, char** argv){
    int cater_size, passengers;
    int ladderid, semctl__;
    union semun  {
             int val;
             struct semid_ds *buf;
             ushort *array;
    } arg;

    ladderid = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL);
    if ( ladderid < 0){perror("Problem with semget"); exit(-1);}

    arg.val = LADDER_UP;
    int rtrn = semctl(ladderid, 0, SETVAL, arg.val);
    if ( rtrn < 0){perror("Problem with semctl"); exit(-1);}

    int passinid = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL);
    if ( passinid < 0){perror("Problem with semget"); exit(-1);}

    arg.val = CAT_CAP;
    rtrn = semctl(passinid, 0, SETVAL, arg.val);
    if ( rtrn < 0){perror("Problem with semctl"); exit(-1);}

    int passoutid = semget(IPC_PRIVATE, 1, IPC_CREAT | IPC_EXCL);
    if ( passoutid < 0){perror("Problem with semget"); exit(-1);}

    arg.val = 0;
    rtrn = semctl(passoutid, 0, SETVAL, arg.val);
    if ( rtrn < 0){perror("Problem with semctl"); exit(-1);}

    int check = 0;

    for ( int i = 0; i < 3; i++){
        if (fork() == 0){
            switch(i){
                case 0:
                    while (check != 3) {
                        captain(ladderid, passinid, passoutid);
                        check++;
                    }
                    return 0;
                    break;
                case 1:
                    while (1) passengerin(ladderid, passinid, passoutid);
                    return 0;
                    break;
                case 2:
                    while (1) passengerout(ladderid, passoutid);
                    return 0;
                    break;
                default: 
                    break;
            }
        }
    }

    return 0;
}