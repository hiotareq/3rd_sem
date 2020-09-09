#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int ac, char* av[]) {
    int i;
    bool check = false;
    for ( i = 1 ; i < ac; i++){
        while (strcmp("-n", av[i]) == 0) { check = true; i++;}
        printf("%s", av[i]);
        if ( i != ac -1 ) printf("%c", ' ');
    }
    if ( !check == true) printf("%c", '\n');
    return 0;
}
