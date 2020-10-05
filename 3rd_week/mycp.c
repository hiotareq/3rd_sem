#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>

int main( int argc, char* argv[]){
    if (argc < 3) {perror("Wrong input"); return -1;}
    if ( argc == 3){
        if (argv[argc - 2] == argv[argc - 1]){//копирование в самого себя, ничего не происходит
            return 0;
        }
        int fd1 = open( argv[argc - 2], O_RDONLY), result;
        if ( fd1 < 0)	{perror("Open of old file failed\n"); return -1;}
        int fd2 = open( argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
        if ( fd2 < 0)	{perror("Open of new file failed\n"); return -1;}
        char buffer[1000];
        ssize_t n;
        while (true){
            n = read( fd1, buffer, sizeof( buffer));
            if ( n < 0){
                perror("Read failed\n");
                return -1;
            }
            if ( n == 0) break;
            write(fd2, buffer, n);
        }
        result = close( fd1);
        if ( result < 0) {perror("Close of the old file failed\n"); return -1;}
        result = close(fd2);
        if ( result < 0) {perror("Close of the new file failed\n"); return -1;}
        return 0;
    }else{//argc>3
        bool flagv = false, flagi = false, flagf = false;
        while( true) {
            struct option longopts[] = {
                    {"interactive", 0, NULL, 0},
                    {"force",       0, NULL, 0},
                    {"verbose",     0, NULL, 0},
                    {0,             0, 0, 0}
            };
            int LongIndex;
            int c = getopt_long(argc, argv, "ivf", longopts, &LongIndex);
            if ( c == -1) {
                break;
            }
            switch(c){//short options
                case 'v':flagv = true;  LongIndex = -1; break;
                case 'i':flagi = true;  LongIndex = -1; break;
                case 'f':flagf = true;  LongIndex = -1; break;
                default: printf("You've entered wrong key!\n"); break;
            }
            if ( LongIndex >= 0){//longoptions
                switch(LongIndex) {
                    case 0:
                        flagi = true;
                        break;
                    case 1:
                        flagf = true;
                        break;
                    case 2:
                        flagv = true;
                        break;
                    default:
                        printf("Something's reaaaly wrong...\n");
                        break;
                }
            }
        }
        if ( flagv == true && flagf == true && flagi == true){//all options are set
        printf("Rewrite old file>?");
        char* resp;
           scanf(resp);
        if ( resp == "y"){
            if (argv[argc - 2] == argv[argc - 1]){//копирование в самого себя, ничего не происходит
                return 0;
            }
            int fd1 = open( argv[argc - 2], O_RDONLY), result;
            if ( fd1 < 0)	{perror("Open of old file failed\n"); rm(argv[argc - 1]);}
            int fd2 = open( argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
            if ( fd2 < 0)	{rm(argv[argc - 1]);}
            open( argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
            char buffer[1000];
            ssize_t n;
            while (true){
                n = read( fd1, buffer, sizeof( buffer));
                if ( n < 0){
                    perror("Read failed\n");
                    return -1;
                }
                if ( n == 0) break;
                write(fd2, buffer, n);
            }
            result = close( fd1);
            if ( result < 0) {perror("Close of the old file failed\n"); return -1;}
            result = close(fd2);
            if ( result < 0) {perror("Close of the new file failed\n"); return -1;}
            printf("%s -> %s", argv[argc - 2], argv[argc - 1]);
            return 0;
            }else return 0;
        }
        if ( flagf == true && flagv == true && flagi == false){
            if (argv[argc - 2] == argv[argc - 1]){//копирование в самого себя, ничего не происходит
                return 0;
            }
            int fd1 = open( argv[argc - 2], O_RDONLY), result;
            if ( fd1 < 0)	{perror("Open of old file failed\n"); rm(argv[argc - 1]);}
            int fd2 = open( argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
            if ( fd2 < 0)	{rm(argv[argc - 1]);}
            open( argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
            char buffer[1000];
            ssize_t n;
            while (true){
                n = read( fd1, buffer, sizeof( buffer));
                if ( n < 0){
                    perror("Read failed\n");
                    return -1;
                }
                if ( n == 0) break;
                write(fd2, buffer, n);
            }
            result = close( fd1);
            if ( result < 0) {perror("Close of the old file failed\n"); return -1;}
            result = close(fd2);
            if ( result < 0) {perror("Close of the new file failed\n"); return -1;}
            printf("%s -> %s", argv[argc - 2], argv[argc - 1]);
            return 0;
        }
        if (flagf == true && flagi == true && flagv == false){
        printf("Rewrite old file>?");
        char* resp;
        scanf(resp);
        if ( resp == "y"){
            if (argv[argc - 2] == argv[argc - 1]){//копирование в самого себя, ничего не происходит
                return 0;
            }
            int fd1 = open( argv[argc - 2], O_RDONLY), result;
            if ( fd1 < 0)	{perror("Open of old file failed\n"); rm(argv[argc - 1]);}
            int fd2 = open( argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
            if ( fd2 < 0)	{rm(argv[argc - 1]);}
            open( argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
            char buffer[1000];
            ssize_t n;
            while (true){
                n = read( fd1, buffer, sizeof( buffer));
                if ( n < 0){
                    perror("Read failed\n");
                    return -1;
                }
                if ( n == 0) break;
                write(fd2, buffer, n);
            }
            result = close( fd1);
            if ( result < 0) {perror("Close of the old file failed\n"); return -1;}
            result = close(fd2);
            if ( result < 0) {perror("Close of the new file failed\n"); return -1;}
            printf("%s -> %s", argv[argc - 2], argv[argc - 1]);
            return 0;
        }
        if ( flagf == true && flagv == false && flagi == false){
            if (argv[argc - 2] == argv[argc - 1]){//копирование в самого себя, ничего не происходит
                return 0;
            }
            int fd1 = open( argv[argc - 2], O_RDONLY), result;
            if ( fd1 < 0)	{perror("Open of old file failed\n"); rm(argv[argc - 1]);}
            int fd2 = open( argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
            if ( fd2 < 0)	{rm(argv[argc - 1]);}
            open( argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
            char buffer[1000];
            ssize_t n;
            while (true){
                n = read( fd1, buffer, sizeof( buffer));
                if ( n < 0){
                    perror("Read failed\n");
                    return -1;
                }
                if ( n == 0) break;
                write(fd2, buffer, n);
            }
            result = close( fd1);
            if ( result < 0) {perror("Close of the old file failed\n"); return -1;}
            result = close(fd2);
            if ( result < 0) {perror("Close of the new file failed\n"); return -1;}
            printf("%s -> %s", argv[argc - 2], argv[argc - 1]);
            return 0;
        }
        if ( flagv == true && flagi == true && flagf == false){
            printf("Rewrite old file>?");
        char* resp;
           scanf(resp);
        if ( resp == "y"){
            if (argv[argc - 2] == argv[argc - 1]){//копирование в самого себя, ничего не происходит
                return 0;
            }
            int fd1 = open( argv[argc - 2], O_RDONLY), result;
            if ( fd1 < 0)	{perror("Open of old file failed\n"); rm(argv[argc - 1]);}
            int fd2 = open( argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
            if ( fd2 < 0)	{perror("Open of new file failed\n");  return(-1);}
            char buffer[1000];
            ssize_t n;
            while (true){
                n = read( fd1, buffer, sizeof( buffer));
                if ( n < 0){
                    perror("Read failed\n");
                    return -1;
                }
                if ( n == 0) break;
                write(fd2, buffer, n);
            }
            result = close( fd1);
            if ( result < 0) {perror("Close of the old file failed\n"); return -1;}
            result = close(fd2);
            if ( result < 0) {perror("Close of the new file failed\n"); return -1;}
            printf("%s -> %s", argv[argc - 2], argv[argc - 1]);
            return 0;
            }else return 0;
        }
        if ( flagv == true && flagi == false){
            if (argv[argc - 2] == argv[argc - 1]){//копирование в самого себя, ничего не происходит
                return 0;
            }
            int fd1 = open( argv[argc - 2], O_RDONLY), result;
            if ( fd1 < 0)	{perror("Open of old file failed\n"); rm(argv[argc - 1]);}
            int fd2 = open( argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
            if ( fd2 < 0)	{perror("Open of new file failed\n");  return(-1);}
            char buffer[1000];
            ssize_t n;
            while (true){
                n = read( fd1, buffer, sizeof( buffer));
                if ( n < 0){
                    perror("Read failed\n");
                    return -1;
                }
                if ( n == 0) break;
                write(fd2, buffer, n);
            }
            result = close( fd1);
            if ( result < 0) {perror("Close of the old file failed\n"); return -1;}
            result = close(fd2);
            if ( result < 0) {perror("Close of the new file failed\n"); return -1;}
            printf("%s -> %s", argv[argc - 2], argv[argc - 1]);
            return 0;
        }
        if ( flagi == true){
            if (argv[argc - 2] == argv[argc - 1]){//копирование в самого себя, ничего не происходит
                return 0;
            }
            int fd1 = open( argv[argc - 2], O_RDONLY), result;
            if ( fd1 < 0)	{perror("Open of old file failed\n"); rm(argv[argc - 1]);}
            int fd2 = open( argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC , 0777);
            if ( fd2 < 0)	{perror("Open of new file failed\n");  return(-1);}
            char buffer[1000];
            ssize_t n;
            while (true){
                n = read( fd1, buffer, sizeof( buffer));
                if ( n < 0){
                    perror("Read failed\n");
                    return -1;
                }
                if ( n == 0) break;
                write(fd2, buffer, n);
            }
            result = close( fd1);
            if ( result < 0) {perror("Close of the old file failed\n"); return -1;}
            result = close(fd2);
            if ( result < 0) {perror("Close of the new file failed\n"); return -1;}
            return 0;
        }else {printf("Something went wrong\n");  return -1;}
    }
    return 0;
}
