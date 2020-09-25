#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main( int argc, char* argv[]){
    if ( argc == 3){
        int fd1 = open( argv[1], O_RDONLY);
        if ( fd1 < 0)	{ perror("open failed"); return -1;}
        int fd2 = open( argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777 );
        if ( fd2 < 0)	{ perror("open failed"); return -1;}
        char buffer[10];
        ssize_t n;
        while( ( n = read( fd1, buffer, sizeof(buffer))) != 0){
            if ( n < 0 ) {
                perror("read failed");
                return -1;
            }
            write( fd2, buffer, n);
        }
        if ( close( fd1) < 0) { perror("close failed") ; return -1;}
        if ( close( fd2) < 0) { perror("close failed") ; return -1;}
        close( fd1);
        close( fd2);
    }
    if ( argc == 4){
        if ( argv[1][0] == '-'){
            if (strstr(argv[1], "f") != NULL){
                if ( strstr(argv[1], "v") != NULL){
                    if ( strstr(argv[1], "i") != NULL ){
                        printf("mycp: переписать '%s' ?", argv[3]);
                        char* resp;
                        scanf("%s",resp);
                        if (resp == "y"){
                            int fd1 = open( argv[1], O_RDONLY);
                            if ( fd1 < 0)	{ perror("open failed"); return -1;}
                            int fd2 = open( argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777 );
                            if ( fd2 < 0)	{ perror("open failed"); return -1;}
                            char buffer[10];
                            ssize_t n;
                            while( ( n = read( fd1, buffer, sizeof(buffer))) != 0){
                                if ( n < 0 ) {
                                    perror("read failed");
                                    return -1;
                                }
                                write( fd2, buffer, n);
                            }
                            if ( close( fd1) < 0) { perror("close failed") ; return -1;}
                            if ( close( fd2) < 0) { perror("close failed") ; return -1;}
                            close( fd1);
                            close( fd2);
                            printf(" '%s' -> '%s'  ", argv[2], argv[3]);//fvi
                        }
                        else return -1;
                    }else{
                        int fd1 = open( argv[1], O_RDONLY);
                        if ( fd1 < 0)	{ perror("open failed"); return -1;}
                        int fd2 = open( argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777 );
                        if ( fd2 < 0)	{ perror("open failed"); return -1;}
                        char buffer[10];
                        ssize_t n;
                        while( ( n = read( fd1, buffer, sizeof(buffer))) != 0){
                            if ( n < 0 ) {
                                perror("read failed");
                                return -1;
                            }
                            write( fd2, buffer, n);
                        }
                        if ( close( fd1) < 0) { perror("close failed") ; return -1;}
                        if ( close( fd2) < 0) { perror("close failed") ; return -1;}
                        close( fd1);
                        close( fd2);
                        printf(" '%s' -> '%s'  ", argv[2], argv[3]);//fv
                    }
                }else{
                    if ( strstr(argv[1], "i") != NULL ){
                        printf("mycp: переписать '%s' ?", argv[3]);
                        char* resp;
                        scanf("%s",resp);
                        if (resp == "y"){
                            int fd1 = open( argv[1], O_RDONLY);
                            if ( fd1 < 0)	{ perror("open failed"); return -1;}
                            int fd2 = open( argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777 );
                            if ( fd2 < 0)	{ perror("open failed"); return -1;}
                            char buffer[10];
                            ssize_t n;
                            while( ( n = read( fd1, buffer, sizeof(buffer))) != 0){
                                if ( n < 0 ) {
                                    perror("read failed");
                                    return -1;
                                }
                                write( fd2, buffer, n);
                            }
                            if ( close( fd1) < 0) { perror("close failed") ; return -1;}
                            if ( close( fd2) < 0) { perror("close failed") ; return -1;}
                            close( fd1);
                            close( fd2);//fi
                        }else return -1;
                    }
                }
            }else{
                if ( strstr(argv[1], "v") != NULL){
                    if ( strstr(argv[1], "i") != NULL ){
                        printf("mycp: переписать '%s' ?", argv[3]);
                        char* resp;
                        scanf("%s",resp);
                        if (resp == "y"){
                            int fd1 = open( argv[1], O_RDONLY);
                            if ( fd1 < 0)	{ perror("open failed"); return -1;}
                            int fd2 = open( argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777 );
                            if ( fd2 < 0)	{ perror("open failed"); return -1;}
                            char buffer[10];
                            ssize_t n;
                            while( ( n = read( fd1, buffer, sizeof(buffer))) != 0){
                                if ( n < 0 ) {
                                    perror("read failed");
                                    return -1;
                                }
                                write( fd2, buffer, n);
                            }
                            if ( close( fd1) < 0) { perror("close failed") ; return -1;}
                            if ( close( fd2) < 0) { perror("close failed") ; return -1;}
                            close( fd1);
                            close( fd2);
                            printf(" '%s' -> '%s'  ", argv[2], argv[3]);//vi
                        }else{
                            if ( strstr(argv[1], "i") != NULL ){
                                printf("mycp: переписать '%s' ?", argv[3]);
                                char* resp;
                                scanf("%s",resp);
                                if (resp == "y"){
                                    int fd1 = open( argv[1], O_RDONLY);
                                    if ( fd1 < 0)	{ perror("open failed"); return -1;}
                                    int fd2 = open( argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777 );
                                    if ( fd2 < 0)	{ perror("open failed"); return -1;}
                                    char buffer[10];
                                    ssize_t n;
                                    while( ( n = read( fd1, buffer, sizeof(buffer))) != 0){
                                        if ( n < 0 ) {
                                            perror("read failed");
                                            return -1;
                                        }
                                        write( fd2, buffer, n);
                                    }
                                    if ( close( fd1) < 0) { perror("close failed") ; return -1;}
                                    if ( close( fd2) < 0) { perror("close failed") ; return -1;}
                                    close( fd1);
                                    close( fd2);
                                    printf(" '%s' -> '%s'  ", argv[2], argv[3]);//v
                                } else {perror("failed on input"); return -1;}
                        }else{
                                if ( strstr(argv[1], "i") != NULL ){
                                    printf("mycp: переписать '%s' ?", argv[3]);
                                    char* resp;
                                    scanf("%s",resp);
                                    if (resp == "y"){
                                        int fd1 = open( argv[1], O_RDONLY);
                                        if ( fd1 < 0)	{ perror("open failed"); return -1;}
                                        int fd2 = open( argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777 );
                                        if ( fd2 < 0)	{ perror("open failed"); return -1;}
                                        char buffer[10];
                                        ssize_t n;
                                        while( ( n = read( fd1, buffer, sizeof(buffer))) != 0){
                                            if ( n < 0 ) {
                                                perror("read failed");
                                                return -1;
                                            }
                                            write( fd2, buffer, n);
                                        }
                                        if ( close( fd1) < 0) { perror("close failed") ; return -1;}
                                        if ( close( fd2) < 0) { perror("close failed") ; return -1;}
                                        close( fd1);
                                        close( fd2);//i
                                    }else return -1;
                                }else return -1;
                            }
                        }
                    }
                }
            }else { perror("read failed"); return -1;}
        }
    return 0;
}
