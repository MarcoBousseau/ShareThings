#include "fAuthentificationClient.h"
#include <stdio.h>

int authentificationClient(char mdpClient[]){
    char entree[15];
    int i;
    for (i=0; i<15; i++) {
        entree[i] = '_';
    }
    char c;
    i=0;
    while(i<15){
        printf("\t\tAuthentification\n\n\t\tmdp (en entrant à chaque caractère) : %s", entree);
        scanf("%s", &c);
        entree[i] = c;
        i++;
    }
    switch(HashCode(mdpClient) == HashCode(entree)){
        case 1:
            return 1;
        case 0:
            return 0;
        default:
            return 0;
    }
}
